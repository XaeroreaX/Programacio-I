#include <stdlib.h>
#include <stdio.h>
#include "funsiones.h"
#include "ejercicios.h"
#define TAM 10
#define OK 0
#define DENEID -1
/*duracion de todo los temas y el artista con mas canciones y todos los artistas de una nacionalidad*/

int main()
{
    char opcion,seguir='s';
    int i;

    eCancion canciones[TAM];
    eInterprete interpretes[TAM];

    for(i=0;i<TAM;i++)
    {
        canciones[i].flagAlta=DENEID;
        interpretes[i].idInterprete=DENEID;
    }

    HarcodeareCancion(canciones);
    HarcodeareInterprete(interpretes);

    system("cls");
    showTable(canciones, interpretes, TAM, TAM);
    system("pause");

    system("cls");
    i = selectInterprete(interpretes, TAM);
    showCancionesInterprete(canciones, interpretes[i].idInterprete, TAM);
    system("pause");


    system("cls");
    if(showInterpreteNacionalidad(canciones, interpretes, TAM, TAM) == DENEID) printf("no se encontraron interpretes");
    system("pause");

    system("cls");
    i = selectInterprete(interpretes, TAM);

    showDuracionInterprete(interpretes[i].idInterprete, canciones, TAM);
    system("pause");

    system("cls");
    showArtistasConMasCanciones(canciones, interpretes, TAM, TAM);
    system("pause");

 /*
    do{

        opcion= mostrarMenu("1.ingrese interprete\n2.ingrese cancion.\n3.Salir.\nIngrese una opcion:");

        switch(opcion)
        {
        case '1' :
                cargarCanciones(canciones,tam);
            break;
        case '2' :
                cargarInterpretes(interpretes,tam);

            break;
        case '3' :
            seguir='n';
            break;
        }

    }while(seguir=='s');
*/


    return 0;
}

