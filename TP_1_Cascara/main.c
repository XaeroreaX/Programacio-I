#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"



int main()
{
    char seguir='s';
    int opcion=0;
    float num1 = 0, num2 = 0, dividendo;
    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                num1 = ingresarNumeroF("ingrese el 1er operando", num1);
                dividendo = num1;
                //printf("%f", dividendo);
                break;
            case 2:
                num2 = ingresarNumeroF("ingrese el 2do operando", num2);
                break;
            case 3:
                num1 = sumarFloats(num1, num2);
                //printf("el resultado de la suma es %f\n\n", num1);
                break;
            case 4:
                num1 = restarFloats(num1, num2);
                //printf("el resultado de la resta es %f\n\n", num1);
                break;
            case 5:
                while(num2 == 0)
                {
                    num2 = ingresarNumeroF("no puedes dividir 0, ingrese de nuevo", num1);
                }
                num2 = dividirFloats(num1, num2);
               // printf("el resultado de la division es %f\n\n", num1);
                break;
            case 6:
                num1 = multiplicarFloats(num1,num2);
                //printf("el resultado de la multiplicacion es %f\n\n", num1);
                break;
            case 7:
                while(num1 - (int)dividendo != 0 || num1 < 0)
                {
                    num1 = ingresarNumeroF("no puedes hacer factorial de numeros decimales", num1);
                    dividendo = num1;
                }
                num1 = factorial(num1);
                break;
            case 8:
                break;
            case 9:
                seguir = 'n';
                break;
        }
        printf("operando 1 es %f \noperando 2 es %f\n\n", num1, num2);

    }


    return 0;
}



