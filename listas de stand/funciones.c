#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cascara.h"
#include "funciones.h"


Sstand** newArrayStand(int* size, int* reserveSize)
{




    stands = (Sstand**) malloc(sizeof(Sstand*)*10);
    if(stands == NULL) return returnAux ;

    size = constructInt(0);
    if(size == NULL) return NULL;


    reserveSize = constructInt(10);
    if(reserveSize == NULL) return NULL;




    return returnAux;

}

int* constructInt(int valor)
{
    int* num;

    num = (int*) malloc(sizeof(int));
    if(num != NULL) *num = 0;


    return num;
}


Sstand* constructParam(int id, char name[], char descripcion[], int saga, int chapter, char linkImagen[])
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
        stand->descripcion = dinamicCharacter(descripcion);
        if(stand->descripcion == NULL) return NULL;
        stand->linkImagen = dinamicCharacter(linkImagen);
        if(stand->linkImagen == NULL) return NULL;



    }


    return stand;
}


Sstand* cargarStand(int id)
{

    Sstand* stand;

    int  saga, chapter;
    char name[1024], descripcion[1024], linkImagen[1024];

    printf("ingrese el id: ");
    scanf("%d", &id);

    fflush(stdin);

    printf("ingrese el nombre:");

    fflush(stdin);

    cargarCaracter(1024, name);
    printf("ingrese la descripcion:");

    fflush(stdin);

    cargarCaracter(1024, descripcion);
    printf("ingrese la saga:");

    fflush(stdin);
    scanf("%d", &saga);
    printf("ingrese el capitulo:");

    fflush(stdin);
    scanf("%d", &chapter);
    printf("ingrese el linkImagen:");

    fflush(stdin);
    cargarCaracter(1024, linkImagen);

    stand = constructParam(id, name, descripcion, saga, chapter, linkImagen);


    return stand;
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




