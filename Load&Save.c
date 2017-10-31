#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "cascara.h"
#include "Load&Save.h"


int LoadStand(ArrayList* standList)
{
    int flag = OK, returnAux = DENEID, i;
    char id[10], name[500], reference[500], descripcion[1024], saga[10], chapter[10], linkImagen[1024];
    Sstand* stand;
    int cont=0;

    FILE * pFile;

    pFile = fopen ("dataStand.csv", "r");

    if(pFile == NULL || standList == NULL) return returnAux;
    returnAux = OK;
   //leer titulo
    fscanf(pFile, "%[^@]@%[^@]@%[^@]@%[^@]@%[^@]@%[^@]@%[^\n]\n", id, name, reference, descripcion, saga, chapter, linkImagen);
    //printf("%s,%s,%s,%s,%s,%s,%s\n", id, name, reference, descripcion, saga, chapter, linkImagen);

    while(!feof(pFile))
    {


        fscanf(pFile, "%[^@]@%[^@]@%[^@]@%[^@]@%[^@]@%[^@]@%[^\n]\n", id, name, reference, descripcion, saga, chapter, linkImagen);

         //printf("%s,%s,%s,%s,%s,%s,%s\n", id, name, reference, descripcion, saga, chapter, linkImagen);


        stand = constructParam(atoi(id), name, reference, descripcion, atoi(saga), atoi(chapter), linkImagen);

        if(standList->add(standList, stand) == OK)
            returnAux = standList->len(standList);


    }

      fclose(pFile);

    return returnAux;
}


int saveStand(ArrayList* standList)
{
    int i, returnAux = DENEID;
    Sstand* stand;

    FILE * pFile;

    pFile = fopen("dataStand.csv", "w+");

    if(standList == NULL || pFile == NULL) return returnAux;

    fprintf(pFile, "id@name@reference@descripcion@saga@chapter@linkImagen\n");
    returnAux = OK;
    for(i = 0; i < standList->len(standList); i++)
    {

        stand = standList->get(standList, i);

        fprintf(pFile, "%d@%s@%s@%s@%d@%d@%s\n", stand->id, stand->name, stand->reference,stand->descripcion, stand->saga, stand->chapter, stand->linkImagen);


    }

    fclose(pFile);

    return returnAux;
}
