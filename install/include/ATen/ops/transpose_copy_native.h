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

TORCH_API at::Tensor & transpose_copy_int_out(const at::Tensor & self, int64_t dim0, int64_t dim1, at::Tensor & out);
TORCH_API at::Tensor transpose_copy_int(const at::Tensor & self, int64_t dim0, int64_t dim1);

} // namespace native
} // namespace at