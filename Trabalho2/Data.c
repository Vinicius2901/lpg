#include "Data.h"
#include <stdio.h>

void le_data( Data *p ){
	do{
		printf("Digite o dia: ");
		scanf("%d", &p->dia);
	}while( (*p).dia > 31 || p->dia < 1 );
	do
	{
		printf("Digite o mes: ");
		scanf("%d", &p->mes);
	} while( p->mes > 12 || p->mes < 1 );
	printf("Digite o ano: ");
	scanf("%d", &p->ano);
}

void mostra_data( Data *p ){
	printf("%d/%d/%d\n", p->dia, p->mes, p->ano );
}

int compara_datas( Data *a, Data *b)
{
	if( a->ano != b->ano )
		return a->ano - b->ano;

	if( a->mes != b->mes )
		return a->mes - b->mes;

	return a->dia - b->dia;
}