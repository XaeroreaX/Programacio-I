#include <stdio.h>
#include <stdlib.h>
#include "FSbaseDeNetflix.h"
#define T 5
#define TX 10

/*
mostrar cada uno
mostrar clientes con su serie
por cada serie los clientes que la estan viendo
la serie menos popular
todas las gente que tenga "FLCL"
*/
int main()
{
    Scliente cliente[T];
    Sserie serie[T];
    SclienteSerie clienteSerie[T];
    printf("clientes:\n");
    HarcodearScliente(cliente);
    printf("----------------\n");
    printf("Serie:\n");
    HarcodearSserie(serie);
    HarcodearSclienteSerie(clienteSerie, cliente, serie);
    printf("\n");
    MostrarClientesFLCL(T, "TTGL", clienteSerie, cliente,serie);

    return 0;
}
