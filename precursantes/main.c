#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int legajo;
    char* nombre;
    int nota;

}sRecursantes;


sRecursantes* newRecursante(int, char[], int);

int main()
{
    sRecursantes* recursante;

    recursante = newRecursante(106004,"martin",2);

    if(recursante!=NULL)
    {
        printf("legajo:%d\nnombre:%s\nnota:%d", recursante->legajo, recursante->nombre, recursante->nota);
        free(recursante);
    }

    return 0;
}

sRecursantes* newRecursante(int legajo, char nombre[], int nota)
{

    sRecursantes* r;
    int len;

    r = (sRecursantes*) malloc(sizeof(sRecursantes));

    if(r != NULL)
    {

        r->legajo = legajo;

        r->nombre = (char*) malloc(sizeof(char)*50);

        if(r->nombre != NULL)
        {
            strcpy(r->nombre, nombre);
            len = strlen(r->nombre);
            r->nombre = (char*) realloc(r->nombre, sizeof(char)* (len+1));

        }
        r->nota = nota;
    }


    return r;

}
