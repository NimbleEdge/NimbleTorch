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

TORCH_API at::Tensor normal_functional(const at::Tensor & self, double mean=0, double std=1, c10::optional<at::Generator> generator=c10::nullopt);
TORCH_API at::Tensor & normal_out(const at::Tensor & self, double mean, double std, c10::optional<at::Generator> generator, at::Tensor & out);
TORCH_API at::Tensor & normal_(at::Tensor & self, double mean=0, double std=1, c10::optional<at::Generator> generator=c10::nullopt);
TORCH_API at::Tensor & normal_sparse_csr_(at::Tensor & self, double mean=0, double std=1, c10::optional<at::Generator> generator=c10::nullopt);
TORCH_API at::Tensor & normal_meta_(at::Tensor & self, double mean=0, double std=1, c10::optional<at::Generator> generator=c10::nullopt);
TORCH_API at::Tensor normal(const at::Tensor & mean, double std=1, c10::optional<at::Generator> generator=c10::nullopt);
TORCH_API at::Tensor & normal_out(const at::Tensor & mean, double std, c10::optional<at::Generator> generator, at::Tensor & out);
TORCH_API at::Tensor normal_meta(const at::Tensor & mean, double std=1, c10::optional<at::Generator> generator=c10::nullopt);
TORCH_API at::Tensor & normal_out_meta(const at::Tensor & mean, double std, c10::optional<at::Generator> generator, at::Tensor & out);
TORCH_API at::Tensor normal(double mean, const at::Tensor & std, c10::optional<at::Generator> generator=c10::nullopt);
TORCH_API at::Tensor & normal_out(double mean, const at::Tensor & std, c10::optional<at::Generator> generator, at::Tensor & out);
TORCH_API at::Tensor normal_meta(double mean, const at::Tensor & std, c10::optional<at::Generator> generator=c10::nullopt);
TORCH_API at::Tensor & normal_out_meta(double mean, const at::Tensor & std, c10::optional<at::Generator> generator, at::Tensor & out);
TORCH_API at::Tensor normal(const at::Tensor & mean, const at::Tensor & std, c10::optional<at::Generator> generator=c10::nullopt);
TORCH_API at::Tensor & normal_out(const at::Tensor & mean, const at::Tensor & std, c10::optional<at::Generator> generator, at::Tensor & out);
TORCH_API at::Tensor normal_meta(const at::Tensor & mean, const at::Tensor & std, c10::optional<at::Generator> generator=c10::nullopt);
TORCH_API at::Tensor & normal_out_meta(const at::Tensor & mean, const at::Tensor & std, c10::optional<at::Generator> generator, at::Tensor & out);
TORCH_API at::Tensor normal(double mean, double std, at::IntArrayRef size, c10::optional<at::Generator> generator=c10::nullopt, c10::optional<at::ScalarType> dtype={}, c10::optional<at::Layout> layout={}, c10::optional<at::Device> device={}, c10::optional<bool> pin_memory={});
TORCH_API at::Tensor & normal_out(double mean, double std, at::IntArrayRef size, c10::optional<at::Generator> generator, at::Tensor & out);

} // namespace native
} // namespace at
