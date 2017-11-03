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



typedef struct
{
    int id;
    char* name;
    char* reference;
    char* descripcion;
    int saga;
    int chapter;
    char* linkImagen;

}Sstand;






int altaStandList(ArrayList*);


int bajaStandList(ArrayList*);
