#include <stdio.h>
#include <stdlib.h>
//ejemplo de una funsion recursiva EN CLASE!!!


int factorial(int);

int main()
{
    int factor = 5;
    printf("%d\n",factorial(factor));
    return 0;
}

int factorial(int n)
{
    int valor;

    if(n == 0)
    {
        return 1;
    }
    else
    {
        valor = n * factorial(n-1);
        return valor;
    }

}
