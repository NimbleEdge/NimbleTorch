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



#include <ATen/ops/adaptive_avg_pool1d_ops.h>

namespace at {


// aten::adaptive_avg_pool1d(Tensor self, int[1] output_size) -> Tensor
TORCH_API inline at::Tensor adaptive_avg_pool1d(const at::Tensor & self, at::IntArrayRef output_size) {
    return at::_ops::adaptive_avg_pool1d::call(self, output_size);
}

}