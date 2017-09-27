#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funsiones.h"
#define OK 0
#define DENEID -1



sSong addSong(sSong canciones[], int size)
{
    int i = 0;

    sSong song;

    song.idCansion = getId(canciones, size);

    printf("\ningrese el nombre");
    cargarCaracter(30, song.nombre);



    song.duracion = numValidado("\ningrese la duracion", 0 , 3600);

    song.flagAlta = OK;

    return song;


}

void VaciarSong(sSong canciones[], int size)
{
    int i;

    for(i = 0; i < size; i++)
    {
        canciones[i].flagAlta = DENEID;
    }


}


int getId(sSong canciones[], int size)
{

    int i, id = 1000;

    for(i = 0; i < size; i++)
    {
        if(canciones[i].flagAlta == OK)
        {
            id = canciones[i].idCansion + 1;

        }
        else
        {
            break;
        }


    }

    return id;
}



int buscarEspcioSong(sSong canciones[], int size)
{
    int i;

    for(i = 0; i<size; i++) if(canciones[i].flagAlta == DENEID) break;

    if(i == size) i = DENEID;

    return i;

}



int numValidado(char messages[], int ground, int top)
{
    int numero;
    fflush(stdin);

    printf("%s:",messages);
    scanf("%d", &numero);

    while(numero < ground || numero > top)
    {
        printf("el numero ingresado no es valido, por favor ingrese de nuevo");
        fflush(stdin);
        scanf("%d", &numero);
    }

    return numero;
}



char cargarCaracter(int tam, char caracteres[])
{
    char buffer[1024];

    fflush(stdin);
    gets(buffer);
    while(strlen(buffer) > tam)
    {
        printf("ingreso mal la cadena de caracteres, ingrese de nuevo");
        fflush(stdin);
        gets(buffer);
    }
    strcpy(caracteres, buffer);

    return caracteres[tam];
}

