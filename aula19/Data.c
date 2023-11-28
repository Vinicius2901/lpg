#include "Data.h"
#include <stdio.h>


void le_data( Data *p )
{
    do
    {
        printf("Digite o dia: ");
        scanf("%d", &p->dia);
    } while ((*p).dia > 31 || p->dia < 1);

    printf("Digite o mes: ");
    scanf("%d", &p->mes);
    printf("Digite o ano: ");
    scanf("%d", &p->ano);
}

void mostra_data( Data *p )
{
    printf("%d/%d/%d\n", p->dia, p->mes, p->ano );
}