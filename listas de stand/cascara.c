#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "ArrayList.h"
#include "cascara.h"


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
