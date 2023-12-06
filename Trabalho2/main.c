#include "trabalho.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    Evento *v = NULL; // Declarção do vetor de eventos.
    int n = 0;
    int i, opt, conf;

    carrega_registro( v, n, "eventos.txt" ); // Carrega os registros dos eventos já registrados antes da execução do código.

    do
    {
        menu();
        n = 1;
        v = malloc( sizeof(Evento) * n );
        v[0].event.ano = 2023;
        v[0].event.mes = 12;
        v[0].event.dia = 25;
        v[0].inicio.hora = 0;
        v[0].inicio.min = 10;
        v[0].fim.hora = 1;
        v[0].fim.min = 0;
        strcpy( v[0].info, "Natal" );
        strcpy( v[0].local, "Casa" );
        scanf("%i", &opt );
        switch ( opt )
        {
        case 1:
            conf = insere_evento( v, n );
            if( conf )
                printf("\nNao tem como inserir evento\n");
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
            break;
        case 6:
            break;
        
        default:
            break;
        }
    } while ( opt != 6 );
    
    return 0;
}
