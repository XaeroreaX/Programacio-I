#define N 51
typedef struct
{
    int idCliente;
    char nombre[N];

}Scliente;

typedef struct
{
    int idSerie;
    char nombre[N];

}Sserie;

typedef struct
{
    int idCliente;
    int idSerie;
    int calificacion;


}SclienteSerie;

typedef struct
{
    int idSerie;
    int cont;
    float promedio
}Sranking;

void HarcodearScliente(Scliente[]);

void HarcodearSserie(Sserie[]);

void HarcodearSclienteSerie(SclienteSerie[], Scliente[], Sserie[]);

void MostrarScliente(int, Scliente[]);

void MostrarSserie(int , Sserie[]);

void MostrarSclienteSerie(int ,SclienteSerie[], Scliente[], Sserie[]);

void MostrarClientesFLCL(int, char[] ,SclienteSerie[], Scliente[], Sserie[]);



