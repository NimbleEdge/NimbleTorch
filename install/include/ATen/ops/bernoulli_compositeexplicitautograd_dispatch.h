#pragma once
// @generated by torchgen/gen.py from DispatchKeyFunction.h

// NB: The implementing C++ file is RegisterDispatchKey.cpp

// The only #includes we need are for custom classes that have defaults in the C++ API
#include <c10/core/MemoryFormat.h>
#include <c10/core/Scalar.h>
#include <ATen/core/Reduction.h>

// Forward declarations of any types needed in the operator signatures.
// We can't directly include these classes because it will cause circular include dependencies.
// This file is included by TensorBody.h, which defines the Tensor class.
#include <ATen/core/ATen_fwd.h>

namespace at {

namespace compositeexplicitautograd {

TORCH_API at::Tensor bernoulli(const at::Tensor & self, c10::optional<at::Generator> generator=c10::nullopt);
TORCH_API at::Tensor bernoulli_functional(const at::Tensor & self, const at::Tensor & p, c10::optional<at::Generator> generator=c10::nullopt);
TORCH_API at::Tensor & bernoulli_out(at::Tensor & out, const at::Tensor & self, const at::Tensor & p, c10::optional<at::Generator> generator=c10::nullopt);
TORCH_API at::Tensor & bernoulli_outf(const at::Tensor & self, const at::Tensor & p, c10::optional<at::Generator> generator, at::Tensor & out);
TORCH_API at::Tensor & bernoulli_out(at::Tensor & out, const at::Tensor & self, double p=0.5, c10::optional<at::Generator> generator=c10::nullopt);
TORCH_API at::Tensor & bernoulli_outf(const at::Tensor & self, double p, c10::optional<at::Generator> generator, at::Tensor & out);

} // namespace compositeexplicitautograd
} // namespace at
