#define PB 1
#define BT 2
#define SC 3
#define DIU 4
#define VA 5
#define SO 6
#define SBR 7
#define JOJOLION 8
#define OK 0
#define DENEID -1


Sstand** newArrayStand(int* size, int* reserveSize);

int* constructInt(int valor);


Sstand* constructParam(int id, char name[], char descripcion[], char[], int saga, int chapter, char linkImagen[]);


Sstand* cargarStand(int id);


int resizeUp(Sstand** stands, int* reserverSize);


char* dinamicCharacter(char character[]);
