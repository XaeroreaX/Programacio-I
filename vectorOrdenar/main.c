#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define D 5
#define N 51
#define S 200
//int delayCaracter(char , int);
int main()
{
    int numeros[D] = {4,1,2,0,3}, i = 0, j = 0, Aux;
    char nombre[N];

    for(i = 0; i < D; i++)
    {
        printf("ingrese el numero de la posicion %d: ", (i + 1));
        scanf("%d", &numeros[i]);
    }

    for(j = 0; j < D-1; j++)
    {
        for(i = (j+1); i < D; i++)
        {
            if(numeros[j] < numeros[i])
            {
                Aux = numeros[j];
                numeros[j] = numeros[i];
                numeros[i] = Aux;
            }
        }
    }
    for(i = 0; i < D; i++)
    {
        printf("%d\n", numeros[i]);

    }
    delayCaracter('a',S);

    return 0;
}

/*void delayCaracter(char caracter, int delay)
{
    printf("%c", caracter);
    sleep(delay);
}/*
