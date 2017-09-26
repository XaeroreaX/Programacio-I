#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "funsiones.h"
#include "ejercicios.h"
#define OK 0
#define DENEID -1


void showArtistasConMasCanciones(eCancion canciones[], eInterprete interpretes[], int sizeC, int sizeI)
{
    int i, j, max = 0, acumulador = 0, flag = DENEID;

    for(i = 0; i < sizeI; i++)
    {
        if(interpretes[i].flagAlta == OK)
        {
            for(j = 0; j < sizeC; j++)
            {
                if(canciones[j].flagAlta == OK)
                {

                    if(interpretes[i].idInterprete == canciones[j].idInterprete) acumulador++;

                }


            }

            if(acumulador > max || flag == DENEID)
            {
                max = acumulador;
                flag = OK;

            }
            acumulador = 0;

        }

    }


    for(i = 0; i < sizeI; i++)
    {
        if(interpretes[i].flagAlta == OK)
        {
            for(j = 0; j < sizeC; j++)
            {
                if(canciones[j].flagAlta == OK)
                {

                    if(interpretes[i].idInterprete == canciones[j].idInterprete) acumulador++;

                }


            }

            if(acumulador == max)
            {
                printf("%s\n", interpretes[i].nombreInterprete);
            }

            acumulador = 0;

        }

    }






}

int showDuracionInterprete(int idInterprete, eCancion canciones[], int size)
{
    int i, returnAux = DENEID, duracion = 0;

    for(i = 0; i < size; i++)
    {
        if(canciones[i].flagAlta == OK)
        {
            if(idInterprete == canciones[i].idInterprete)
            {
                returnAux = OK;
                duracion += canciones[i].duracion;
            }


        }



    }

    showDuracion(duracion);

    return returnAux;
}

int showInterpreteNacionalidad(eCancion canciones[], eInterprete interpretes[],int sizeC, int sizeI)
{
    int returnAux = DENEID, i, j;
    char nacionalidad[50];

    printf("ingrese una nacionalidad");
    cargarCaracter(50, nacionalidad);
    printf("\n\n");

    for(i = 0; i < sizeI; i++)
    {
        if(strcmp(interpretes[i].nacionalidad, nacionalidad) == 0)
        {
            printf("interprete %s:", interpretes[i].nombreInterprete);
            showCancionesInterprete(canciones, interpretes[i].idInterprete, sizeC);
            returnAux = OK;
        }


    }

    return returnAux;
}

void showCancionesInterprete(eCancion canciones[], int idInterprete, int size)
{
    int i, j;


    for(i = 0; i < size; i++)
    {
        if(canciones[i].flagAlta == OK)
        {
            if(idInterprete == canciones[i].idInterprete)
            {
                printf("\n%s", canciones[i].TituloCancion);
            }


        }
    }
    printf("\n");


    //for(i = 0; i < )



}


void showTable(eCancion canciones[], eInterprete interpretes[], int sizeC, int sizeI)
{
    /*int idCancion;
    char TituloCancion;
    int idInterprete;
    int duracion;
    int flagAlta;*/

    int i;
    printf("idCancion\t\t\tTitulo\t\tInterprete\t\tduracion\n");

    for(i = 0; i < sizeC; i++)
    {
        if(canciones[i].flagAlta == OK)
        {
            printf("%9d\t\t%14s\t\t", canciones[i].idCancion, canciones[i].TituloCancion);
            if(showInterprete(canciones[i].idInterprete, interpretes, sizeI) == DENEID) printf("UNKNOW");
            printf("\t\t  ");
            showDuracion(canciones[i].duracion);
            printf("\n");


        }



    }




}

int showInterprete(int idInterprete, eInterprete interprete[], int sizeI)
{
    int i, returnAux = DENEID;

    for(i = 0; i < sizeI; i++)
    {
        if(interprete[i].flagAlta == OK)
        {

            if(idInterprete == interprete[i].idInterprete)
            {
                printf("%10s", interprete[i].nombreInterprete);
                returnAux = OK;
                break;
            }

        }


    }

    return returnAux;
}


void showDuracion(int duracion)
{
    int minute;
    int second;
    minute = duracion / 60;
    second = duracion-(60*minute);

    if(second == 0)
    {
        printf("%2d:00",minute, second);
    }
    else
    {
        printf("%2d:%d",minute, second);
    }
}

