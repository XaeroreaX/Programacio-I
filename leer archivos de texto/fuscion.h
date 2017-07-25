typedef struct{

    char *name;
    int age;

}Speople;



Speople* harcodearSpeople();

void showStruct(void* pArray, void (*pFunc)(void*), int size);

void showSpeople(void* pStruct);

