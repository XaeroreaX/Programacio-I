#include <stdio.h>
#include <stdlib.h>
#include "cascara.h"
#include "funsiones.h"
#define S 10
#define OK 0
#define DENEID -1


int main()
{

    int i,opcion=0;
    sSong canciones[S];

    VaciarSong(canciones, S);

    while(opcion != 6)
    {
        for(i = 0; i < S;i++)
        {
            if(canciones[i].flagAlta == OK)
            printf("%d\n", canciones[i].idCansion);
        }
        printf("1- Agregar \n");
        printf("2- Borrar \n");
        printf("3- Modificar \n");
        printf("5- mostrar\n");
        printf("6- Salir\n");
        printf("ingrese opcion:");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");

                if(alta(canciones, S) == DENEID) printf("no hay mas espacio");



                system("pause");
                break;
            case 2:
                system("cls");


                system("pause");
                break;
            case 3:
                system("cls");


                system("pause");
                break;
            case 4:
                system("cls");



                system("pause");
               break;
            case 5:
                system("cls");

                system("pause");
                break;
            case 6:
                break;
            default:
                system("cls");
                printf("ingreso mal la opcion, por favor ingrese de nuevo");
                system("pause");
                break;


        }
        system("cls");

    }


    return 0;
}

