#include <stdio.h>
#include "funtion.h"

int sumar(char mensaje[],int num1, int num2)
{
    int suma;
    suma = num1 + num2;
    printf("%s: %d", mensaje, suma);
    return suma;
}

int multiplicacion(int num1, int num2)
{
    int resultado;
    resultado = num1 * num2;
    return resultado;
}
