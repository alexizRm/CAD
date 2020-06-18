#include <stdio.h>
#include <omp.h>

int main ()
{
  int tid;
  int a=4;

  #pragma omp parallel private(tid) num_threads(4)
  {
    tid=omp_get_thread_num();
    printf("\nParte 1 Aqui esta trabajando el hilo %d,a=%d\n",tid,a );

    #pragma omp master
    {
      printf("\n Aqui esta trabajando Solo el Hilo %d\n",tid);
      a=a+3;
    }
    printf("\nParte 2 Aqui esta trabajando el Hilo %d, a=%d",tid, a );

  }
  return 0;
}
