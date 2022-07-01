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



#include <ATen/ops/cross_entropy_loss_ops.h>

namespace at {


// aten::cross_entropy_loss(Tensor self, Tensor target, Tensor? weight=None, int reduction=Mean, int ignore_index=-100, float label_smoothing=0.0) -> Tensor
TORCH_API inline at::Tensor cross_entropy_loss(const at::Tensor & self, const at::Tensor & target, const c10::optional<at::Tensor> & weight={}, int64_t reduction=at::Reduction::Mean, int64_t ignore_index=-100, double label_smoothing=0.0) {
    return at::_ops::cross_entropy_loss::call(self, target, weight, reduction, ignore_index, label_smoothing);
}

}