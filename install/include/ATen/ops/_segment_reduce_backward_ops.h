#pragma once

// @generated by torchgen/gen.py from Operator.h

#include <tuple>
#include <vector>

// Forward declarations of any types needed in the operator signatures.
// We can't directly include these classes because it will cause circular include dependencies.
// This file is included by TensorBody.h, which defines the Tensor class.
#include <ATen/core/ATen_fwd.h>

namespace at {
namespace _ops {


struct TORCH_API _segment_reduce_backward {
  using schema = at::Tensor (const at::Tensor &, const at::Tensor &, const at::Tensor &, c10::string_view, const c10::optional<at::Tensor> &, const c10::optional<at::Tensor> &, int64_t, const c10::optional<at::Scalar> &);
  using ptr_schema = schema*;
  // See Note [static constexpr char* members for windows NVCC]
  STATIC_CONSTEXPR_STR_INL_EXCEPT_WIN_CUDA(name, "aten::_segment_reduce_backward")
  STATIC_CONSTEXPR_STR_INL_EXCEPT_WIN_CUDA(overload_name, "")
  STATIC_CONSTEXPR_STR_INL_EXCEPT_WIN_CUDA(schema_str, "_segment_reduce_backward(Tensor grad, Tensor output, Tensor data, str reduce, *, Tensor? lengths=None, Tensor? offsets=None, int axis=0, Scalar? initial=None) -> Tensor")
  static at::Tensor call(const at::Tensor & grad, const at::Tensor & output, const at::Tensor & data, c10::string_view reduce, const c10::optional<at::Tensor> & lengths, const c10::optional<at::Tensor> & offsets, int64_t axis, const c10::optional<at::Scalar> & initial);
  static at::Tensor redispatch(c10::DispatchKeySet dispatchKeySet, const at::Tensor & grad, const at::Tensor & output, const at::Tensor & data, c10::string_view reduce, const c10::optional<at::Tensor> & lengths, const c10::optional<at::Tensor> & offsets, int64_t axis, const c10::optional<at::Scalar> & initial);
};

}} // namespace at::_ops
