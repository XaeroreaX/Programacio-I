#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define H 5
#define N 51
#include "KITdeFunsionesXae.h"

SPersona HarcodearS(char nombre[NT], char telefono[NT], char nacionalidad[N], int edad, int dni, float altura, float peso)
{
    SPersona persona;
    strcpy(persona.nombre, nombre);
    strcpy(persona.telefono, telefono);
    strcpy(persona.nacionalidad, nacionalidad);
    persona.edad = edad;
    persona.dni = dni;
    persona.altura = altura;
    persona.peso = peso;

    return persona;
}

/**-----------------------------------------------------------------------------------------------------------------------*/
void HarcodearSArray(SPersona persona[H])
{
    int i = 0;
    char nombre[H][N] = {"Martin", "Roberto", "Claudia", "Camila", "Jesus"};
    char telefono[H][N] = {"155497-5912","4433-5477","155457-5719","4435-5246","155248-4795"};
    char nacionalidad[H][N] = {"Argentina", "Estados Unidos", "España", "Africa", "Mexico"};
    int edad[H] = {22, 66, 15, 33, 42};
    int dni[H] = {22458975, 66684219, 15785132, 33237981, 42428794};
    float altura[H] = {1.85, 2.10, 1.63, 1.25, 1.90};
    float peso[H] = {77.10, 80.63, 61.85, 53.25, 79.10};

    for(i = 0; i < H; i++)
    {
        strcpy(persona[i].nombre, nombre[i]);
        strcpy(persona[i].telefono, telefono[i]);
        strcpy(persona[i].nacionalidad, nacionalidad[i]);
        persona[i].edad = edad[i];
        persona[i].dni = dni[i];
        persona[i].altura = altura[i];
        persona[i].peso = peso[i];
    }

}

/**-----------------------------------------------------------------------------------------------------------------------*/


SPersona cargarPersona(int tam, SPersona persona)
{
    int i = 0;



        printf("\ningrese el nombre de la persona");
        persona.nombre = cargarCaracter(N, persona.nombre);
        printf("\ningrese el numero telefonico");
        gets(persona.telefono);
        printf("\ningrese la nacionalidad");
        gets(persona.nacionalidad);
        printf("\ningrese la edad");
        scanf("%d", &persona.edad);
        printf("\ningrese el dni");
        scanf("%d", &persona.dni);
        printf("\ningrese la altura");
        scanf("%f", &persona.altura);
        printf("\ningrese la peso");
        scanf("%f", &persona.peso);





}


/**-----------------------------------------------------------------------------------------------------------------------*/

char cargarCaracter(int tam, caracteres[tam])
{
    char buffer[1024];

    gets(buffer);
    while(strlen(buffer) > tam)
    {
        printf("ingreso mal la cadena de caracteres, ingrese de nuevo");
        gets(buffer);
    }
    strcpy(caracteres, buffer);

    return caracteres[tam];
}

/**-----------------------------------------------------------------------------------------------------------------------*/


void MostrarS(SPersona persona)
{

    printf("Nombre:%s----Nacionalidad:%s----Telefono:%s\n------------------------------------\nEdad:%d----DNI:%d----Altura:%f----Peso:%f\n", persona.nombre, persona.nacionalidad, persona.telefono, persona.edad, persona.dni, persona.altura, persona.peso);

}


/**-----------------------------------------------------------------------------------------------------------------------*/

Struct* contructor1(char string[1024], int entero)
{
    int len;
    Struct* construir;

    construir = (Struct*) malloc(sizeof(Struct));

    if(construir == NULL) return construir;

    construir->string = (char*) malloc(sizeof(char)*(strlen(string) + 1));


    strcpy(construir->string, string);
    construir->entero = entero;

    return construir;

}


int harcodearSUser(ArrayList* userList)
{
    int i, returnAux = DENEID, id[5] = {1, 1001, 1002, 1003, 1004};
    char nickName[5][50] = {"XaeroreaX", "mr. queen", "camila","Atilio", "pucci"};
    char password[5][50] = {"master6060", "rey2501", "camila","abel6060", "Made in heaven"};
    SUser* user;



    if(user == NULL || userList == NULL) return returnAux;

    for(i = 0; i < 5; i++)
    {


        user = (SUser*) malloc(sizeof(SUser));
        user->id = id[i];

        strcpy(user->nickName, nickName[i]);
        strcpy(user->password, password[i]);

        returnAux = userList->add(userList, user);
        if(returnAux == DENEID) break;

    }

    return returnAux;
}

int menuAdministrador(ArrayList* movieList)
{

    char seguir='s';
    int opcion=0, returnAux = DENEID;

    if(movieList == NULL) return returnAux;

    while(seguir=='s')
        {
            printf("1- Agregar pelicula\n");
            printf("2- Borrar pelicula\n");
            printf("3- Modificar pelicula\n");
            printf("4- Generar pagina web\n");
            printf("5- Limpiar la lista de peliculas\n");
            printf("6- Salir\n");

            scanf("%d",&opcion);

            switch(opcion)
            {
                case 1:
                    system("cls");

                    if(addMovieList(movieList) == DENEID) printf("Error en la funcion addMovieList\n");

                    system("pause");
                    break;
                case 2:
                    system("cls");
                    if(removeMovieList(movieList) == DENEID) printf("Error en la funcion removeMovieList\n");

                    system("pause");
                    break;
                case 3:
                    system("cls");

                    if(setMovieList(movieList) == DENEID) printf("Error en la funcion removeMovieList\n");

                    system("pause");
                    break;
                case 4:
                    system("cls");

                    if(generarPagina(movieList) == DENEID) printf("Error en la funcion generarPagina\n");

                    system("pause");
                   break;
                case 5:
                    system("cls");
                    if(movieList->clear(movieList) == DENEID)
                    {


                        printf("ERROR en la funsion CLEAR en movieList\n");
                    }
                    else
                    {


                        printf("el arrayList fue limpiado\n");
                    }

                    system("pause");
                    break;
                case 6:
                    seguir = 'n';
                    break;


            }

            if(movieList->sort(movieList, compareMovie, 1) == DENEID ) printf("ERROR en la funsion sort de arrayList de EMovie");
            movieListToFile(movieList);
            system("cls");

        }
    returnAux = OK;
    return returnAux;
}

/**-------------------------------------------------------////n)

int charAddDinamic(char* caracter)
{
    int len, returnAux = DENEID;
    char* aux;

    caracter = (char*) malloc(sizeof(char) * 1024);

    if(caracter == NULL) return returnAux;

    fflush(stdin);
    scanf("%1023[^\n]", caracter);

    len = strlen(caracter);

    aux = (char*) realloc(caracter, sizeof(char*)* len+1);

    if(aux != NULL)
    {
        caracter = aux;
        returnAux = OK;
    }

    return returnAux;
}
