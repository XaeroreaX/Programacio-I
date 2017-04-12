#include "FSPersona.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T 3


int main()
{
    SPersona persona[T];
    //int i;

    persona[0] = HarcodearS("pepe", 12, 37880456, 1);
    persona[1] = HarcodearS("juan", 36, 38840456, 0);
    persona[2] = HarcodearS("yusepe", 24, 44750446, 0);
    persona[T] = ordenarS(T, persona);
    mostraArrayS(T, persona);

    return 0;
}
