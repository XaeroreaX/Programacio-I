#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

float ingresarNumeroF(char mensaje[], float numero)
{
    printf("%s: \n",mensaje);
    scanf("%f", &numero);
    //numero = 1.56;

    return numero;
}

float sumarFloats(float num1, float num2)
{
    float resultado;

    resultado = num1 + num2;


    return resultado;

}

float restarFloats(float num1, float num2)
{
    float resultado;

    resultado = num1 - num2;


    return resultado;


}

float dividirFloats(float num1, float num2)
{
    float resultado;

    resultado = num1 / num2;


    return resultado;


}

