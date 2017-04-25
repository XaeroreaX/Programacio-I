#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FSbaseDeNetflix.h"
#define N 51
#define T 5
#define TX 10

void HarcodearScliente(Scliente cliente[T])
{
    int i = 0;
    int idCliente[T] = {100, 101, 102, 103, 104};
    char nombre[T][N] = {"pepe", "Martin", "Mauricio", "Cristian", "sanchez"};
    for(i = 0; i < T; i++)
    {
        cliente[i].idCliente = idCliente[i];
        strcpy(cliente[i].nombre, nombre[i]);
    }

    //MostrarScliente(T, cliente);

}

/**-------------------------------------------------------------------------------------------------------------------------*/


void MostrarScliente(int tam, Scliente cliente[tam])
{
    int i;
    for(i = 0; i < tam; i++)
    {
        printf("id:%d-----Nombre:%s\n",cliente[i].idCliente, cliente[i].nombre);
    }


}

/**-------------------------------------------------------------------------------------------------------------------------*/


void HarcodearSserie(Sserie serie[T])
{
    int i = 0;
    int idSerie[T] = {100, 101, 102, 103, 104};
    char nombre[T][N] = {"FLCL", "TTGL", "JJBA:SC", "GOT", "Rick & Morty"};
    for(i = 0; i < T; i++)
    {
        serie[i].idSerie = idSerie[i];
        strcpy(serie[i].nombre, nombre[i]);
    }

    //MostrarSserie(T, serie);

}


/**-------------------------------------------------------------------------------------------------------------------------*/


void MostrarSserie(int tam, Sserie serie[tam])
{
    int i;
    for(i = 0; i < T; i++)
    {
        printf("id:%d-----Nombre:%s\n",serie[i].idSerie, serie[i].nombre);
    }
}

/**-------------------------------------------------------------------------------------------------------------------------*/

void HarcodearSclienteSerie(SclienteSerie clienteSerie[T], Scliente cliente[T], Sserie serie[T])
{
    int i = 0,j = 0, k = 0;
    int idCliente[T] = {100, 100, 103, 102, 102};
    int idSerie[T] = {100, 101, 102, 101, 100};
    int calificacion[T] = {9, 7, 7, 8, 6};

    for(i = 0; i < T; i++)
    {
        clienteSerie[i].idCliente = idCliente[i];
        clienteSerie[i].idSerie = idSerie[i];
        clienteSerie[i].calificacion = calificacion[i];
    }

   // MostrarSclienteSerie(T, clienteSerie, cliente, serie);

}



/**-------------------------------------------------------------------------------------------------------------------------*/

void MostrarSclienteSerie(int tam, SclienteSerie clienteSerie[tam], Scliente cliente[tam], Sserie serie[tam])
{
    int i, j, k;
    for(i = 0; i < tam; i++)
    {
        for(j = 0; cliente[j].idCliente != clienteSerie[i].idCliente && j < tam; j++);
        for(k = 0; serie[k].idSerie != clienteSerie[i].idSerie && k < tam; k++);
        printf("El cliente %s vio",cliente[j].nombre);
        printf(" %s y lo califico con un %d\n",serie[k].nombre,clienteSerie[i].calificacion);


    }
}

/**-------------------------------------------------------------------------------------------------------------------------*/

void MostrarClientesFLCL(int tam, char seriep[51] ,SclienteSerie clienteSerie[tam], Scliente cliente[tam], Sserie serie[tam])
{
    int i = 0 , j = 0 ,k = 0,m = 0;


    for(i = 0; i < tam; i++)
    {
        m = i;
        for(; strcmp(serie[m].nombre, seriep) != 0 && m < tam; m++);
        if(m < tam)
        {
            for(k = 0; serie[m].idSerie != clienteSerie[k].idSerie && k < tam; k++);
            if(k < tam)
            {
                for(j = 0; clienteSerie[i].idCliente != cliente[j].idCliente && j < tam; j++);

                printf("el cliente %s,", cliente[j].nombre);




            }
        }
    }

    printf("vieron %s",seriep);




}

