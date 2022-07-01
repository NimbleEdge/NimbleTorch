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

TORCH_API at::Tensor _resize_output_functional(const at::Tensor & self, at::IntArrayRef size, at::Device device);
TORCH_API const at::Tensor & _resize_output_out(const at::Tensor & self, at::IntArrayRef size, at::Device device, const at::Tensor & out);
TORCH_API const at::Tensor & _resize_output_(const at::Tensor & self, at::IntArrayRef size, at::Device device);

} // namespace native
} // namespace at
