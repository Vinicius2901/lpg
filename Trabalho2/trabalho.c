#include "trabalho.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void carrega_registro( Evento *v, int n, char *nome_arq )
{
    int i;
    FILE *f = fopen( nome_arq, "rt");
    if( f == NULL )
    {
        printf("O arquivo ainda nao existe");
    }
    else
    {
        fscanf( f, "%d", &n );
        v = malloc( sizeof(Evento) * n );
        for( i = 0; i < n; i++ )
        {
            fscanf( f, "%d", &v[i].event.dia );
            fscanf( f, "%d", &v[i].event.mes );
            fscanf( f, "%d", &v[i].event.ano );
            fscanf( f, "%d", &v[i].inicio.hora );
            fscanf( f, "%d", &v[i].inicio.min );
            fscanf( f, "%d", &v[i].fim.hora );
            fscanf( f, "%d", &v[i].fim.min );
            fscanf( f, "%d", &v[i].info );
            fscanf( f, "%d", &v[i].local );
        }
    }
    fclose( f );
    printf("%d registros foram carregados", n );
}

void menu()
{
    printf("Digite o numero de qual opcao deseja:\n");
    printf("( 1 ) Cadastrar novo evento\n");
    printf("( 2 ) Mostrar todos os eventos da agenda\n");
    printf("( 3 ) Mostrar todos os eventos de uma data\n");
    printf("( 4 ) Mostrar todos os eventos com uma descricao\n");
    printf("( 5 ) Remover evento\n");
    printf("( 6 ) Sair do programa");
}

void mostrar_evento( Evento *x )
{
    printf("Data do evento: %d/%d/%d\n", x->event.dia, x->event.mes, x->event.mes );
    printf("Horario: %d\n", x->inicio.hora, x->inicio.min );
    printf("Descricao: %s\n", x->info );
    printf("Local: %s\n\n", x->local );
}

void mostra_todos_eventos( Evento *x, int n )
{
    int i;
    for( i = 0; i < n; i++ )
        mostrar_evento( &x[i] );
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
    scanf("%[^\n]", ev );
    for( i = 0; i < n; i++ )
        if( strcmp( x[i].info, ev ) )
            mostrar_evento( &x[i] );
}

int insere_evento( Evento *x, int n )
{
    //n++;
    //x = realloc( x, n );
    Evento conf;
    le_data( &conf.event );
    le_horario( &conf.inicio );
    le_horario( &conf.fim );
    int i;
    for( i = 0; i < n; i++ )
    {
        if( compara_datas( &x[i].event, &conf.event ) == 0 )
        {
            if( compara_horario( &x[i].inicio, &conf.inicio ) < 0 && compara_horario( &x[i].fim, &conf.inicio ) > 0 )
                return 1;
            if( compara_horario( &x[i].inicio, &conf.inicio ) > 0 && compara_horario( &x[i].inicio, &conf.fim ) < 0 )
                return 1;
            if( compara_horario( &x[i].inicio, &conf.inicio ) > 0 && compara_horario( &x[i].fim, &conf.fim ) > 0 )
                return 1;
        }
    }

}

void le_horario( Horario *x )
{
    do
    {
        printf("Digite a hora do evento: ");
        scanf("%i", &x->hora );
    } while( x->hora > 24 || x->hora < 0);

    do
    {
        printf("Digite o min do evento: ");
        scanf("%i", &x->min );
    } while( x->min > 60 || x->min < 0);
}

int compara_horario( Horario *a, Horario *b )
{
    if( a->hora != b->hora )
        return a->hora - b->hora;
    return a->min - b->min;
}