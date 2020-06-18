#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char *argv [])
{
    int i,j,k,x1,y1,x2,y2;
    double empezar,terminar;
    printf("Multiplicacion de dos matrices\n");
    printf("Ingresa tamano de Matriz A: \nRenglones: ");
    scanf("%d",&x1);
    printf("Columnas: ");
    scanf("%d",&y1);
    printf("Ingresa tamano de Matriz B: \nRenglones: ");
    scanf("%d",&x2);
    printf("Columnas: ");
    scanf("%d",&y2);
    if(y1!=x2) {	//Verificacion para poder realizar la multiplicacion de matrices
        printf("El num de columnas de A debe ser igual al num de renglones de B");
        exit(0);
    }
    empezar= omp_get_wtime();
    //Asignacion de memoria para la primer matriz A
    float **a= (float **)malloc(sizeof(float*)*x1);
    for(i=0; i<x1; i++) {
        a[i] = (float *)malloc(sizeof(float)*y1);
    }
    //Asignacion de memoria para la segunda matriz B
    float **b= (float **)malloc(sizeof(float*)*x2);
    for(i=0; i<x2; i++) {
        b[i] = (float *)malloc(sizeof(float)*y2);
    }
    //Asignacion de memoria para la matriz resultante C
    float **c= (float **)malloc(sizeof(float*)*x1);
    for(i=0; i<x1; i++) {
        c[i] = (float *)malloc(sizeof(float)*y2);
    }
    //printf("Valores Matriz A \n");
    //Asignacion de valores de A
    for(i=0; i<x1; i++) {
        for(j=0; j<y1; j++) {
            //printf("A[%d][%d]= ",i,j);
            //scanf("%f",&a[i][j]);
	    a[i][j]=1;
        }
    }
    //Asignacion de valores de B
    //printf("Valores Matriz B \n");
    for(i=0; i<x2; i++) {
        for(j=0; j<y2; j++) {
            //printf("B[%d][%d]= ",i,j);
            //scanf("%f",&b[i][j]);
	    b[i][j]=1;
        }
    }
    //Inicializacion de C a cero
    for(i=0; i<x1; i++) {
        for(j=0; j<y2; j++) {
            c[i][j]= 0;
        }
    }
    #pragma omp parallel for private(j,k)
    for(i=0; i<x1; i++) {	//Ciclo que mueve los renglones de A
        for(j=0; j<y2; j++) {	//Ciclo que mueve las columnas de B
            for(k=0; k<x2; k++) {	//Ciclo que recorre A y B para el producto de sus componentes
                c[i][j]= c[i][j]+(a[i][k]*b[k][j]);
            }
        }
    }
    /*printf("Matriz resultante C \n");
    for(i=0; i<x1; i++) {	//Despliegue de matriz resultante C
        for(j=0; j<y2; j++) {
            printf("%8.3f  ",c[i][j]);
        }
        printf("\n");
    }*/
    terminar= omp_get_wtime();
    printf("\nTIEMPO=%1f\n",terminar-empezar);
    return 0;
}
