#include "trabalho.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    Evento *v = NULL; // Declarção do vetor de eventos.
    int n = 0;
    int i, opt, conf;

    carrega_registro( v, &n, "eventos.txt" ); // Carrega os registros dos eventos já registrados antes da execução do código.

    /*FILE *f = fopen( "eventos.txt", "rt");
    if( f == NULL )
    {
        printf("O arquivo ainda nao existe\n");
    }
    else
    {
        fscanf( f, "%d", &n );
        v = malloc( sizeof(Evento) * n );
        for( i = 0; i < n; i++ )
        {
            fscanf( f, "%d %d %d", &v[i].event.dia, &v[i].event.mes, &v[i].event.ano );
            fscanf( f, "%d %d", &v[i].inicio.hora, &v[i].inicio.min );
            fscanf( f, "%d %d", &v[i].fim.hora, &v[i].fim.min );
            fscanf( f, "%[^\n]", &v[i].info );
            fscanf( f, "%[^\n]", &v[i].local );
        }
    }
    fclose( f );
    printf("%d registros foram carregados", n );*/

    v = malloc( sizeof(Evento) * n );
    /*n = 1;
    v[0].event.ano = 2023;
    v[0].event.mes = 12;
    v[0].event.dia = 25;
    v[0].inicio.hora = 0;
    v[0].inicio.min = 0;
    v[0].fim.hora = 1;
    v[0].fim.min = 0;
    strcpy( v[0].info, "Natal" );
    strcpy( v[0].local, "Casa" );*/

    do
    {
        menu();
        scanf("%i", &opt );
        switch ( opt )
        {
        case 1:
            conf = insere_evento( v, &n );
            if( conf )
                printf("\nO evento sobrepoe outro evento ja existente, tente novamente\n");
            printf("\n\n%i\n\n", n);
            break;
        case 2:
            if( n == 0 )
            {
                printf("Evento nao encontrado");
                break;
            }
            mostra_todos_eventos( v, n );
            break;
        case 3:
            if( n == 0 )
            {
                printf("Evento nao encontrado");
                break;
            }
            mostra_evento_data( v, n );
            break;
        case 4:
            if( n == 0 )
            {
                printf("Evento nao encontrado");
                break;
            }
            mostra_evento_desc( v, n );
            break;
        case 5:
            if( n == 0 )
            {
                printf("Nao ha eventos para excluir");
                break;
            }
            printf("Escolha o numero do evento que deseja excluir: ");
            scanf("%i", &conf );
            rm_evento( v, &n, conf-1 );
            break;
        default:
            break;
        }
    } while ( opt != 6 );

    salva_cadastro( v, n, "eventos.txt" );

    free( v );

    return 0;
}