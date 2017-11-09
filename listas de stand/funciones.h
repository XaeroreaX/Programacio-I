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


Sstand* constructParam(int id, char name[], char descripcion[], char[], int saga, int chapter, char user[], char linkImagen[]);


Sstand* cargarStand(int id);


int getId(ArrayList* standList);

int getIndex(ArrayList* standList);

void showStand(Sstand* stand);

void showStandDescription(Sstand* stand);

void showAllStand(ArrayList* standList, void (*funcion)(Sstand*));

int compareStandAparicion(void* standA, void* standB);

char* dinamicCharacter(char character[]);
