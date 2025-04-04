#include <float.h>
#include <omp.h>
#include <stdio.h>
#include <cub/cub.cuh>

#include "test_header.cuh"

using VT = double;

void dummy_omp_pin() {
  int nth = 1;
#if _OPENMP
#pragma omp parallel
#pragma omp single
  nth = omp_get_num_threads();
  std::cout << "openmp Used" << std::endl;
#else
  std::cout << "openmp not used" << std::endl;
#endif
  std::cout << "num threads : " << nth << std::endl;
}

int main() {
  dummy_omp_pin();
  size_t N = 1 << 28;
  VT *h_arr;
  VT *h_arr_res;
  VT *d_arr;
  size_t sizeinbytes = N * sizeof(VT);
  cudaMallocHost(&h_arr, sizeinbytes);
  cudaMallocHost(&h_arr_res, sizeinbytes);
  cudaMalloc(&d_arr, sizeinbytes);
  test::setvaluecpu(h_arr, N, 0.0);
  test::streamgpu<<<40, 256>>>(d_arr, N);
  test::streamcpu(h_arr, N);
  cudaMemcpy(h_arr_res, d_arr, sizeinbytes, cudaMemcpyDeviceToHost);

  test::printerror(h_arr, h_arr_res, N);
  cudaFreeHost(h_arr);
  cudaFreeHost(h_arr_res);
  cudaFree(d_arr);
  return 0;
}
