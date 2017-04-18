#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define D 20
#define PITBULL 1
#define OVEJERO 2
#define PP 3
/*a)Listado de perros c/ nombre de su dueño

b)Listado de Dueños c/ sus perros

c)Listado de dueños con perros PP

D)Listado de dueños que deben vacunar a sus perros

*/
typedef struct
{
    int identificador;
    int raza;
    int vacunasAlDia;
    int duenio;
    char nombre[20];

}SPerro;

typedef struct
{
    int codigo;
    char nombre[20];
    char telefono[20];

}SDuenio;


void HarcodearSPerro(SPerro[]);
void HarcodearSDuenio(SDuenio[]);
void mostrarPerro(int, int, SPerro[], SDuenio[]);
void mostrarDuenio(int, int, SPerro[], SDuenio[]);
void mostrarDuenioRPP(int, int, SPerro[], SDuenio[]);
void mostrarDuenioIrresponsables(int, int, SPerro[], SDuenio[]);
void mostrarRaza(int);
void mostrarVacunas(int);
SPerro CargarSPerro();
SDuenio CargarSDuenio();
//void mostrarRaza(SPerro);

int main()
{
    SDuenio duenios[D];
    SPerro perros[D];
    int i = 0;
    //HarcodearSDuenio(duenios);
    //HarcodearSPerro(perros);

    //mostrarPerro(D, D, perros, duenios);

    //mostrarDuenio(D, D, perros, duenios);

    //mostrarDuenioRPP(D, D, perros, duenios);

    //mostrarDuenioIrresponsables(D, D, perros, duenios);

    /*for(i = 0; i < D; i++)
    {
        duenios[i] = CargarSDuenio();
    }*/
    /*for(i = 0; i < P; i++)
    {
        perros[i] = CargarSPerro();
    }*/

    return 0;
}

SPerro CargarSPerro()
{
    SPerro perro;
    char buffer[1024];
    printf("ingrese el identificador del perro:");

    scanf("%d", &perro.identificador);
    printf("ingrese la raza del perro(del 1 al 5):");
    scanf("%d", &perro.raza);
    printf("ingrese el nombre del perro:");
    fflush(stdin);
    gets(perro.nombre);
    printf("vacunas:");
    scanf("%d", &perro.vacunasAlDia);
    printf("ingrese el identificador de la raza:");
    scanf("%d", &perro.duenio);

    return perro;
}

SDuenio CargarSDuenio()
{
    SDuenio duenio;

    scanf("%d", &duenio.codigo);

    fflush(stdin);
    gets(duenio.nombre);

    scanf("%d", &duenio.telefono);

    return duenio;
}

void HarcodearSDuenio(SDuenio duenio[D])
{

    int i = 0;
    int codigo[D] = {1001, 1002, 1003, 1004, 1005};
    char telefono[D][20] = {"4431-2501", "4733-3583", "4531-8879", "4435-7751", "4433-5477"};
    char nombre[D][20] = {"juan", "martin", "pity", "dela", "sancho"};

    for(i= 0; i < D; i++)
    {
        duenio[i].codigo = codigo[i];
        strcpy(duenio[i].telefono, telefono[i]);
        strcpy(duenio[i].nombre, nombre[i]);
    }

}
void HarcodearSPerro(SPerro perror[D])
{
    int i;
    int identificador[D] = {1, 2, 3, 4, 5};
    int raza[D] = {PITBULL, OVEJERO, PITBULL, PP, PP};
    char nombre[D][20] = {"toby", "doby", "yogui", "neko","firulaiz"};
    int vacunas[D] = {0, 0, 0, 0, 0};
    int duenio[D] = {1002, 1004, 1003, 1002, 1004};

    for(i = 0; i < D; i++)
    {
        perror[i].identificador = identificador[i];
        perror[i].raza = raza[i];
        strcpy(perror[i].nombre, nombre[i]);
        perror[i].vacunasAlDia = vacunas[i];
        perror[i].duenio = duenio[i];
    }

}
void mostrarPerro(int tamP, int tamD, SPerro perro[tamP], SDuenio duenio[tamD])
{
    int i = 0, j;
    for(i = 0; i < tamP; i++)
    {

        for(j = 0; j < tamD && duenio[j].codigo != perro[i].duenio; j++);
        printf("Nombre del perro: %s y Nombre del duenio: %s\n", perro[i].nombre, duenio[j].nombre);

    }

}

void mostrarDuenio(int tamP, int tamD, SPerro perro[tamP], SDuenio duenio[tamD])
{
    int i, j;
    for(i = 0; i < tamD; i++)
    {
        for(j = 0; j < tamP && duenio[i].codigo != perro[j].duenio; j++);
        if(j < tamP)
            printf("el nombre del duenio es %s y tiene los siguientes perros:\n", duenio[i].nombre);
        else
            printf("el duenio %s no tiene perros\n",duenio[i].nombre);
        for(j = 0; j< tamP; j++)
        {
            if(duenio[i].codigo == perro[j].duenio)
            {
                printf("-%s\n", perro[j].nombre);

            }



        }



    }

}

void mostrarDuenioRPP(int tamP, int tamD, SPerro perro[tamP], SDuenio duenio[tamD])
{
    int i = 0, j = 0, flag = 0;
    for(i = 0; i < tamD; i++)
    {
        for(j = 0; j < tamP; j++)
        {
            if(duenio[i].codigo == perro[j].duenio && perro[j].raza == PP)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 1)
            break;
    }

    if(flag == 0)
    {
        printf("no hay duenios con perros de la raza PP");

    }
    else
    {
        for(i = 0; i < tamD; i++)
        {
            for(j = 0; j < tamP && (duenio[i].codigo != perro[j].duenio || perro[j].raza != PP); j++);
            if(j < tamP)
            {
                printf("el duenio %s tiene los siguientes perros de la raza PP:", duenio[i].nombre);
                for(j = 0; j < tamP; ++j)
                {
                    if(duenio[i].codigo == perro[j].duenio && perro[j].raza == PP)
                    {
                        printf(" %s\t",perro[j].nombre);
                    }

                }
                printf("\n\n");
            }
            else
            {
                printf("el duenio %s no tiene perros de la raza\n\n", duenio[i].nombre);
            }

        }
    }


}

void mostrarDuenioIrresponsables(int tamP, int tamD, SPerro perro[tamP], SDuenio duenio[tamD])
{
    int i, j, flag = 0;

    for(i = 0; i < tamD; i++)
    {
        for(j = 0; j < tamP && (duenio[i].codigo != perro[j].duenio || perro[j].vacunasAlDia == 1); j++);
        if(j < tamP)
        {
            printf("el duenio %s tiene que vacunar a ", duenio[i].nombre);

            for(j = 0; j < tamP; j++)
            {
                if(duenio[i].codigo == perro[j].duenio && perro[j].vacunasAlDia == 0)
                {
                    printf(".%s ", perro[j].nombre);

                }
            }
        }
    }

}

void mostrarRaza(int raza)
{

    switch(raza)
    {
        case PITBULL:
            printf("Pitbull");
            break;
        case OVEJERO:
            printf("Ovejero");
            break;
        case PP:
            printf("PP");
        default:
            printf("error");
            break;

    }

}
 void mostrarVacunas(int V)
 {
     if(V == 1)
     {
         printf("todas las vacunas al dia");
     }
     else
     {
         printf("faltan vacunas");
     }
 }
