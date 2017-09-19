#include <stdlib.h>
#include <stdio.h>
#include "funsiones.h"
#include "ejercicios.h"
#define OK 0
#define DENEID -1




void showCancionesInterprete(eCancion canciones[], eInterprete interpretes[], int sizeC, int sizeI)
{
    int i, j;

    j = selectInterprete(interpretes, sizeI);

    for(i = 0; i < sizeC; i++)
    {
        if(canciones[i].flagAlta == OK)
        {
            if(interpretes[j].idInterprete == canciones[i].idInterprete)
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

