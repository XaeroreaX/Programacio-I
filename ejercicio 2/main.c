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
int ingreseNumero(char Mensaje[], int, int);
/** \brief ingresa un numero con un mensaje y lo valida con un numero minimo
 *
 * \param mensaje que quiera mostrar
 * \param numero a ingresar
 * \param el minimo que tiene el numero
 * \return un valor entero que ingreso
 *
 */
 int validarMinimo(int ,int);
 /** \brief valida enteros solo minimos
  *
  * \param un numero
  * \param y el minimo
  * \return un entero ya validado
  *
  */



int main()
{
    int legajo;
    float sueldo;
    legajo = ingreseNumero("ingrese el Legajo", legajo, 1000);

    printf("%d",legajo);
    return 0;
}

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
