#include <float.h>
#include <omp.h>
#include <stdio.h>

#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
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
  thrust::host_vector<VT> h_vec(N, 0.0);
  thrust::device_vector<VT> d_vec(N, 0.0);
  thrust::host_vector<VT> h_vec_res(N, 0.0);

  test::streamgpu<<<40, 256>>>(thrust::raw_pointer_cast(d_vec.data()),
                               d_vec.size());
  test::streamcpu(h_vec.data(), h_vec.size());
  h_vec_res = d_vec;

  test::printerror(h_vec.data(), h_vec_res.data(), h_vec.size());

  return 0;
}
