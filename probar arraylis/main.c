#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"


typedef struct
{

    char name[21];
    int age;

}SPeople;

void HarcodearS(SPeople[]);

int main()
{

    ArrayList* pList;
    SPeople get;
    SPeople person[10];
    int i;

    pList =(ArrayList*) malloc(sizeof(ArrayList));

    pList = al_newArrayList();

    HarcodearS(person);


    pList->add(pList, person[1]);

    get = pList->get(pList, 0);

    printf("%s",get.name);
    return 0;
}

void HarcodearS(SPeople person[10])
{
    char name[5][21] = {"Marta","Ricardo","Leo","Mentecato","Sircon"};
    int age[5] = {34,17,15,40,60};
    int i;

    for(i = 0; i < 5; i++)
    {

        strcpy(person[i].name, name[i]);
        person[i].age = age[i];


    }


}
