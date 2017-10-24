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
        returnAux = OK;

        i = *size;

        if(*size == *reserverSize)
        {
            returnAux = resizeUp(stands, reserverSize);
        }


        if(returnAux == OK) *(stands + i) = stand;
        *size = i + 1;

    }

    return returnAux;

}

