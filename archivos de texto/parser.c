#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"


int parserEmployee(FILE* pFile , ArrayList* pArrayListEmployee)
{
    int i;
    char auxString[128] , auxChar;

    Employee* auxEmployee;

    pFile = fopen("data.csv", "r");

    fgets(auxString,128,pFile);

    printf("%s",auxString);

    vaciar(128, auxString);

    while(!feof(pFile))
    {
        fgetsToChar(pFile, 128, auxString, ',');
        auxEmployee->id = atoi(auxString);

        vaciar(128, auxString);

        fgetsToChar(pFile, 128, auxString, ',');
        strcpy(auxEmployee->name, auxString);

        auxChar = fgetc(pFile);

        vaciar(128, auxString);

        fgetsToChar(pFile, 128, auxString, ',');
        strcpy(auxEmployee->lastName, auxString);


        vaciar(128, auxString);

        fgetsToChar(pFile, 128, auxString, '\n');

        switch(auxString[0])
        {
            case 't':
                auxEmployee->isEmpty = 1;
                break;
            case 'f':
                auxEmployee->isEmpty = 0;
                break;
        }

        pArrayListEmployee->add(pArrayListEmployee, auxEmployee);
        vaciar(128, auxString);


       // system("pause");
    }

    printf("%s\n",auxString);
    return 0;
}

void fgetsToChar(FILE* pFile, int size, char string[size], char To)
{
    int i;

    char auxChar;


    for(i = 0; auxChar != To && i < size; i++)
    {
        auxChar = fgetc(pFile);
        if(auxChar != To)
            string[i] = auxChar;

    }



}

void vaciar(int size, char string[size])
{
    int i;

    for(i = 0; i < size; i++)
        string[i] = '\0';


}


