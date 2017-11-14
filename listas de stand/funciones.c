#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "cascara.h"
#include "funciones.h"


Sstand** newArrayStand(int* size, int* reserveSize)
{

    Sstand** stands;


    stands = (Sstand**) malloc(sizeof(Sstand*)*10);
    if(stands == NULL) return stands;

   *size = 0;


   *reserveSize = 10;




    return stands;

}

int* constructInt(int valor)
{
    int* num;

    num = (int*) malloc(sizeof(int));
    if(num != NULL) *num = valor;


    return num;
}


Sstand* constructParam(int id, char name[], char descripcion[], char reference[], int saga, int chapter, char user[], char linkImagen[])
{
    Sstand* stand;

    stand = (Sstand*) malloc(sizeof(Sstand));

    if(stand != NULL)
    {

        stand->id = id;
        stand->saga = saga;
        stand->chapter = chapter;
        stand->name = dinamicCharacter(name);
        if(stand->name == NULL) return NULL;

        stand->reference = dinamicCharacter(reference);
        if(stand->reference == NULL) return NULL;
        stand->descripcion = dinamicCharacter(descripcion);
        if(stand->descripcion == NULL) return NULL;
        stand->user = dinamicCharacter(user);
        if(stand->user == NULL) return NULL;
        stand->linkImagen = dinamicCharacter(linkImagen);
        if(stand->linkImagen == NULL) return NULL;



    }


    return stand;
}


Sstand* cargarStand(int id)
{

    Sstand* stand;

    int  saga, chapter;
    char name[1024], descripcion[1024], reference[1024], user[1024], linkImagen[1024];



    printf("ingrese el nombre:");

    fflush(stdin);

    cargarCaracter(1024, name);
    printf("ingrese la descripcion:");

    fflush(stdin);

    cargarCaracter(1024, descripcion);


    printf("ingrese el referencia:");

    fflush(stdin);

    cargarCaracter(1024, reference);


    printf("ingrese la saga:");
    fflush(stdin);
    scanf("%d", &saga);
    printf("ingrese el capitulo:");

    fflush(stdin);
    scanf("%d", &chapter);
    printf("ingrese el user:");

    fflush(stdin);
    cargarCaracter(1024, user);

    printf("ingrese el linkImagen:");

    fflush(stdin);
    cargarCaracter(1024, linkImagen);

    stand = constructParam(id, name, descripcion,reference, saga, chapter, user, linkImagen);


    return stand;
}


int getId(ArrayList* standList)
{
    int flagEncontrado = DENEID;
    int i, j,id;
    Sstand* stand1, *stand2;

    if(standList == NULL) return id;


    if(standList->isEmpty(standList) == 1)
    {
        id = 1000;
    }
    else
    {


        stand1 =(Sstand*) standList->get(standList, 0);
        id = stand1->id +1;


        for(i = 1; i < standList->len(standList); i++)
        {
            stand1 =(Sstand*) standList->get(standList, i);

            if(stand1->id == id)
            {
                id = stand1->id +1;
            }
            else
            {

                for(j = i + 1; j < standList->len(standList); j++)
                {
                    stand2 =(Sstand*) standList->get(standList, j);

                    if(id == stand2->id) break;

                }


                if(j < standList->len(standList)) flagEncontrado = OK;

            }

            if(flagEncontrado == DENEID)
            {
                id = stand1->id + 1;
            }
            else
            {
                break;
            }
        }

    }

    return id;
}


int getIndex(ArrayList* standList)
{
    int index, id;

    Sstand* stand;

    showAllStand(standList,showStand);

    printf("ingrese el id del stand");

    scanf("%d", &id);

    for(index = 0; index < standList->len(standList); index++)
    {

        stand = standList->get(standList, index);

        if(stand->id == id) break;

    }

    if(index == standList->len(standList)) index = DENEID;

    return index;

}


void showStand(Sstand* stand){printf("%d:%s", stand->id, stand->name);}


void showStandDescription(Sstand* stand){printf("%s\n-------------------------------------------------------------\n\n%50s\n\n---------------------------------------------------\n",stand->name,stand->descripcion);}


void showAllStand(ArrayList* standList, void (*funcion)(Sstand*))
{
    int i;

    Sstand* stand;

    for(i = 0; i < standList->len(standList); i++)
    {

        stand = standList->get(standList, i);

        funcion(stand);

        printf("\n");

    }

}


int compareStandAparicion(void* standA, void* standB)
{

    if(((Sstand*) standA)->saga > ((Sstand*)standB)->saga)
    {
        return 1;
    }

    if(((Sstand*) standA)->saga < ((Sstand*)standB)->saga)
    {
        return -1;
    }

    if(((Sstand*) standA)->saga == ((Sstand*)standB)->saga)
    {
        if(((Sstand*) standA)->chapter > ((Sstand*)standB)->chapter)
        {
            return 1;
        }

        if(((Sstand*) standA)->saga < ((Sstand*)standB)->saga)
        {
            return -1;
        }
    }

    return 0;

}

char* dinamicCharacter(char character[])
{
    char* chars;
    int len;

    len = strlen(character);

    chars = (char*) malloc(sizeof(char)*(len+1));

    strcpy(chars, character);


    return chars;
}



/**---------------------------------------------------------------*/

void cargarCaracter(int tam, char caracteres[])
{
    char buffer[1024];

    fflush(stdin);
    gets(buffer);
    while(strlen(buffer) > tam)
    {
        printf("ingreso mal la cadena de caracteres, ingrese de nuevo");
        fflush(stdin);
        gets(buffer);
    }
    strcpy(caracteres, buffer);


}




