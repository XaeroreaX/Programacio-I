#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main()
{
    char buffer[1024], nombre[24], apellido[24], nombreYApellido[50];
    int valCadena;


    printf("ingrese el nombre: ");
    gets(buffer);
    valCadena=strlen(buffer);
    while(valCadena > 23)
    {
        printf("ingrese un nombre mas corto: ");
        gets(buffer);
        valCadena=strlen(buffer);
    }
    strcpy(nombre, buffer);


    printf("ingrese el apellido: ");
    gets(buffer);
    valCadena=strlen(buffer);
    while(valCadena > 23)
    {
        printf("ingrese un apellido mas corto: ");
        gets(buffer);
        valCadena=strlen(buffer);
    }
    strcpy(apellido, buffer);



    nombre[0] = toupper(nombre[0]);
    apellido[0] = toupper(apellido[0]);


    strcpy(nombreYApellido, nombre);
    strcat(nombreYApellido,", ");
    strcat(nombreYApellido, apellido);


    puts(nombreYApellido);

    return 0;
}
