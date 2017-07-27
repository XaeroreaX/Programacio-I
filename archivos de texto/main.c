#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/


int main()
{



    char seguir='s';
    int opcion=0, returnAux = DENEID;
    FILE* pFile;

    ArrayList* pArrayListEmployee = al_newArrayList();

    while(seguir=='s')
        {
            printf("1. Parse del archivo data.csv\n");
            printf("2. Listar Empleados\n");
            printf("3. Ordenar por nombre\n");
            printf("4. Agregar un elemento\n");
            printf("5. Elimina un elemento\n");
            printf("6. Listar Empleados (Desde/Hasta)\n");
            printf("7. salir\n");

            printf("\n\tIngrese opcion:");

            scanf("%d",&opcion);

            switch(opcion)
            {
                case 1:
                    system("cls");


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
;

                    system("pause");
                   break;
                case 5:
                    system("cls");

                    system("pause");
                    break;
                case 6:
                    system("cls");

                    system("pause");
                    break;
                case 7:
                    seguir = 'n';
                    break;


            }

         //   if(movieList->sort(movieList, compareMovie, 1) == DENEID ) printf("ERROR en la funsion sort de arrayList de EMovie");
         //   movieListToFile(movieList);
            system("cls");

        }

    return 0;
}
