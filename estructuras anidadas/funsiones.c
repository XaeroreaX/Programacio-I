#include <stdlib.h>
#include <stdio.h>
#include "funsiones.h"
#include "ejercicios.h"
#define OK 0
#define DENEID -1


char mostrarMenu(char texto[])
{
    char opcion;
    printf("%s", texto);
    opcion = getche();
    return opcion;
}

void cargarCanciones(eCancion listaCanciones[], int size)
{
    int i,flag=0;

     for(i=0; i<size; i++)
   {
       if(listaCanciones[i].idCancion==0)
       {
        flag=1;
        printf("Ingrese id de la cancion: ");
       scanf("%d", &listaCanciones[i].idCancion);
       printf("Ingrese nombre: ");
       fflush(stdin);
       gets(listaCanciones[i].TituloCancion);
       printf("Ingrese id del interperte: ");
       scanf("%d", &listaCanciones[i].idInterprete);
       printf("Ingrese duracion: ");
       scanf("%d", &listaCanciones[i].duracion);
       break;
       }

   }
   if(flag==0)
   {
       printf("no hay lugar.");
   }
}

void cargarInterpretes(eInterprete listaInterpretes[], int TAM)
{
    int i,flag=0;

     for(i=0; i<TAM; i++)
   {
       if(listaInterpretes[i].idInterprete==0)
       {
        flag=1;
        printf("Ingrese id del interprete: ");
       scanf("%d", &listaInterpretes[i].idInterprete);
       printf("Ingrese nombre del interprete: ");
       fflush(stdin);
       gets(listaInterpretes[i].nombreInterprete);
       printf("Ingrese nacionalidad del interprete: ");
       fflush(stdin);
       gets(listaInterpretes[i].nacionalidad);

       }

   }
   if(flag==0)
   {
       printf("no hay lugar.");
   }
}

int findEspacioCanciones(eCancion cancion[], int size)
{
    int i, returnAux = DENEID;

    for(i = 0; i < size; i++)
    {
        if(cancion[i].flagAlta == DENEID)
        {
            returnAux = i;
            break;
        }


    }

    return returnAux;

}


eInterprete cargarPersona(eInterprete arrayInterpretes[], int size)
{
    int i = 0;
    eInterprete interprete;

    /*int idInterprete;
    char nombreInterprete[30];
    char nacionalidad[30];
    int flagAlta;*/

        interprete.idInterprete = getIdI(arrayInterpretes, size);
        printf("\ningrese el nombre del interprete");
        cargarCaracter(30, interprete.nombreInterprete);
        printf("\ningrese la nacionalidad");

        cargarCaracter(30, interprete.nacionalidad);

        interprete.flagAlta = OK;



}

int getId(eInterprete arrayInterpretes[], int size)
{
    int i, returnAux = DENEID;
    for(i = 0; i < size; i++)
        {
            if(arrayInterpretes[i].flagAlta == DENEID)
            {
                returnAux = arrayInterpretes[i-1].idInterprete + 1;
                break;

            }
        }

    return returnAux;
}


eCancion cargarPersona(eCancion arrayCanciones[], int sizeC)
{
    int i = 0;
    eCancion canciones;
    /*int idCancion;
    char TituloCancion[30];
    int idInterprete;
    int duracion;
    int flagAlta;*/

        canciones.idCancion = getIdC(arrayCanciones, sizeC);
        printf("\ningrese el nombre de la cancion");
        cargarCaracter(N, canciones.TituloCancion);

        i = selectInterprete()

        scanf("%d", &persona.edad);




}


int getIdI(eInterprete arrayInterpretes[], int size)
{
    int i, returnAux = DENEID;
    for(i = 0; i < size; i++)
        {
            if(arrayInterpretes[i].flagAlta == DENEID)
            {
                returnAux = arrayInterpretes[i-1].idInterprete + 1;
                break;

            }
        }

    return returnAux;
}


int getIdC(eCancion arrayCanciones[], int size)
{
    int i, returnAux = DENEID;
    for(i = 0; i < size; i++)
        {
            if(arrayCanciones[i].flagAlta == DENEID)
            {
                returnAux = arrayCanciones[i-1].idCancion + 1;
                break;

            }
        }

    return returnAux;
}



int selectInterprete(eInterprete interpretes[], int size)
{
    int i, returnAux = DENEID;

    for(i = 0; i < size; i++)
    {
        if(interpretes[i].flagAlta == OK)
        {

            printf("%d)%s\n",(i+1), interpretes[i].nombreInterprete);

        }

    }

    fflush(stdin);

    scanf("%d", &i);
    i--;

    returnAux = i;


    return returnAux;
}


void HarcodeareInterprete(eInterprete interprete[])
{
    /*int idInterprete;
    char nombreInterprete[30];
    char nacionalidad[30];idInterprete
    int flagAlta;*/
    int i = 0;
    int idInterprete[5] = {1000, 1001, 1002, 1003, 1004};
    char nombreInterprete[5][30] = {"Martin", "Roberto", "Claudia", "Camila", "Jesus"};
    char nacionalidad[5][30] = {"Argentina", "Estados Unidos", "España", "Africa", "Mexico"};

    for(i = 0; i < 5; i++)
    {
        strcpy(interprete[i].nombreInterprete, nombreInterprete[i]);
        strcpy(interprete[i].nacionalidad, nacionalidad[i]);
        interprete[i].idInterprete = idInterprete[i];
        interprete[i].flagAlta = OK;
    }

}

void HarcodeareCancion(eCancion cancion[])
{
    /*int idCancion;
    char TituloCancion;
    int idInterprete;
    int duracion;
    int flagAlta;*/
    int i = 0;
    int idCancion[5] = {100, 101, 102, 103, 104};
    char TituloCancion[5][30] = {"MID", "KQ", "BR", "Starless", "21 guns"};
    int idInterprete[5] = {1003, 1001,  1000,  1002, 1000};
    int duracion[5] = {180 , 210 ,  160 ,  360 , 400};

    for(i = 0; i < 5; i++)
    {
        strcpy(cancion[i].TituloCancion, TituloCancion[i]);
        cancion[i].idCancion = idCancion[i];
        cancion[i].idInterprete = idInterprete[i];
        cancion[i].duracion = duracion[i];
        cancion[i].flagAlta = OK;
    }

}


void cargarCaracter(int tam, char caracteres[])
{
    char buffer[1024];

    gets(buffer);
    while(strlen(buffer) > tam)
    {
        printf("ingreso mal la cadena de caracteres, ingrese de nuevo");
        gets(buffer);
    }
    strcpy(caracteres, buffer);

}
