#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
int ingreseNumero(char Mensaje[], int numero, int min)
{
    printf("%s: ",Mensaje);
    scanf("%d", &numero);
    numero = validarMinimo(numero, min);
    return numero;
}

int validarMinimo(int numero, int min)
{
    while(numero < min)
    {
        printf("ingreso mal el numero, ingrese numero mayores a %d: ", min);
        scanf("%d", &numero);
    }
    return numero;
}

float ingreseNumeroF(char mensaje[], int min, int max)
{
    float numero;
    printf("%s: ", mensaje);
    scanf("%f",&numero);
    numero = ValidarMinMax(numero, min, max);
    return numero;
}

 float ValidarMinMax(float numero, int min, int max)
 {
     while(numero > max || numero < min)
     {
         printf("ingreso mal el numero, por favor ingrese del %d hasta %d: ",min, max);
         scanf("%f", &numero);
     }
     return numero;
 }
