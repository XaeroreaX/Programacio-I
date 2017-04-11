#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T 3
typedef struct
{
    char nombre[20];
    int edad;
    int dni;
    int flagEstado;
}SPersona;

SPersona HarcodearS(char[], int, int, int);

void mostraArrayS(SPersona[]);

SPersona ordenarS(SPersona[]);

int main()
{
    SPersona persona[T];
    //int i;

    persona[0] = HarcodearS("juan", 12, 37880456, 1);
    persona[1] = HarcodearS("pepe", 36, 38840456, 1);
    persona[2] = HarcodearS("yusepe", 24, 44750446, 1);
    persona[T] = ordenarS(persona);
    mostraArrayS(persona);

    return 0;
}

SPersona HarcodearS(char nombre[20],int edad,int dni, int flag)
{
    SPersona persona;
    strcpy(persona.nombre,nombre);
    persona.edad = edad;
    persona.dni = dni;
    persona.flagEstado = flag;
    return persona;
}

void mostraArrayS(SPersona persona[T])
{
    int i;
    char prueba[20] = "martin";
    for(i = 0; i < T; i++)
    {
        printf("Nombre:%s----Edad:%d----DNI:%d\n",persona[i].nombre, persona[i].edad, persona[i].dni);
    }
    /*i = strcmp(persona[0].nombre,prueba);
    printf("la comparacion da %d",i);*/
}

SPersona ordenarS(SPersona persona[T])
{
    SPersona Aux;
    int i, j;
    for(i = 0; i < T-1; i++)
    {
        for(j = i+1; j < T; j++)
        {
            if(strcmp(persona[j].nombre, persona[i].nombre) < 0)
            {
                Aux = persona[i];
                persona[i] = persona[j];
                persona[j] = persona[i];
            }
        }
    }

    return persona[T];
}

