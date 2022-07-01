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

TORCH_API at::Tensor cauchy_functional(const at::Tensor & self, double median=0, double sigma=1, c10::optional<at::Generator> generator=c10::nullopt);
TORCH_API at::Tensor & cauchy_out(const at::Tensor & self, double median, double sigma, c10::optional<at::Generator> generator, at::Tensor & out);
TORCH_API at::Tensor & cauchy_(at::Tensor & self, double median=0, double sigma=1, c10::optional<at::Generator> generator=c10::nullopt);

} // namespace native
} // namespace at
