#include "trabalho.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void carrega_registro( Evento *v, int *n, char *nome_arq )
{
    int i;
    FILE *f = fopen( nome_arq, "rt");
    if( f == NULL )
    {
        printf("O arquivo ainda nao existe\n");
    }
    else
    {
        fscanf( f, "%d", n );
        v = malloc( sizeof(Evento) * *n );
        for( i = 0; i < *n; i++ )
        {
            fscanf( f, "%d %d %d", &v[i].event.dia, &v[i].event.mes, &v[i].event.ano );
            fscanf( f, "%d %d", &v[i].inicio.hora, &v[i].inicio.min );
            fscanf( f, "%d %d", &v[i].fim.hora, &v[i].fim.min );
            fscanf( f, " %[^\n]", &v[i].info );
            fscanf( f, " %[^\n]", &v[i].local );
        }
    }
    fclose( f );
    printf("%d registros foram carregados", *n );
}

void menu()
{
    printf("\nDigite o numero de qual opcao deseja:\n");
    printf("( 1 ) Cadastrar novo evento\n");
    printf("( 2 ) Mostrar todos os eventos da agenda\n");
    printf("( 3 ) Mostrar todos os eventos de uma data\n");
    printf("( 4 ) Mostrar todos os eventos com uma descricao\n");
    printf("( 5 ) Remover evento\n");
    printf("( 6 ) Sair do programa\n\n");
}

void mostrar_evento( Evento *x ) // Função auxiliar
{
    printf("Data do evento: %d/%d/%d\n", x->event.dia, x->event.mes, x->event.ano );
    printf("Horario de inicio: %dh%dmin\n", x->inicio.hora, x->inicio.min );
    printf("Horario de fim: %dh%dmin\n", x->fim.hora, x->fim.min );
    printf("Descricao: %s\n", x->info );
    printf("Local: %s\n\n", x->local );
}

void mostra_todos_eventos( Evento *x, int n )
{
    int i;
    for( i = 0; i < n; i++ )
    {
        printf("Evento %i\n", i+1);
        mostrar_evento( &x[i] );
    }
}

void mostra_evento_data( Evento *x, int n )
{
    int i, d, m, a;
    printf("Digite um dia: ");
    scanf("%i", &d );
    printf("Digite um mes: ");
    scanf("%i", &m );
    printf("Digite um ano: ");
    scanf("%i", &a);

    printf("Seus eventos em %i/%i/%i sao:\n\n", d, m, a );
    for( i = 0; i < n; i++ )
        if( a == x[i].event.ano && m == x[i].event.mes && d == x[i].event.dia )
            mostrar_evento( &x[i] );
}

void mostra_evento_desc( Evento *x, int n )
{
    int i;
    char ev[50];
    printf("Digite o nome do evento deseja procurar: ");
    scanf(" %[^\n]", ev );
    for( i = 0; i < n; i++ )
        if( strcmp( x[i].info, ev ) == 0 )
            mostrar_evento( &x[i] );
}

int insere_evento( Evento *x, int *n )
{
    //n++;
    //x = realloc( x, n );

    // INSERÇÃO DE DADOS.

    Evento conf;
    le_data( &conf.event );
    do // HORARIO DE INICIO DEVE SER MENOR QUE O HORARIO DE FIM.
    {
        le_horario( &conf.inicio );
        le_horario( &conf.fim );
        if( (conf.inicio.hora > conf.fim.hora && conf.inicio.hora != conf.fim.hora) || (conf.inicio.min > conf.fim.min && conf.inicio.hora == conf.fim.hora) )
            printf("\nHoraio de inicio deve anteceder o horario de fim!\n\n");
    } while ( (conf.inicio.hora > conf.fim.hora && conf.inicio.hora != conf.fim.hora) || (conf.inicio.min > conf.fim.min && conf.inicio.hora == conf.fim.hora) );
    
    printf("Digite a descricao do evento: ");
    scanf(" %[^\n]", conf.info );
    printf("Digite o local do evento: ");
    scanf(" %[^\n]", conf.local );
    int i;
    for( i = 0; i < *n; i++ ) // EVENTO NÃO PODE SER ACRESCENTADO SE INTERPOLAR COM OUTRO EVENTO JA EXISTENTE.
    {
        if( compara_datas( &x[i].event, &conf.event ) == 0 )
        {
            if( compara_horario( &x[i].inicio, &conf.inicio ) < 0 && compara_horario( &x[i].fim, &conf.inicio ) > 0 )
                return 1;
            if( compara_horario( &x[i].inicio, &conf.inicio ) > 0 && compara_horario( &x[i].inicio, &conf.fim ) < 0 )
                return 1;
            if( compara_horario( &x[i].inicio, &conf.fim ) < 0 && compara_horario( &x[i].fim, &conf.fim ) > 0 )
                return 1;
            if( compara_horario( &x[i].inicio, &conf.inicio) == 0 && compara_horario( &x[i].inicio, &conf.inicio ) == 0 )
            {
                if( strcmp( x[i].info, conf.info ) == 0 && strcmp( x[i].local, conf.local ) == 0 )
                {
                    printf("\n\nEsse evento ja existe\n\n");
                    return 1;
                }
                return 1;
            }
        }
    }

    // INCREMENTO NO NUMERO DE EVENTOS.

    (*n)++;
    x = realloc( x, sizeof(Evento) * *n );
    //printf("\n\nn: %i\n\n", *n);
    x[(*n)-1] = conf;

    //mostrar_evento( &x[0] );

    // ORDENAÇÃO DOS EVENTOS.

    if( *n > 1 )
        selection_sort_Evento( x, *n );

    return 0;
}

void le_horario( Horario *x )
{
    do
    {
        printf("Digite a hora do evento: ");
        scanf("%i", &x->hora );
    } while( x->hora > 23 || x->hora < 0);

    do
    {
        printf("Digite o min do evento: ");
        scanf("%i", &x->min );
    } while( x->min > 59 || x->min < 0);
}

int compara_horario( Horario *a, Horario *b )
{
    if( a->hora != b->hora )
        return a->hora - b->hora;
    return a->min - b->min;
}

void selection_sort_Evento( Evento *x, int k )
{
	int i;
	for( i = 0 ; i < k-1 ; i++ )
    {
		int i_menor = i , j;
		for( j = i+1 ; j < k ; j++ )
        {
			if( compara_datas( &x[j].event, &x[i_menor].event ) < 0 )
				i_menor = j;
            else if( compara_datas( &x[j].event, &x[i_menor].event ) == 0 )
                if( compara_horario( &x[j].inicio, &x[i_menor].inicio ) < 0 )
                    i_menor = j;
		}
		Evento aux = x[i];
		x[i] = x[i_menor];
		x[i_menor] = aux;
	}
}

void rm_evento( Evento *x, int *n, int rmv )
{
    int i, aux;
    for( i = 0; i < rmv; i++ );
    aux = i;
    i++;
    while ( i < *n )
    {
        x[aux] = x[i];
        i++;
        aux++;
    }
    x = realloc( x, aux * sizeof(Evento) );
    (*n)--;
}

void salva_cadastro( Evento *x, int n , char *nome_arq )
{
	FILE *f = fopen( nome_arq , "wt" );
	if( f == NULL )
    {
		printf("Erro no arquivo da saida!\n");
		return;
	}
	fprintf( f, "%d\n", n );
	int i;
	for( i = 0 ; i < n ; i++ ){
		fprintf( f, "%d %d %d", x[i].event.dia, x[i].event.mes, x[i].event.ano );
        fprintf( f, "%d %d", x[i].inicio.hora, x[i].inicio.min );
        fprintf( f, "%d %d", x[i].fim.hora, x[i].fim.min );
		fprintf( f, "%s\n", x[i].info );
		fprintf( f, "%s\n", x[i].local );
	}
	fclose( f ); // Fundamental!	
}