typedef struct
{
    int idInterprete;
    char nombreInterprete[30];
    char nacionalidad[30];
    int flagAlta;
}eInterprete;

typedef struct
{
    int idCancion;
    char TituloCancion[30];
    int idInterprete;
    int duracion;
    int flagAlta;
}eCancion;

char mostrarMenu(char texto[]);
void cargarInterpretes(eInterprete [], int);
void cargarCanciones(eCancion[], int );


void HarcodeareInterprete(eInterprete interprete[]);
void HarcodeareCancion(eCancion cancion[]);
