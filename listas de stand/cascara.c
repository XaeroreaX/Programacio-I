#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "ArrayList.h"
#include "cascara.h"
#include "funciones.h"


int altaStandList(ArrayList* standList)
{
    Sstand* stand;
    int i, returnAux = DENEID, id;

    if(standList == NULL) return returnAux;


    id = getId(standList);

    stand = cargarStand(id);

    if(stand != NULL)
    {


        returnAux = standList->add(standList, stand);


    }

    return returnAux;

}


int bajaStandList(ArrayList* standList)
{
    int index, returnAux = DENEID - 1;

    char seleccion;

    Sstand* stand;


    if(standList == NULL) return returnAux;

    index = getIndex(standList);


    if(index != DENEID)
    {
        stand = standList->get(standList, index);

        printf("desea eliminar a %s? y/n", stand->name);

        seleccion = getch();

        if(seleccion = 'y')
        {


            returnAux = standList->remove(standList, index);

            if(returnAux == DENEID) returnAux = DENEID - 1;
        }
    }



}


int modifStandList(ArrayList* standList)
{
    int index, id, returnAux = DENEID - 1;

    char seleccion;

    Sstand* stand;


    if(standList == NULL) return returnAux;

    index = getIndex(standList);


    if(index != DENEID)
    {
        stand = standList->get(standList, index);

        printf("desea modificar a %s? y/n\n", stand->name);

        seleccion = getch();

        if(seleccion = 'y')
        {
            printf("ingrese los datos:\n");


            id = getId(standList);

            stand = cargarStand(id);

            returnAux = standList->set(standList, stand);

            if(returnAux == DENEID) returnAux = DENEID - 1;
        }
    }



}


int informarStand(ArrayList* standList)
{

    int i, returnAux = DENEID, parte, from = DENEID, to = DENEID, flagFrom = DENEID/*, flagTo = DENEID*/;

    Sstand* stand;

    ArrayList* arco;

    if(standList == NULL) return returnAux;

    printf("ingrese las siguientes pociones\n");
    printf("0.todas las sagas\n");
    printf("1. parte 1\n");
    printf("2. parte 2 \n");
    printf("3. parte 3\n");
    printf("4. parte 4\n");
    printf("5. parte 5\n");
    printf("6. parte 6\n");
    printf("7. parte 7\n");
    printf("8. parte 8\n");
    printf("ingrese opcion:");
    scanf("%d", &parte);

    if(parte == 0)
    {
        showAllStand(standList, showStandDescription);

    }
    else
    {

        for(i = 0; i < standList->len(standList); i++)
        {

            stand = standList->get(standList, i);

            if(flagFrom == DENEID)
            {
                if(parte == stand->saga)
                {
                    from = i;
                    flagFrom = OK;
                }

            }


            if(from != DENEID)
            {
                if(stand->saga != parte)
                {
                    to = i;
                    break;
                }
            }


        }

        if(from != DENEID)
        {
            if(to != DENEID)
            {
                arco = standList->subList(standList, from, to);
            }
            else
            {
                arco = standList->subList(standList, from, standList->len(standList));
            }

        }


        showAllStand(arco, showStandDescription);


    }
}
