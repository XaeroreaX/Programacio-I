typedef struct
{
    int idCansion;
    char nombre[30];
    int duracion;
    int flagAlta;

}sSong;



sSong addSong(sSong[], int);

void VaciarSong(sSong[], int);

int getId(sSong[], int);

int buscarEspcioSong(sSong[], int);

int numValidado(char[], int, int);

char cargarCaracter(int, char[]);
