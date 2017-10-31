#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "cascara.h"


int altaStand(ArrayList* standList)
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

