#include <stdio.h>
#include <stdlib.h>
#include "cascara.h"
#include "funciones.h"



int main()
{
    int option = 0;
    int size;
    int reserveSize;

    Sstand** stands;

    stands = newArrayStand(&size, &reserveSize);
    if(stands == NULL)
    {
        printf("no se encotro espacio!!!");
        option = 5;
    }


 //   printf("%d-%d", size, reserveSize);

    while(option != 5)
    {


        printf("1-alta\n");
        printf("2-baja\n");
        printf("3-modificacion\n");
        printf("4-generar pagina\n");
        printf("5-salir\n");

        printf("ingrese opcion:");

        scanf("%d", &option);

        switch(option)
        {
            case 1:
                system("cls");

                if(altaStand(stands, &size, &reserveSize) == DENEID) printf("no se encotro espacio!!!");

                system("cls");
                break;

            case 2:


                break;

            case 3:


                break;

            case 4:


                break;

            case 5:


                break;

            default:


                break;

        }


    }

    return 0;
}
