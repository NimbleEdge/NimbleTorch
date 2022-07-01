#pragma once

#include <cstdint>
#include <memory>
#include <mutex>
#include <type_traits>
#include <utility>

#include <ATen/Context.h>
#include <c10/core/DeviceType.h>
#include <c10/macros/Macros.h>
#include <c10/util/flat_hash_map.h>
#include <c10/util/strong_type.h>
#include <c10/util/variant.h>
#include <torch/csrc/profiler/containers.h>
#include <torch/csrc/profiler/kineto_shim.h>
#include <torch/csrc/profiler/util.h>
#include <torch/csrc/utils/python_stub.h>

namespace torch {
namespace profiler {
namespace impl {

enum class EventType : uint8_t {
  TorchOp = 0,
  Backend,
  Allocation,
  PyCall,
  PyCCall
};

template <EventType>
struct ExtraFields;

struct TorchOpBasicFields {
  int64_t sequence_number_;
  uint64_t forward_tid_;
  at::RecordScope scope_;
  bool is_async_;
  int64_t debug_handle_;
  std::string name_;

  // Set in the exit callback.
  uint64_t end_tid_{0};
};

struct Inputs {
  std::vector<std::vector<int64_t>> shapes_;
  std::vector<std::string> dtypes_;
};

using jit_stack_t = std::vector<std::string>;
using jit_modules_t = std::vector<std::string>;
using extra_args_t = std::unordered_map<std::string, c10::IValue>;

struct FallbackPair {
  CUDAEventStub cuda_event_start_ = nullptr;
  CUDAEventStub cuda_event_end_ = nullptr;
};

template <>
struct ExtraFields<EventType::TorchOp> : TorchOpBasicFields {
  ExtraFields(
      TorchOpBasicFields&& f,
      uint64_t correlation_id,
      time_t end_time_ns,
      Inputs&& inputs,
      jit_stack_t&& jit_stack,
      jit_modules_t&& jit_modules,
      extra_args_t&& extra_args,
      FallbackPair&& gpu_fallback)
      : TorchOpBasicFields(std::move(f)),
        correlation_id_{correlation_id},
        end_time_ns_{end_time_ns},
        inputs_{std::move(inputs)},
        jit_stack_{std::move(jit_stack)},
        jit_modules_{std::move(jit_modules)},
        extra_args_{std::move(extra_args)},
        gpu_fallback_{std::move(gpu_fallback)} {}
  uint64_t correlation_id_;
  time_t end_time_ns_;
  Inputs inputs_;
  jit_stack_t jit_stack_;
  jit_modules_t jit_modules_;
  extra_args_t extra_args_;
  FallbackPair gpu_fallback_;
};

template <>
struct ExtraFields<EventType::Backend> {
  int64_t start_time_us_;
  int64_t end_time_us_;
  int64_t debug_handle_;
  at::RecordScope scope_;
  std::string name_;
  std::string backend_;
  jit_stack_t jit_stack_;
  jit_modules_t jit_modules_;
};

template <>
struct ExtraFields<EventType::Allocation> {
  torch::profiler::impl::approx_time_t start_time_;
  void* ptr_;
  int64_t alloc_size_;
  int64_t total_allocated_;
  int64_t total_reserved_;
  c10::DeviceType device_type_;
  c10::DeviceIndex device_index_;
};

// For performance.
static_assert(
    std::is_pod<ExtraFields<EventType::Allocation>>::value,
    "Non-POD member of ExtraFields<EventType::Allocation>.");

struct PyFrameState {
  int line_no_;
  at::StringView filename_;
  at::StringView funcname_;
};

template <typename T, typename Tag>
using strong_t = strong::
    type<T, Tag, strong::regular, strong::convertible_to<T>, strong::hashable>;

using PyModuleSelf = strong_t<PyObject*, struct PyModuleSelf_>;
using PyModuleCls = strong_t<PyObject*, struct PyModuleCls_>;
using PyCFunction = strong_t<PyObject*, struct PyCFunction_>;

struct NNModuleInfo {
  PyModuleSelf self_;
  PyModuleCls cls_;
  at::StringView cls_name_;

  // Indicates that `self_` is the kth instance of `cls_` observed.
  size_t id_{std::numeric_limits<size_t>::max()};
};

struct PyExtraFieldsBase {
  PyExtraFieldsBase(time_t end_time_ns, size_t python_tid, PyFrameState caller)
      : end_time_ns_{end_time_ns}, python_tid_{python_tid}, caller_{caller} {}

  time_t end_time_ns_;
  size_t python_tid_;
  PyFrameState caller_;

  // kth python event observed. (Used by TensorBoard)
  size_t id_{std::numeric_limits<size_t>::max()};
};

template <>
struct ExtraFields<EventType::PyCall> : public PyExtraFieldsBase {
  using args_t = std::pair<PyFrameState, c10::optional<NNModuleInfo>>;

  ExtraFields(
      time_t end_time_ns,
      size_t python_tid,
      PyFrameState caller,
      args_t args)
      : PyExtraFieldsBase(end_time_ns, python_tid, caller),
        callsite_{args.first},
        module_{args.second} {}

  PyFrameState callsite_;
  c10::optional<NNModuleInfo> module_;
};

template <>
struct ExtraFields<EventType::PyCCall> : public PyExtraFieldsBase {
  using args_t = at::StringView;

  ExtraFields(
      time_t end_time_ns,
      size_t python_tid,
      PyFrameState caller,
      args_t args)
      : PyExtraFieldsBase(end_time_ns, python_tid, caller),
        function_name_{args} {}

  at::StringView function_name_;
};

struct TORCH_API Result : public std::enable_shared_from_this<Result> {
  template <typename... Args>
  [[nodiscard]] static std::shared_ptr<Result> create(Args... args) {
    return std::shared_ptr<Result>(new Result(std::forward<Args>(args)...));
  }

  std::string name() const;
  torch::profiler::impl::kineto::KinetoActivityType kinetoType() const;
  uint64_t correlationID() const;
  int64_t endTimeNS() const;
  uint64_t endTID() const;
  c10::DeviceType deviceType() const;

  int64_t start_time_ns_;
  uint64_t start_tid_;
  kineto::DeviceAndResource kineto_info_;
  c10::variant<
      ExtraFields<EventType::TorchOp>,
      ExtraFields<EventType::Backend>,
      ExtraFields<EventType::Allocation>,
      ExtraFields<EventType::PyCall>,
      ExtraFields<EventType::PyCCall>>
      extra_fields_;

  std::weak_ptr<Result> parent_;
  std::vector<std::shared_ptr<Result>> children_;
  bool finished_{false};

 private:
  template <EventType E>
  Result(
      int64_t start_time_ns,
      uint64_t start_tid,
      kineto::DeviceAndResource kineto_info,
      ExtraFields<E>&& extra_fields)
      : start_time_ns_{start_time_ns},
        start_tid_{start_tid},
        kineto_info_{kineto_info},
        extra_fields_{std::move(extra_fields)} {}
};

struct KinetoObserverContext : public at::ObserverContext {
  struct Event {
    TorchOpBasicFields basic_fields_;
    approx_time_t start_time_;

    // Set in the exit callback.
    approx_time_t end_time_{std::numeric_limits<approx_time_t>::min()};
  };

  explicit KinetoObserverContext(Event* event) : event_{event} {}

  Event* event_;
  FallbackPair* fallback_{nullptr};
};

constexpr int IO_ENCODER_DEFAULT_BLOCK_SIZE = 1024;

// InputOutputEncoder
// Stores each op_events' shapes and dtypes into a contiguous AppendOnlyList
// so that we no longer create vectors for shapes and dtypes on every op.
// Those vectors can be created during post-processing.
class InputOutputEncoder final {
 public:
  void push(c10::ArrayRef<const c10::IValue> values);

  // Used during post-processing to create vectors for shapes and dtype.
  auto getNextShapesAndDtypes();

  void clear();

 private:
  enum class Tag {
    Tensor = 0,
    UndefinedTensor,
    TensorListBegin, // TODO: generalize to other lists.
    Scalar,
    Other,
    TERMINATOR
  };

  struct TensorMetadata {
    void* ptr_;
    c10::ScalarType dtype_;
    uint32_t dim_;
  };

  void push(const at::Tensor& t);

  AppendOnlyList<Tag, IO_ENCODER_DEFAULT_BLOCK_SIZE> tags_;
  AppendOnlyList<TensorMetadata, IO_ENCODER_DEFAULT_BLOCK_SIZE>
      tensor_metadata_;
  AppendOnlyList<int64_t, IO_ENCODER_DEFAULT_BLOCK_SIZE> tensor_sizes_;
};

class RecordQueue;
namespace python_tracer {
/*
Libtorch does not depend on Python (e.g. cannot #include <Python.h>); however
when we call the profiler from libtorch_python we need the profiler to be able
to ingest the data that we collect from the Python tracer. (`PyEval_SetProfile`)

In order to solve this dependency issue we define a virtual base and a function
to register a getter. The python tracer then implements these functions and
exposes itself by calling `registerTracer` from `torch/csrc/autograd/init.cpp`.
This pattern of registration for faux python dependencies in libtorch is common
in the PyTorch codebase.
*/

using TraceKey = strong::type<
    uint64_t,
    struct TraceKey_,
    strong::regular,
    strong::hashable,
    strong::ostreamable>;

struct CompressedEvent {
  TraceKey key_;
  uint64_t system_tid_;
  kineto::DeviceAndResource kineto_info_;
  time_t enter_t_;
};

struct TORCH_API PythonTracerBase {
  static PythonTracerBase& get();
  virtual ~PythonTracerBase() = default;

  virtual void start(RecordQueue* queue) = 0;
  virtual void stop() = 0;
  virtual std::vector<std::shared_ptr<Result>> getEvents(
      std::function<time_t(approx_time_t)> time_converter,
      std::vector<CompressedEvent>& enters) = 0;
  virtual void clear() = 0;
};

using GetFn = PythonTracerBase& (*)();
TORCH_API void registerTracer(GetFn get_tracer);
} // namespace python_tracer

class TORCH_API ThreadLocalSubqueue {
 public:
  ThreadLocalSubqueue(const uint64_t tid, const ProfilerConfig& config);

  std::unique_ptr<KinetoObserverContext> begin_op(const at::RecordFunction& fn);

  template <class... Args>
  void emplace_backend_event(Args&&... args) {
    backend_events_.emplace_back(std::forward<Args>(args)...);
  }

  template <class... Args>
  void emplace_allocation_event(Args&&... args) {
    allocations_.emplace_back(std::forward<Args>(args)...);
  }

  template <class... Args>
  void emplace_py_call(Args&&... args) {
    py_calls_.emplace_back(std::forward<Args>(args)...);
  }

  uint64_t tid() const {
    return tid_;
  }

  const kineto::DeviceAndResource& kineto_info() const {
    return kineto_info_;
  }

 private:
  uint64_t tid_;
  ProfilerConfig config_;
  kineto::DeviceAndResource kineto_info_;

  friend class RecordQueue;
  // See `containers.h` for block size benchmarks.
  static constexpr size_t BlockSize = 512;

  template <typename T, size_t ChunkSize>
  class EventBlock : public std::array<T, ChunkSize> {
   public:
    EventBlock();
    uint64_t correlation_id(const T* ptr) const {
      TORCH_INTERNAL_ASSERT_DEBUG_ONLY(
          ptr >= this->data() && ptr < this->data() + ChunkSize);
      return id_start_ + (ptr - this->data());
    }

   private:
    uint64_t id_start_;
  };

  class OpList : public AppendOnlyList<
                     KinetoObserverContext::Event,
                     BlockSize,
                     EventBlock> {
   public:
    template <class... Args>
    std::pair<KinetoObserverContext::Event*, uint64_t> emplace_back(
        Args&&... args);
    static uint64_t correlationID(const OpList::Iterator& e);
  };

  OpList op_events_;

  // report_input_shapes
  InputOutputEncoder inputs_outputs_;

  // with_stack
  AppendOnlyList<jit_stack_t, BlockSize> jit_stack_;
  AppendOnlyList<std::pair<python_tracer::TraceKey, approx_time_t>, BlockSize>
      py_calls_;

  // with_modules
  AppendOnlyList<jit_modules_t, BlockSize> jit_modules_;

  // with_flops
  AppendOnlyList<extra_args_t, BlockSize> extra_args_;

  // ProfilerState::KINETO_GPU_FALLBACK
  AppendOnlyList<FallbackPair, BlockSize> gpu_fallback_;

  // reportBackendEventToActiveKinetoProfiler
  AppendOnlyList<ExtraFields<EventType::Backend>, BlockSize> backend_events_;

  // reportMemoryUsage
  AppendOnlyList<ExtraFields<EventType::Allocation>, BlockSize> allocations_;
};

class TORCH_API RecordQueue {
 public:
  RecordQueue(const ProfilerConfig& config, std::set<ActivityType> activities);

  bool tracePython() const;
  ThreadLocalSubqueue* getSubqueue();
  void stop();

  // NB: This is a destructive operation.
  std::vector<std::shared_ptr<Result>> getRecords(
      std::function<time_t(approx_time_t)> time_converter);

 private:
  uint32_t id_;
  ProfilerConfig config_;
  std::set<ActivityType> activities_;
  ska::flat_hash_map<uint64_t, std::unique_ptr<ThreadLocalSubqueue>>
      sub_queues_;
  std::mutex sub_queue_mutex_;
};

} // namespace impl
} // namespace profiler
} // namespace torch
