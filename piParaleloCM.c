#include <stdio.h>
int main (int argc, char* argv [])
{
  long long n = 100000000;
  double h;
  double x, pi, area=0.0,tmp;
  int i, nth=0;
  h=1.0/(double)n;
  #pragma omp parallel private (x,tmp)
   {
    #pragma omp for
    for (i=0; i<n; i++)
      {

        x=(i+.5)*h;
        #pragma omp critical
        area = area+ 4.0/(1.+ x*x)+tmp;

      }
    }
  pi = area*h;

  printf("el valor de PI es %15.12f\n",pi);
  return 0;
  }
