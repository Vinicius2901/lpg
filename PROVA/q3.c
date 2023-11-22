#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostra_vetores( int n_listas, int *p_qtdValores, int **p_listas );

int main()
{
    int **p;
    int n;
    printf("Digite a quantidade de vetores: ");
    scanf("%i", &n );
    p = malloc( sizeof( int* ) * n );
    int *qtd = malloc( sizeof( int ) * n );
    int i, j, nnumeros;
    printf("Digite a quantidade de termos dos vetores:\n");
    for( i = 0; i < n; i++ )
    {
        printf("Vetor %i: ", i+1 );
        scanf("%i", &nnumeros);
        qtd[i] = nnumeros;
        p[i] = malloc( sizeof( int ) * nnumeros );
    }
    for( i = 0; i < n; i++ )
        for( j = 0; j < qtd[i]; j++ )
            p[i][j] = rand() % 100 + 1;
            
    mostra_vetores( n, qtd, p );
    
    free( qtd );
    for( i = 0; i < n; i++ )
        free( p[i] );
        
    free( p );
    
    return 0;
    
}

void mostra_vetores( int n_listas, int *p_qtdValores, int **p_listas )
{
    int i, j;
    for( i = 0; i < n_listas; i++ )
    {
        printf("Vetor %i: ", i+1 );
        for( j = 0; j < p_qtdValores[i]; j++ )
            printf("%i\t", p_listas[i][j] );
        printf("\n");
    }
}
