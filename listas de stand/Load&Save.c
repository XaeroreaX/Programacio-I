#include <stdio.h>
#include <stdlib.h>
#include "cascara.h"
#include "Load&Save.h"


int LoadStand(Sstand** stands, int* size, int* reseverSize)
{
    int flag = OK, returnAux = DENEID, i;
    char id[10], name[500], reference[500], descripcion[1024], saga[10], chapter[10], linkImagen[1024];
    Sstand* stand;
    int cont=0;

    FILE * pFile;

    pFile = fopen ("dataStand.csv", "r");

    if(pFile == NULL || stands == NULL) return returnAux;
    returnAux = OK;
   //leer titulo
    fscanf(pFile, "%[^,]@%[^,]@%[^,]@%[^,]@%[^,]@%[^,]@%[^\n]\n", id, name, reference, descripcion, saga, chapter, linkImagen);

    if(ferror(pFile)) return returnAux;

    while(!feof(pFile))
    {
        if(*size == *reseverSize) flag = resizeUp(stands, reseverSize);

        if(flag != DENEID)
        {

            fscanf(pFile, "%[^,]@%[^,]@%[^,]@%[^,]@%[^,]@%[^,]@%[^\n]\n", id, name, reference, descripcion, saga, chapter, linkImagen);

            stand = constructParam(atoi(id), name, reference, descripcion, atoi(saga), atoi(chapter), linkImagen);
            i = *size;

            *(stands+i) = stand;

            *size = i + 1;

            returnAux = *size;

        }
    }

      fclose(pFile);

    return returnAux;
}


int saveStand(Sstand** stands, int *size)
{
    int i, returnAux = DENEID;
    Sstand* stand;

    FILE * pFile;

    pFile = fopen("dataStand.csv", "w+");

    if(stands == NULL || pFile == NULL) return returnAux;

    fprintf(pFile, "id@name@reference@descripcion@saga@chapter@linkImagen\n");
    returnAux = OK;
    for(i = 0; i < *size; i++)
    {

        stand = *(stands+i);

        fprintf(pFile, "%d@%s@%s@%s@%d@%d@%s\n", stand->id, stand->name, stand->reference,stand->descripcion, stand->saga, stand->chapter, stand->linkImagen);


    }

    fclose(pFile);

    return returnAux;
}
