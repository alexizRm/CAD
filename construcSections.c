#include<omp.h>
#include<stdio.h>

int main (){
  int tid;
  #pragma omp parallel private (tid) num_threads(2)
  {
    tid=omp_get_thread_num();

    #pragma omp sections
    {
      #pragma omp section
      {
        printf("\n En esta seccion esta solo el hilo %d",tid);
      }
      #pragma omp section
      {
        printf("\n En esta seccion solo el hilo %d", tid);
      }
      #pragma omp section
      {
        printf("\n\n En esta seccion solo el hilo %d", tid);
      }
    }
  }
  return 0;
}
