#include <stdio.h>
int main (int argc, char* argv [])
{
  long long n = 1;
  double h;
  double x, pi, area=0.0;
  int i, nth=0;
  h=1.0/(double)n;
  #pragma omp parallel private (x)
   {
    #pragma omp for
    for (i=0; i<n; i++)
      {

        x=(i+.5)*h;
        area = area + 4.0/(1.+ x*x);

      }
    }
  pi = area*h;

  printf("el valor de PI es %15.12f\n",pi);
  return 0;
  }
