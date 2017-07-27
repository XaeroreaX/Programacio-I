#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"


int parserEmployee(FILE* pFile , ArrayList* pArrayListEmployee)
{
    int i;
    char auxString[128], auxChar;

    Employee* auxEmployee;

    pFile = fopen("data.csv","r");

    if(pFile == NULL || pArrayListEmployee == NULL)
    {
        printf("no se pudo leer el archivo\n")
        return -1;
    }

    fgets(auxString, 128, pFile);
    freeString(auxString, 128);

    while(!feof(pFile))
    {
        for(i = 0; auxChar != ","; i++)
        {
            auxChar = fgetc(pFile);

            if(auxChar != ",")
            {
                auxString[i] = auxChar;
            }

        }

        auxEmployee->id = atoi(auxChar);


        for(i = 0; auxChar != ","; i++)
        {
            auxChar = fgetc(pFile);

            if(auxChar != ",")
            {
                auxString[i] = auxChar;
            }

        }


        strcpy(auxEmployee->name, auxString);


        for(i = 0; auxChar != ","; i++)
        {
            auxChar = fgetc(pFile);

            if(auxChar != ",")
            {
                auxString[i] = auxChar;
            }

        }


        strcpy(auxEmployee->name, auxString);

        fgets(auxString, 6, pFile);

    }

    fclose(pFile);

    return 0;
}



void freeString(char String[size], int size)
{
    int i;

    for(i = 0; i < size; i++)
        char String[i] = '\0';

}

/*
char* FgetsToChar(FILE* pFile, char to)
{


    for(i = 0; auxChar != ","; i++)
    {
        auxChar = fgetc(pFile);

        if(auxChar != ",")
        {
            auxString[i] = auxChar;
        }

        }


}*/
