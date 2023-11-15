#include <stdio.h>
#include <stdlib.h>

int *uniao( int *v1, int n1, int *v2, int n2, int *p3 );
int busca_seq( int v[], int n, int key );

int main()
{
    int tam1, tam2;
    printf("Digite o tamanho do vetor 1: ");
    scanf("%i", &tam1);

    int *v1 = malloc( sizeof(int) * tam1 );

    int i;
    printf("Digite os elementos do conjunto 1: ");
    for( i = 0; i < tam1; i++ )
    {
        scanf("%i", v1+i );
        if( busca_seq( v1, i, v1[i]) )
        {
            printf("O numero ja existe no conjunto, digite novamente: ");
            i--;
        }
    }

    printf("Digite o tamanho do conjunto 2: ");
    scanf("%i", &tam2);

    int *v2 = malloc( sizeof(int) * tam2 );

    printf("Digite os elementos do vetor 2: ");
    for( i = 0; i < tam2; i++ )
    {
        scanf("%i", v2+i );
        if( busca_seq( v2, i, v2[i]) )
        {
            printf("O numero ja existe no conjunto, digite novamente: ");
            i--;
        }
    }

    int tamu = 0;

    int *pUniao = uniao( v1, tam1, v2, tam2, &tamu );

    printf("O tamanho da uniao eh: %i\n", tamu );
    printf("A uniao dos conjuntos eh: ");
    for( i = 0; i < tamu; i++ )
        printf("%i ", pUniao[i] );
    
    free( pUniao );
    
    return 0;
}

int busca_seq( int v[], int n, int key )
{
    int i;
    for( i = 0; i < n; i++ )
        if ( v[i] == key )
            return 1;
    return 0;
}


int *uniao( int *v1, int n1, int *v2, int n2, int *p3 )
{
    int i, j = 0;
    *p3 = n1;
    for( i = 0; i < n2; i++ )
    {
        if( busca_seq( v1, n1, v2[i]) == 0 )
            (*p3)++;
    }
    int *uniao = malloc( sizeof(int) * *p3 );
    for( i = 0; i < n1; i++ )
        uniao[i] = v1[i];
    while (i < *p3)
    {
        if( busca_seq( uniao, i, v2[j])  == 0 )
        {
            uniao[i] = v2[j];
            i++;
        }
        j++;
    }

    return uniao;
}