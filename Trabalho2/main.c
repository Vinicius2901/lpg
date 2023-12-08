//  TRABALHO FEITO POR RAFAEL RIBEIRO KLUGE E VINÍCIUS GIROTI

#include "trabalho.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    Evento *v = NULL; // Declaração do vetor de eventos.
    int n = 0;
    int i, opt, conf, aux = 0;
    Data conf1;
    
    system("cls");
    carrega_registro( &v, &n, "eventos.txt" ); // Carrega os registros dos eventos já registrados antes da execução do código.

    do
    {
        if( aux )
            system("cls");
        menu();
        scanf("%i", &opt );
        switch ( opt )
        {
        case 1:
            conf = insere_evento( &v, &n );
            if( conf )
                printf("\nO evento sobrepoe outro evento ja existente, tente novamente\n");
            system("pause");
            break;
        case 2:
            if( n == 0 )
            {
                printf("\nAgenda vazia\n");
                break;
            }
            mostra_todos_eventos( v, n );
            system("pause");
            break;
        case 3:
            if( n == 0 )
            {
                printf("\nAgenda vazia\n");
                break;
            }
            le_data( &conf1 );
            conf = mostra_evento_data( v, n, conf1 );
            if( conf )
                printf("\nNao existem eventos nessa data\n");
            system("pause");
            break;
        case 4:
            if( n == 0 )
            {
                printf("\nAgenda vazia\n");
                break;
            }
            conf = mostra_evento_desc( v, n );
            if( conf )
                printf("\nNao existem eventos com essa descricao\n");
            system("pause");
            break;
        case 5:
            if( n == 0 )
            {
                printf("Agenda vazia\n");
                break;
            }
            printf("Sobre o evento que deseja remover:\n");
            conf = rm_evento( &v, &n );
            if( conf )
                printf("\nO evento que deseja remover nao existe\n");
            system("pause");
            break;
        default:
            break;
        }
        aux++;
    } while ( opt != 6 );

    salva_cadastro( v, n, "eventos.txt" );

    free( v );

    return 0;
}
