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


struct TORCH_API _test_ambiguous_defaults_a {
  using schema = at::Tensor (const at::Tensor &, int64_t, int64_t);
  using ptr_schema = schema*;
  // See Note [static constexpr char* members for windows NVCC]
  STATIC_CONSTEXPR_STR_INL_EXCEPT_WIN_CUDA(name, "aten::_test_ambiguous_defaults")
  STATIC_CONSTEXPR_STR_INL_EXCEPT_WIN_CUDA(overload_name, "a")
  STATIC_CONSTEXPR_STR_INL_EXCEPT_WIN_CUDA(schema_str, "_test_ambiguous_defaults.a(Tensor dummy, int a=1, int b=1) -> Tensor")
  static at::Tensor call(const at::Tensor & dummy, int64_t a, int64_t b);
  static at::Tensor redispatch(c10::DispatchKeySet dispatchKeySet, const at::Tensor & dummy, int64_t a, int64_t b);
};

struct TORCH_API _test_ambiguous_defaults_b {
  using schema = at::Tensor (const at::Tensor &, int64_t, c10::string_view);
  using ptr_schema = schema*;
  // See Note [static constexpr char* members for windows NVCC]
  STATIC_CONSTEXPR_STR_INL_EXCEPT_WIN_CUDA(name, "aten::_test_ambiguous_defaults")
  STATIC_CONSTEXPR_STR_INL_EXCEPT_WIN_CUDA(overload_name, "b")
  STATIC_CONSTEXPR_STR_INL_EXCEPT_WIN_CUDA(schema_str, "_test_ambiguous_defaults.b(Tensor dummy, int a=2, str b=\"2\") -> Tensor")
  static at::Tensor call(const at::Tensor & dummy, int64_t a, c10::string_view b);
  static at::Tensor redispatch(c10::DispatchKeySet dispatchKeySet, const at::Tensor & dummy, int64_t a, c10::string_view b);
};

}} // namespace at::_ops
