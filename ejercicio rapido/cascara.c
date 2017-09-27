#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cascara.h"
#include "funsiones.h"
#define OK 0
#define DENEID -1


int alta(sSong canciones[], int size)
{
    int i, returnAux = DENEID;

    i = buscarEspcioSong(canciones, size);

    if(i != DENEID)
    {
        canciones[i] = addSong(canciones, size);
        returnAux = OK;
    }

    return returnAux;
}

