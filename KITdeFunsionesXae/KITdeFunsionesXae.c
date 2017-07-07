#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define H 5
#define N 51
#include "KITdeFunsionesXae.h"

SPersona HarcodearS(char nombre[NT], char telefono[NT], char nacionalidad[N], int edad, int dni, float altura, float peso)
{
    SPersona persona;
    strcpy(persona.nombre, nombre);
    strcpy(persona.telefono, telefono);
    strcpy(persona.nacionalidad, nacionalidad);
    persona.edad = edad;
    persona.dni = dni;
    persona.altura = altura;
    persona.peso = peso;

    return persona;
}

/**-----------------------------------------------------------------------------------------------------------------------*/
void HarcodearSArray(SPersona persona[H])
{
    int i = 0;
    char nombre[H][N] = {"Martin", "Roberto", "Claudia", "Camila", "Jesus"};
    char telefono[H][N] = {"155497-5912","4433-5477","155457-5719","4435-5246","155248-4795"};
    char nacionalidad[H][N] = {"Argentina", "Estados Unidos", "España", "Africa", "Mexico"};
    int edad[H] = {22, 66, 15, 33, 42};
    int dni[H] = {22458975, 66684219, 15785132, 33237981, 42428794};
    float altura[H] = {1.85, 2.10, 1.63, 1.25, 1.90};
    float peso[H] = {77.10, 80.63, 61.85, 53.25, 79.10};

    for(i = 0; i < H; i++)
    {
        strcpy(persona[i].nombre, nombre[i]);
        strcpy(persona[i].telefono, telefono[i]);
        strcpy(persona[i].nacionalidad, nacionalidad[i]);
        persona[i].edad = edad[i];
        persona[i].dni = dni[i];
        persona[i].altura = altura[i];
        persona[i].peso = peso[i];
    }

}

/**-----------------------------------------------------------------------------------------------------------------------*/


SPersona cargarPersona(int tam, SPersona persona)
{
    int i = 0;



        printf("\ningrese el nombre de la persona");
        persona.nombre = cargarCaracter(N, persona.nombre);
        printf("\ningrese el numero telefonico");
        gets(persona.telefono);
        printf("\ningrese la nacionalidad");
        gets(persona.nacionalidad);
        printf("\ningrese la edad");
        scanf("%d", &persona.edad);
        printf("\ningrese el dni");
        scanf("%d", &persona.dni);
        printf("\ningrese la altura");
        scanf("%f", &persona.altura);
        printf("\ningrese la peso");
        scanf("%f", &persona.peso);





}


/**-----------------------------------------------------------------------------------------------------------------------*/

char cargarCaracter(int tam, caracteres[tam])
{
    char buffer[1024];

    gets(buffer);
    while(strlen(buffer) > tam)
    {
        printf("ingreso mal la cadena de caracteres, ingrese de nuevo");
        gets(buffer);
    }
    strcpy(caracteres, buffer);

    return caracteres[tam];
}

/**-----------------------------------------------------------------------------------------------------------------------*/


void MostrarS(SPersona persona)
{

    printf("Nombre:%s----Nacionalidad:%s----Telefono:%s\n------------------------------------\nEdad:%d----DNI:%d----Altura:%f----Peso:%f\n", persona.nombre, persona.nacionalidad, persona.telefono, persona.edad, persona.dni, persona.altura, persona.peso);

}


/**-----------------------------------------------------------------------------------------------------------------------*/

Struct* contructor1(char string[1024], int entero)
{
    int len;
    Struct* construir;

    construir = (Struct*) malloc(sizeof(Struct));

    if(construir == NULL) return construir;

    construir->string = (char*) malloc(sizeof(char)*(strlen(string) + 1));


    strcpy(construir->string, string);
    construir->entero = entero;

    return construir;

}
