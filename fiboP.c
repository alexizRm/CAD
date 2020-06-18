#include <stdio.h>
long fibonacci(int n);
main ()
{
  int nthr=0;
  int n;
  long resul;
  printf("\n Numero a calcular? ");
  scanf("%d", &n);
  #pragma omp parallel
  {
    #pragma omp single
    {           {
    resul = fibonacci(n);
    }
  }
}
  printf ("\nEl numero Fibonacci de %5d es %d", n, resul);
}
  long fibonacci(int n){
    long fn1, fn2, fn;
    if ( n == 0 || n == 1 )
    return(n);
    if ( n < 30 ){
      #pragma omp task shared(fn1)
      {
        fn1 = fibonacci(n-1);
      }
      #pragma omp task shared(fn2)
      {
        fn2 = fibonacci(n-2);
      }
      #pragma omp taskwait
      {
        fn = fn1 + fn2;
      }
      return(fn);
    }
 }
