#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "KITdeFunsionesXae.h"


/**-----------------------------------------------------------CASCARA------------------------------------------------------------------*/

int cascara(ArrayList* movieList)
{

    char seguir='s';
    int opcion=0, returnAux = DENEID;

    if(movieList == NULL) return returnAux;

    while(seguir=='s')
        {
            printf("1- Agregar \n");
            printf("2- Borrar \n");
            printf("3- Modificar \n");
            printf("5- mostrar\n");
            printf("6- Salir\n");
            printf("ingrese opcion")

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



                    system("pause");
                   break;
                case 5:
                    system("cls");

                    system("pause");
                    break;
                case 6:
                    seguir = 'n';
                    break;
                default:
                    system("cls");
                    printf("ingreso mal la opcion, por favor ingrese de nuevo");
                    system("pause");
                    break;


            }
            system("cls");

        }
    returnAux = OK;
    return returnAux;
}


/**-----------------------------------------------------HARCODEO------------------------------------------------------------------------*/

void HarcodearSArray(struct[])
{
    int i = 0;
    char nombre[][] = {"Martin", "Roberto", "Claudia", "Camila", "Jesus"};
    int edad[] = {22, 66, 15, 33, 42};

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


/**------------------------------------------------------------------------*/

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




/**---------------------------------------------------------ALTA--------------------------------------------------------------------*/


struct cargarS()
{
    int i = 0;

    struct persona;

    printf("\ningrese el nombre ");
    cargarCaracter(N, persona.nombre);


    printf("\ningrese la edad");
    scanf("%d", &persona.edad);


    return persona;


}


/**------------------------------------------------------------------------*/

sSong addS(sSong canciones[], int size)
{
    int i = 0;

    sSong song;

    song.idCansion = buscarEspcioSong(canciones, size);

    printf("\ningrese el nombre");
    cargarCaracter(30, song.nombre);


    printf("\ningrese la duracion");
    song.duracion = numValidado("\ningrese la duracion", 0 , 3600);


    return song;


}

/**------------------------------------------------------------------------*/

int getId(sSong canciones[], int size)
{

    int i, id = 1000;

    for(i = 0; i < size; i++)
    {
        if(canciones[i].flagAlta == OK)
        {
            id = canciones[i].idCansion + 1;

        }
        else break;

    }

    return id;
}

/**---------------------------------------------------------------*/

int buscarEspcioStruct(sSong canciones[], int size)
{
    int i;

    for(i = 0; i<size; i++) if(canciones[i].flagAlta == DENEID) break;

    if(i == size) i = DENEID;

    return i;

}



/**---------------------------------------------------------------*/

char cargarCaracter(int tam, char caracteres[])
{
    char buffer[1024];

    fflush(stdin);
    gets(buffer);
    while(strlen(buffer) > tam)
    {
        printf("ingreso mal la cadena de caracteres, ingrese de nuevo");
        fflush(stdin);
        gets(buffer);
    }
    strcpy(caracteres, buffer);

    return caracteres[tam];
}


/**---------------------------------------------------------------*/

int numValidado(char messages[], int ground, int top)
{
    int numero;
    fflush(stdin);

    printf("%s:",messages);
    scanf("%d", &numero);

    while(numero < ground || numero > top)
    {
        printf("el numero ingresado no es valido, por favor ingrese de nuevo");
        fflush(stdin);
        scanf("%d", &numero);
    }

    return numero;
}


/**---------------------------------------------------------------*/

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

/**---------------------------------------------------------------*/

void vaciar(int size, char string[size])
{
    int i;

    for(i = 0; i < size; i++)
        string[i] = '\0';


}

/**-------------------------------------------------CONSTRUCTOR----------------------------------------------------------------------------*/


void VaciarStruct(sSong canciones[], int size)
{
    int i;

    for(i = 0; i < size; i++)
    {
        canciones[i].flagAlta = DENEID;
    }


}


/**---------------------------------------------------------------*/

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





/**----------------------------------------------------ARCHIVOS-------------------------------------------------------------------------*/

int ListToFile()
{
    FILE* file;
    int returnAux = DENEID, index;

    SUser* user;

    user = (SUser*) malloc(sizeof(SUser));

    file = fopen("dataUser.dat", "w+b");

    if(file == NULL || userList == NULL)
    {
        fclose(file);
        return returnAux;
    }


    for(index = 0; index < userList->len(userList); index++)
    {
        user =(SUser*) userList->get(userList, index);

        fwrite(user, sizeof(SUser), 1 ,file);

    }



    fclose(file);
    return returnAux;
}


/**-------------------------------------------------------------*/

int fileToList(ArrayList* movieList)
{
    FILE* file;
    int returnAux = DENEID, index, size;

    EMovie* movie;



    file = fopen("data.dat", "rb");

    if(file == NULL || movieList == NULL)
    {
        fclose(file);
        return returnAux;
    }

    fseek(file, 0 , SEEK_END);

    size = ftell(file)/sizeof(EMovie);

    rewind(file);

    for(index = 0; index<size; index++)
    {
        movie = (EMovie*) malloc(sizeof(EMovie));

        fread(movie, sizeof(EMovie), 1,file);

        returnAux = movieList->add(movieList, movie);
        if(returnAux == DENEID) break;

    }
/*
    len = showMovieListIndex(movieList);
        if(len == DENEID) printf("Error en la funcion showMovieList");*/

    fclose(file);
    return returnAux;
}


/**-------------------------------------------------------------*/


void fgetsToChar(FILE* pFile, int size, char string[size], char To)
{
    int i;

    char auxChar;


    for(i = 0; auxChar != To && i < size; i++)
    {
        auxChar = fgetc(pFile);
        if(auxChar != To)
            string[i] = auxChar;

    }



}



/**---------------------------------------------------------SORT--------------------------------------------------------------------*/

int compareMovie(void* MovieA, void* MovieB)
{

    if(((EMovie*)MovieA)->puntaje < ((EMovie*)MovieB)->puntaje)
    {
        return 1;
    }


    if(((EMovie*)MovieA)->puntaje > ((EMovie*)MovieB)->puntaje)
    {
        return -1;
    }

    if(((EMovie*)MovieA)->puntaje == ((EMovie*)MovieB)->puntaje)
    {
        if(strcmp(((EMovie*)MovieA)->titulo, ((EMovie*)MovieB)->titulo) == 1)
        {
            return 1;
        }
        else
        {
            return -1;
        }

    }


    return 0;


}




