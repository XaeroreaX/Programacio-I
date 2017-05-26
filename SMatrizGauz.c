#include <stdio.h>
#include <stdlib.h>
#include "SMatrizGauz.h"
#define OK 0
#define DENIED 1



/**----------------------------------------------------------------------------------*////1)


void CargarMatriz(int** matriz , int FILA, int COL)
{

    int f,c;
    if(matriz != NULL)
    {

        //cargamos matriz con 2 for
        for(f = 0; f < FILA; f++)
        {
            for(c = 0; c < COL; c++)
            {
                printf("ingrese el elemento de la matriz[%d][%d] :", (f+1), (c+1));
                scanf("%d",(matriz[f] + c)); //asi se pide matriz dinamica

            }
        }


    }
    else
    {
        printf("no se encontro espacio en memoria"); //por si no encontro espacio en memoria
    }

}


/**----------------------------------------------------------------------------------*////2)


void mostrarMatriz(int** matriz, int FILA, int COL)
{
    int f,c;

    if(matriz != NULL)
    {

        for(f = 0; f < FILA; f++)
        {
            for(c = 0; c < COL; c++)
            {
                printf("%d ",*(matriz[f] + c));

            }

            printf("\n");
        }


    }
    else
    {
        printf("no se encontro espacio en memoria"); //por si no encontro espacio en memoria
    }


}


/**----------------------------------------------------------------------------------*////3)


int inversible(int** m)
{
    int* s;
    int a,b,c;
    s = (int*) malloc(sizeof(int));

    if(s != NULL)
    {


        //|A| = -a11.( a22.a33 - a23.a32 ) + a12.(a21.a33 - a31.a23) - a13.(a21.a32 - a22.a31)
        a = m[0][0] * ( (m[1][1] * m[2][2]) - (m[1][2] * m[2][1]) );
        b = m[0][1] * ( (m[1][0] * m[2][2]) - (m[2][0] * m[1][2]) );
        c = m[0][2] * ( (m[1][0] * m[2][1]) - (m[1][1] * m[2][0]) );

        *s = -a  + b -c ;



        printf("%d", *s);

        if(*s != OK)
        {
            printf("la matriz tiene inversa");
            return OK;

        }

        printf("la matriz no tiene inversa");
        return DENIED;

    }

}
