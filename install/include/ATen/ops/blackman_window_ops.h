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


struct TORCH_API blackman_window {
  using schema = at::Tensor (int64_t, c10::optional<at::ScalarType>, c10::optional<at::Layout>, c10::optional<at::Device>, c10::optional<bool>);
  using ptr_schema = schema*;
  // See Note [static constexpr char* members for windows NVCC]
  STATIC_CONSTEXPR_STR_INL_EXCEPT_WIN_CUDA(name, "aten::blackman_window")
  STATIC_CONSTEXPR_STR_INL_EXCEPT_WIN_CUDA(overload_name, "")
  STATIC_CONSTEXPR_STR_INL_EXCEPT_WIN_CUDA(schema_str, "blackman_window(int window_length, *, ScalarType? dtype=None, Layout? layout=None, Device? device=None, bool? pin_memory=None) -> Tensor")
  static at::Tensor call(int64_t window_length, c10::optional<at::ScalarType> dtype, c10::optional<at::Layout> layout, c10::optional<at::Device> device, c10::optional<bool> pin_memory);
  static at::Tensor redispatch(c10::DispatchKeySet dispatchKeySet, int64_t window_length, c10::optional<at::ScalarType> dtype, c10::optional<at::Layout> layout, c10::optional<at::Device> device, c10::optional<bool> pin_memory);
};

struct TORCH_API blackman_window_periodic {
  using schema = at::Tensor (int64_t, bool, c10::optional<at::ScalarType>, c10::optional<at::Layout>, c10::optional<at::Device>, c10::optional<bool>);
  using ptr_schema = schema*;
  // See Note [static constexpr char* members for windows NVCC]
  STATIC_CONSTEXPR_STR_INL_EXCEPT_WIN_CUDA(name, "aten::blackman_window")
  STATIC_CONSTEXPR_STR_INL_EXCEPT_WIN_CUDA(overload_name, "periodic")
  STATIC_CONSTEXPR_STR_INL_EXCEPT_WIN_CUDA(schema_str, "blackman_window.periodic(int window_length, bool periodic, *, ScalarType? dtype=None, Layout? layout=None, Device? device=None, bool? pin_memory=None) -> Tensor")
  static at::Tensor call(int64_t window_length, bool periodic, c10::optional<at::ScalarType> dtype, c10::optional<at::Layout> layout, c10::optional<at::Device> device, c10::optional<bool> pin_memory);
  static at::Tensor redispatch(c10::DispatchKeySet dispatchKeySet, int64_t window_length, bool periodic, c10::optional<at::ScalarType> dtype, c10::optional<at::Layout> layout, c10::optional<at::Device> device, c10::optional<bool> pin_memory);
};

}} // namespace at::_ops