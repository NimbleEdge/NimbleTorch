#pragma once

// @generated by torchgen/gen.py from Function.h

#include <ATen/Context.h>
#include <ATen/DeviceGuard.h>
#include <ATen/TensorUtils.h>
#include <ATen/TracerMode.h>
#include <ATen/core/Generator.h>
#include <ATen/core/Reduction.h>
#include <ATen/core/Tensor.h>
#include <c10/core/Scalar.h>
#include <c10/core/Storage.h>
#include <c10/core/TensorOptions.h>
#include <c10/util/Deprecated.h>
#include <c10/util/Optional.h>



#include <ATen/ops/expand_copy_ops.h>

namespace at {


// aten::expand_copy(Tensor self, int[] size, *, bool implicit=False) -> Tensor
TORCH_API inline at::Tensor expand_copy(const at::Tensor & self, at::IntArrayRef size, bool implicit=false) {
    return at::_ops::expand_copy::call(self, size, implicit);
}

// aten::expand_copy.SymInt(Tensor self, SymInt[] size, *, bool implicit=False) -> Tensor
TORCH_API inline at::Tensor expand_copy_symint(const at::Tensor & self, c10::SymIntArrayRef size, bool implicit=false) {
    return at::_ops::expand_copy_SymInt::call(self, size, implicit);
}

// aten::expand_copy.SymInt_out(Tensor self, SymInt[] size, *, bool implicit=False, Tensor(a!) out) -> Tensor(a!)
TORCH_API inline at::Tensor & expand_copy_symint_out(at::Tensor & out, const at::Tensor & self, c10::SymIntArrayRef size, bool implicit=false) {
    return at::_ops::expand_copy_SymInt_out::call(self, size, implicit, out);
}

// aten::expand_copy.SymInt_out(Tensor self, SymInt[] size, *, bool implicit=False, Tensor(a!) out) -> Tensor(a!)
TORCH_API inline at::Tensor & expand_copy_symint_outf(const at::Tensor & self, c10::SymIntArrayRef size, bool implicit, at::Tensor & out) {
    return at::_ops::expand_copy_SymInt_out::call(self, size, implicit, out);
}

// aten::expand_copy.out(Tensor self, int[] size, *, bool implicit=False, Tensor(a!) out) -> Tensor(a!)
TORCH_API inline at::Tensor & expand_copy_out(at::Tensor & out, const at::Tensor & self, at::IntArrayRef size, bool implicit=false) {
    return at::_ops::expand_copy_out::call(self, size, implicit, out);
}

// aten::expand_copy.out(Tensor self, int[] size, *, bool implicit=False, Tensor(a!) out) -> Tensor(a!)
TORCH_API inline at::Tensor & expand_copy_outf(const at::Tensor & self, at::IntArrayRef size, bool implicit, at::Tensor & out) {
    return at::_ops::expand_copy_out::call(self, size, implicit, out);
}

}
