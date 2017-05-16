#include <stdio.h>
#include <stdlib.h>
#define T 5
int main()
{
    int* pInt, pAux, pAuxi;
    int i, j;

    pAuxi = (int*) malloc(sizeof(int));
    pInt = (int*) malloc(sizeof(int)* T);
    if(pInt != NULL)
    {
        for(i = 0; i < T; i++)
        {
            printf("ingrese un numero: ");
            scanf("%d", pInt+i);
        }

        for(i = 0; i < T; i++)
        {
            printf("%p--%d\n",(pInt+i), *(pInt+i));

        }
        system("pause");

        pAux = (int*) realloc(pInt, sizeof(int)*(T+5));
        if(pAux != NULL)
        {

            pInt = pAux;


            for(i = T; i < T + 5; i++)
            {
                printf("ingrese un numero: ");
                scanf("%d", pInt+i);
            }
            for(i = 0; i < T + 5 - 1; i++ )
            {
                for(j = i + 1; i < T + 5; j++ )
                {
                    if(*(pInt + i) > *(pInt + j) )
                    {
                        *pAux = &(pInt + i);
                        *(pInt + i) = (pInt + j);
                        *(pInt + i) = pAux ;
                    }



                }
            }
            for(i = 0; i < T + 5; i++)
            {
                printf("%p--%d\n",(pInt+i), *(pInt+i));

            }

            system("pause");

            pAux = (int*) realloc(pInt, sizeof(int)*(T-2));
            if(pAux != NULL)
            {
                pInt = pAux;

                for(i = 0; i < T  - 2; i++)
                {
                    printf("ingrese un numero: ");
                    scanf("%d", pInt+i);
                }
                for(i = 0; i < T - 2; i++)
                {
                    printf("%p--%d\n",(pInt+i), *(pInt+i));

                }
            }

        }
    }
    return 0;
}
