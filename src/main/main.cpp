#include <float.h>
#include <stdio.h>
#include <cub/cub.cuh>

#include <cuda_runtime.h>

#define reps 200

int main() {
#if _OPENMP
  printf("omp used\n");
#endif

#if __clang__
  printf("clang is used\n");
#endif

  return 0;
}
