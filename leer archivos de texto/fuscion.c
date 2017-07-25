#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fuscion.h"
#define DENEID -1
#define OK 0


Speople* harcodearSpeople()
{
    int i, len;
    char nickName[5][50] = {"XaeroreaX", "mr. queen", "camila","Atilio", "pucci"};
    int age[5] = {23, 38, 19, 58, 27};

    Speople* people;

    people = (Speople*) malloc(sizeof(Speople) * 5);

    if(people == NULL) return NULL;

    for(i = 0; i < 5; i++)
    {


        (people+i)->age = age[i];

        len = strlen(nickName[i]);

        (people+i)->name =(char*) malloc(sizeof(char) * len + 1);

        if((people+i)->name == NULL) return NULL;

        strcpy((people+i)->name, nickName[i]);


    }

//    showStruct(people, showSpeople, 5);


    return people;
}

int printfile(Speople* people)
{
    int i ,returnAux = DENEID;

    FILE* arch;

    arch = fopen("texto.txt", "w+");

    if(arch == NULL) return returnAux;

    for(i = 0; i < 5; i++)
    {


        fprintf(arch,"%s|%d \r",(people+i)->name, (people+i)->age);

    }

    fclose(arch);

    returnAux = OK;

    return returnAux;
}
