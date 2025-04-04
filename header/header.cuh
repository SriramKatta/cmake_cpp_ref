#ifndef HEADER_HPP
#define HEADER_HPP
#pragma once  // Redundant but Safe

#include <iostream>

namespace test {
  template <typename VT>
  __global__ void streamgpu(VT *data, size_t N) {
    const auto gridStart = threadIdx.x + blockDim.x * blockIdx.x;
    const auto gridStride = blockDim.x * gridDim.x;
    for (size_t idx = gridStart; idx < N; idx += gridStride) {
      data[idx] += static_cast<VT>(1.0);
    }
  }

  template <typename VT>
  void streamcpu(VT *data, size_t N) {
#pragma omp parallel for
    for (size_t idx = 0; idx < N; idx++) {
      data[idx] += static_cast<VT>(1.0);
    }
  }

  template <typename VT>
  void setvaluecpu(VT *data, size_t N, const VT &val) {
#pragma omp parallel for
    for (size_t idx = 0; idx < N; idx++) {
      data[idx] = val;
    }
  }

  template <typename VT>
  void printarray(VT *data, size_t N) {
    for (size_t idx = 0; idx < N; idx++) {
      std::cout << data[idx] << " ";
    }
    std::cout << std::endl;
  }

  template <typename VT>
  void printerror(VT *data1, VT *data2, size_t N) {
    VT error = 0.0;
#pragma omp parallel for reduction(+ : error)
    for (size_t idx = 0; idx < N; idx++) {
      error += std::abs(data1[idx] - data2[idx]);
    }
    std::cout << "error is : " << error << std::endl;
  }
}  // namespace test

#endif