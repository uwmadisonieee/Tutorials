#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long ARRAY_SIZE = 10000000; // 10 Million floats

clock_t t_start, t_end;
double t_time;

int main(int argc, char **argv)
{
  float* a = (float*)malloc(sizeof(float) * ARRAY_SIZE);
  float* b = (float*)malloc(sizeof(float) * ARRAY_SIZE);
  long i;

  ////////////////
  // Normal Run //
  ////////////////
  t_start = clock();

  for (i = 0; i < ARRAY_SIZE; i += sizeof(float)) {
    *(a + i) = 2 * i;
  }

  t_end = clock();
  t_time = (double)(t_end - t_start) / CLOCKS_PER_SEC;
  printf("Normal speed: %f seconds\n", t_time);

  t_start = clock();

  ////////////////
  // OpenMP run //
  ////////////////
  #pragma omp parallel for
  for (i = 0; i < ARRAY_SIZE; i += sizeof(float)) {
    *(b + i) = 2 * i;
  }

  t_end = clock();
  t_time = (double)(t_end - t_start) / CLOCKS_PER_SEC;
  printf("OpenMP speed: %f seconds\n", t_time);

  free(a);
  free(b);

  return 0;
}
