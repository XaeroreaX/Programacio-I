#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ArrayList.h"
#include "cascara.h"
#include "funciones.h"
#include "Load&Save.h"


int main()
{
    int option = 0;
    char seleccion;
    ArrayList* standList;

    standList = al_newArrayList();

    if(LoadStand(standList) == DENEID) printf("no pudo abrir el archivo\n");
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

                if(altaStandList(standList) == DENEID)
                {


                    printf("no se encotro espacio!!!\n");
                    system("pause");
                }
                system("cls");
                break;

            case 2:
                system("cls");

                if(bajaStandList(standList) == (DENEID - 1))
                {


                    printf("no se pudo remover el stand\n");
                    system("pause");
                }
                system("cls");
                break;

            case 3:
                system("cls");

                if(modifStandList(standList) == DENEID)
                {


                    printf("no se pudo modificar el stand\n");
                    system("pause");
                }
                system("cls");
                break;

            case 4:

                generarPagina(standList);

                break;

            case 5:
                system("cls");



                break;

            default:


                break;

        }


    }


    printf("desea guardar el progreso? y/n");
    fflush(stdin);
    seleccion = getchar();
    if(seleccion == 'y')
    {
        //printf("hola");
        if(saveStand(standList)) printf("error al salvar el archivo");
    }
    return 0;
}
