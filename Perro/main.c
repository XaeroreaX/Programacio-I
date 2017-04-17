#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define P 3
#define D 5
#define PITBULL 1
#define OVEJERO 2
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


void HarcodearSPerro(int, SPerro[]);
void HarcodearSDuenio(int, SDuenio[]);
void mostrarPerro(int, int, SPerro[], SDuenio[]);
void mostrarRaza(int);
void mostrarVacunas(int);
SPerro CargarSPerro();
SDuenio CargarSDuenio();
//void mostrarRaza(SPerro);

int main()
{
    SDuenio duenios[D];
    SPerro perros[P];
    int i = 0;
    HarcodearSDuenio(D, duenios);
    HarcodearSPerro(P, perros);

    mostrarPerro(P, D, perros, duenios);

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

void HarcodearSDuenio(int tam, SDuenio duenio[tam])
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
void HarcodearSPerro(int tam, SPerro perror[tam])
{
    int i;
    int identificador[P] = {1, 2, 3};
    int raza[P] = {PITBULL, OVEJERO, PITBULL};
    char nombre[P][20] = {"toby", "doby", "yogui"};
    int vacunas[P] = {1, 0, 1};
    int duenio[P] = {1002, 1004, 1003};

    for(i = 0; i < P; i++)
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
        printf("Identificador:%d\nNombre del perro: %s\nRaza del perro: ", perro[i].identificador, perro[i].nombre, duenio[j].nombre);
        mostrarRaza(perro[i].raza);
        printf("\nNombre del duenio: %s\nEstado de las vacunas:", duenio[j].nombre);
        mostrarVacunas(perro[i].vacunasAlDia);
        printf("\n---------------------------------------------------\n");
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
