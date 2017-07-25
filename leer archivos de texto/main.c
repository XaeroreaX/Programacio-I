#include <stdio.h>
#include <stdlib.h>
#include "fuscion.h"
#define DENEID -1
#define OK 0


int main()
{
    Speople* people;
    people = harcodearSpeople();

    printfile(people);

    return 0;
}
