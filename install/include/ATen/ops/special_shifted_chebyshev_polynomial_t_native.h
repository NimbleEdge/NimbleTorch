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
#include <ATen/ops/special_shifted_chebyshev_polynomial_t_meta.h>

namespace at {
namespace native {

struct TORCH_API structured_special_shifted_chebyshev_polynomial_t_out : public at::meta::structured_special_shifted_chebyshev_polynomial_t {
void impl(const at::Tensor & x, const at::Tensor & n, const at::Tensor & out);
};
TORCH_API at::Tensor special_shifted_chebyshev_polynomial_t(const at::Scalar & x, const at::Tensor & n);
TORCH_API at::Tensor & special_shifted_chebyshev_polynomial_t_out(const at::Scalar & x, const at::Tensor & n, at::Tensor & out);
TORCH_API at::Tensor special_shifted_chebyshev_polynomial_t(const at::Tensor & x, const at::Scalar & n);
TORCH_API at::Tensor & special_shifted_chebyshev_polynomial_t_out(const at::Tensor & x, const at::Scalar & n, at::Tensor & out);

} // namespace native
} // namespace at
