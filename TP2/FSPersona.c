#include "FSPersona.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

SPersona HarcodearS(char nombre[20],int edad,int dni, int flag)
{
    SPersona persona;
    strcpy(persona.nombre,nombre);
    persona.edad = edad;
    persona.dni = dni;
    persona.flagEstado = flag;
    return persona;
}

void mostraArrayS(int tam, SPersona persona[tam])
{
    int i;
    char estado[10];
    //char prueba[20] = "martin";
    for(i = 0; i < tam; i++)
    {
        if(persona[i].flagEstado == 1)
        {
            strcpy(estado, "casado");
        }
        else
        {
            if(persona[i].flagEstado == 0)
            {
                strcpy(estado, "soltero");
            }
        }
        printf("Nombre:%s----Edad:%d----DNI:%d---Estado:%s\n",persona[i].nombre, persona[i].edad, persona[i].dni, estado);
    }
    /*i = strcmp(persona[0].nombre,prueba);
    printf("la comparacion da %d",i);*/
}

SPersona ordenarS(int tam, SPersona persona[tam])
{
    SPersona Aux;
    int i, j;
    for(i = 0; i < tam-1; i++)
    {
        for(j = i+1; j < tam; j++)
        {
            if(strcmp(persona[j].nombre, persona[i].nombre) == -1)
            {
                Aux = persona[i];
                persona[i] = persona[j];
                persona[j] = Aux;
            }
        }
    }

    return persona[tam];
}


