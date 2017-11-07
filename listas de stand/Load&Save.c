#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "cascara.h"
#include "Load&Save.h"


int LoadStand(ArrayList* standList)
{
    int flag = OK, returnAux = DENEID, i;
    char id[10], name[500], reference[500], descripcion[1024], saga[10], chapter[10],user[500], linkImagen[1024];
    Sstand* stand;
    int cont=0;

    FILE * pFile;

    pFile = fopen ("dataStand.csv", "r");

    if(pFile == NULL || standList == NULL) return returnAux;
    returnAux = OK;
   //leer titulo
    fscanf(pFile, "%[^@]@%[^@]@%[^@]@%[^@]@%[^@]@%[^@]@%[^@]@%[^\n]\n", id, name, reference, descripcion, saga, chapter, user, linkImagen);

    //printf("hola");
    while(!feof(pFile))
    {


        if(flag != DENEID)
        {

            fscanf(pFile, "%[^@]@%[^@]@%[^@]@%[^@]@%[^@]@%[^@]@%[^@]@%[^\n]\n", id, name, reference, descripcion, saga, chapter, user, linkImagen);

            stand = constructParam(atoi(id), name, reference, descripcion, atoi(saga), atoi(chapter), user, linkImagen);

            if(standList->add(standList, stand) == OK)
                returnAux = standList->len(standList);

        }
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

    fprintf(pFile, "id@name@reference@descripcion@saga@chapter@user@linkImagen\n");
    returnAux = OK;
    for(i = 0; i < standList->len(standList); i++)
    {

        stand = standList->get(standList, i);

        fprintf(pFile, "%d@%s@%s@%s@%d@%d@%s%s\n", stand->id, stand->name, stand->reference,stand->descripcion, stand->saga, stand->chapter,stand->user, stand->linkImagen);


    }

    fclose(pFile);

    return returnAux;
}



int generarPagina(ArrayList* standList)
{
    int i, returnAux = DENEID, val;

    Sstand* stand;

    FILE* file;

    file = fopen("index.HTML", "w");

    if(standList == NULL || file == NULL) return returnAux;



    for(i = 0; i < standList->len(standList); i++)
    {

        stand = standList->get(standList, i);




        fprintf(file,"<img  src=%s alt=%s style=width:200px;hight:200px>",stand->linkImagen,stand->name);

                //titulo
        fprintf(file,"<h2><a href=#>%s</a></h2>",stand->name);

                //otros aspectos

      /*  int id;
    char* name;
    char* reference;
    char* descripcion;
    int saga;
    int chapter;
    char* user;
    char* linkImagen;*/

        fprintf(file,"<h3><li> referencia: %s</li>", stand->reference);
        fprintf(file,"<h3><li> usuario: %s</li>", stand->user);
        fprintf(file,"<h3><li> aparicion:  parte ");

        switch(stand->saga)
        {
            case PB:
                fprintf(file,"Phanton Blood ch%d</li>", stand->chapter);
                break;
            case BT:
                fprintf(file,"Battle Tendency ch%d</li>", stand->chapter);
                break;
            case SC:
                fprintf(file,"Stardust Cruzade ch%d</li>", stand->chapter);
                break;
            case DIU:
                fprintf(file,"Diamond Is Umbreakable ch%d</li>", stand->chapter);
                break;
            case VA:
                fprintf(file,"Vento Aureo ch%d</li>", stand->chapter);
                break;
            case SO:
                fprintf(file,"Stone Ocean ch%d</li>", stand->chapter);
                break;
            case SBR:
                fprintf(file,"Steel Ball Run ch%d</li>", stand->chapter);
                break;
            case JOJOLION:
                fprintf(file,"Jojolion ch%d</li>", stand->chapter);
                break;
            default:
                fprintf(file,"-- ch%d</li>");
                break;


        }


        fprintf(file,"<pre>%s</pre>", stand->descripcion);


    }




    printf("pagina generada esxitosamente");



    fclose(file);
    returnAux = OK;
    return returnAux;
}
