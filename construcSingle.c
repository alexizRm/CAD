#include <stdio.h>
#include <omp.h>

int main()
{
  int tid;
  int a=4;

  #pragma omp parallel private (tid) num_threads(4)
  {
    tid=omp_get_thread_num();

    printf("\n Parte 1 aqui esta trabajando el hilo %d, a=%d",tid,a);

    #pragma omp single
    {
      printf("\n Aqui esta trabajando SOLO el hilo %d\n",tid );
      a=a+3;
    }
    printf("\n Parte 2 aqui esta tranbajando en hilo %d, a =%d\n",tid,a);

  }
  return 0;
}
