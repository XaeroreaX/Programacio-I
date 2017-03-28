/*De los empleados de una fábrica (no se sabe cuántos) se registra la siguiente información:
 Numero de legajo (entero, solo 4 cifras). Validar con una función.
 Sueldo neto (decimal, entre 1500 y 10000). Validar con una función.
 Sexo (carácter, ´f´ o ´m´). Validar con una función.
 Edad (entero, entre 18 y 65). Validar con una función.
Se pide realizar un programa que permita cargar los datos mencionados anteriormente y mostrar por pantalla la
siguiente información:
1. Cantidad de empleados (masculinos) que ganan entre 2000 y 7500 .
2. Cantidad de empleados (femeninos) cuya edad sea mayor a 38 años.
3. Porcentaje de empleados masculinos y femeninos (Realizar en una función)
4. Total de dinero que deberá pagar la fábrica en concepto de sueldos para todos sus empleados.
5. Empleado masculino con mayor sueldo (mostrar legajo)
6. Empleado femenino con mayor edad (mostrar legajo y sueldo)*/
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    int legajo;
    float sueldo;
    legajo = ingreseNumero("ingrese el Legajo(mas de 1000)", legajo, 1000);
    sueldo = ingreseNumeroF("ingrese un sueldo entre 1500 y 10000", 1500, 10000);

    printf("%f",sueldo);
    return 0;
}


