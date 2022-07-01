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



#include <ATen/ops/mse_loss_backward_ops.h>

namespace at {


// aten::mse_loss_backward.grad_input(Tensor grad_output, Tensor self, Tensor target, int reduction, *, Tensor(a!) grad_input) -> Tensor(a!)
TORCH_API inline at::Tensor & mse_loss_backward_out(at::Tensor & grad_input, const at::Tensor & grad_output, const at::Tensor & self, const at::Tensor & target, int64_t reduction) {
    return at::_ops::mse_loss_backward_grad_input::call(grad_output, self, target, reduction, grad_input);
}

// aten::mse_loss_backward.grad_input(Tensor grad_output, Tensor self, Tensor target, int reduction, *, Tensor(a!) grad_input) -> Tensor(a!)
TORCH_API inline at::Tensor & mse_loss_backward_outf(const at::Tensor & grad_output, const at::Tensor & self, const at::Tensor & target, int64_t reduction, at::Tensor & grad_input) {
    return at::_ops::mse_loss_backward_grad_input::call(grad_output, self, target, reduction, grad_input);
}

// aten::mse_loss_backward(Tensor grad_output, Tensor self, Tensor target, int reduction) -> Tensor
TORCH_API inline at::Tensor mse_loss_backward(const at::Tensor & grad_output, const at::Tensor & self, const at::Tensor & target, int64_t reduction) {
    return at::_ops::mse_loss_backward::call(grad_output, self, target, reduction);
}

}
