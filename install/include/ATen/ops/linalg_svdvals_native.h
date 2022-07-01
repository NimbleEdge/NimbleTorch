#pragma once

// @generated by torchgen/gen.py from NativeFunction.h

#include <c10/core/Scalar.h>
#include <c10/core/Storage.h>
#include <c10/core/TensorOptions.h>
#include <c10/util/Deprecated.h>
#include <c10/util/Optional.h>
#include <c10/core/QScheme.h>
#include <ATen/core/Reduction.h>
#include <ATen/core/Tensor.h>
#include <tuple>
#include <vector>


namespace at {
namespace native {

TORCH_API at::Tensor linalg_svdvals(const at::Tensor & A, c10::optional<c10::string_view> driver=c10::nullopt);
TORCH_API at::Tensor & linalg_svdvals_out(const at::Tensor & A, c10::optional<c10::string_view> driver, at::Tensor & out);

} // namespace native
} // namespace at