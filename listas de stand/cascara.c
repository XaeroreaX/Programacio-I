#include <stdio.h>
#include <stdlib.h>
#include "cascara.h"


int altaStand(Sstand** stands, int* size, int* reserverSize)
{
    Sstand* stand;
    int i, returnAux = DENEID;



    stand = cargarStand(1000);

    if(stand != NULL)
    {
        i = *size;
        returnAux = OK;
        *(stands + i) = stand;

    }

    return returnAux;

}

