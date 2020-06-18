#include <stdio.h>
#include <omp.h>
#define nth 4
int main (int argc, char* argv [])
{
  long long n = 100000000;
  double h;
  double x, pi, area[nth],areaFin=0.0;
  int i, id;
  h=1.0/(double)n;
  #pragma omp parallel private (x,id) shared(area,areaFin)
   {
     id = omp_get_thread_num();
     area[id]=0.0;
    #pragma omp for
    for (i=0; i<n; i++)
      {

        x=(i+.5)*h;
        area[id] = area[id]+ 4.0/(1.+ x*x);

      }
    }
    for(i=0;i<nth;i++)
    {
        areaFin+=area[i];
    }
  pi = areaFin*h;

  printf("el valor de PI es %15.12f\n",pi);
  return 0;
  }
