#include <stdio.h>
#include <stdlib.h>
#include "SMatrizGauz.h"
#define OK 0 //validaciones
#define DENIED 1
#define M 3
//validar

int main()
{
    int i, j, val;
    int** numero = NULL;

    numero = (int**) malloc(sizeof(int) * M);

    for(i = 0; i < M; i++)
        numero[i] = (int*) malloc(sizeof(int) * M);

    CargarMatriz(numero, M,M);

    mostrarMatriz(numero, M, M);

    val = inversible(numero);


    return 0;
}
