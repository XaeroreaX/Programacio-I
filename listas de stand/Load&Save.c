#include <stdio.h>
#include <stdlib.h>



int LoadStand(Sstand** stands, int* size, int* reseverSize)
{
    int flag = OK, returnAux = DENEID;
    char id[10], name[500], reference[500], descripcion[1024], saga[10], chapter[10], linkImagen[1024];
    Sstand* stand;
    int cont=0;

    FILE * pFile;

    pFile = fopen ("dataStand.csv", "r");

    if(pFile == NULL || stands == NUL) return returnAux;

   //leer titulo
    fscanf(pFile, "%[^,]@%[^,]@%[^,]@%[^,]@%[^,]@%[^,]@%[^\n]\n", id, name, reference, descripcion, saga, chapter, linkImagen);

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
