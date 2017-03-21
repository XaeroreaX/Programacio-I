#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <ctype.h>

/*1- Cantidad de n�meros pares.
2- Cantidad de n�meros impares.
3- Sumatoria de todos los n�meros impares.
4- Promedio de todos los n�meros.
5- El n�mero mayor ingresado.
6- El n�mero impar menor ingresado.
7- Cu�ntos n�meros est�n entre 3-15, entre 16-29 y 30 o m�s.
8- Dada la sumatoria de todos los n�meros impares (item 3) determinar:
a- La sumatoria de todos los n�meros que le anteceden (incluyendolo). Utilizar FOR.
b- Mostrar todos los n�meros hasta la unidad. Utilizar FOR.*/

int main()
{
    ///Declaramos variables
    int numeros;
    int cont = 0, cantNumPar = 0, cantNQuince = 0, cantNMasTreinta = 0, cantNVeintinueve = 0;//contadores
    int acumNumeros = 0,acumNumerosImpares = 0,sumatoriaAllNImpares = 0;//acumuladores
    int max, minImpar;//maximos y minimos
    float Promedio;
    char validacion;
    bool respuesta1erImpar = false;

    ///ingresamos y procesamos
    do
    {
        if(cont>0)
            printf("\n\n");
        printf("ingrese el numero %d\n",cont+1);
        //printf("%d",cont);
        scanf("%d",&numeros);
        while(numeros < 0) // validacion de numeros positivos
        {
            printf("ingreso malel numero %d, ingrese de nuevo\n",cont+1);
            //printf("%d",cont);
            scanf("%d",&numeros);
        }

        //Calculos de pares e impares

        if(numeros%2 == 0)
        {
            cantNumPar++;
        }
        else
        {
            acumNumerosImpares = acumNumerosImpares + numeros;
            if(respuesta1erImpar == false)
            {
                minImpar = numeros;
                respuesta1erImpar = true;
            }
            else
            {
                if(minImpar > numeros)
                    minImpar = numeros;
            }
        }

        //numero maximo
        if(cont == 0)
            max = numeros;
        else
        {
            if(max < numeros)
            {
                max = numeros;
            }
        }

        //contando numoeros por su valor
        if(numeros >= 3 && numeros <= 15)
            cantNQuince++;
        else
        {
            if(numeros >= 16 && numeros <= 29)
                cantNVeintinueve++;
            else
                cantNMasTreinta++;
        }


        //tomando datos de todas las pasadas
        acumNumeros = acumNumeros + numeros;
        cont++;
        // confirmacion
        printf("\ndesea ingresar otro numero? y/n");
        validacion = tolower(getch());
        while(validacion != 'y' && validacion != 'n')
        {
            printf("\n error! desea ingresar otro numero? y/n");
            validacion = tolower(getch());
        }

    }while(validacion == 'y');
    Promedio = (float)acumNumeros/cont;//promedio

    for(cont = 1; cont <= acumNumerosImpares; cont++)
    {
        sumatoriaAllNImpares = sumatoriaAllNImpares + cont;
        printf("\n%d",cont);//mostramos los numeros de la sumatoria
    }
    ///mostramos todos los parametros por pantalla
    printf("\nla cantidad de numeros pares es: %d",cantNumPar);
    printf("\n\nla sumatoria de numeros impares es: %d",acumNumerosImpares);
    printf("\n\nel promedio de los numeros totales es: %f",Promedio);
    printf("\n\nel numero maximo es: %d",max);
    printf("\n\nel numero impar minimo es: %d",minImpar);
    printf("\n\nlos cantidad de numeros entre 3-15 son %d\n\nla cantidad de numeros entre 16-29 es %d\n\nla cantidad de numeros mayores a 29 son %d",cantNQuince, cantNVeintinueve, cantNMasTreinta);
    printf("\n\nLa sumatoria de todos los numeros que le anteceden al total de los impares es %d",sumatoriaAllNImpares);
    return 0;
}
