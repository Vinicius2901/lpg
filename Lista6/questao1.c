#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float *clone( float *v, int n );

int main()
{
    int tam, i;
    printf("Digite o tamanho do vetor: ");
    scanf("%i", &tam);
    float v[tam];
    printf("Vetor: ");
    srand( time(0) ); // Iguala a "semente" do rand ao timer atual.
    for( i = 0; i < tam; i++ )
    {
        v[i] = (rand() % 100 + 1) / 10; // Da valor aos vetor.
        printf("%.2f ", v[i] );
    }

    float *pClone = clone( v, tam );

    printf("\nVetor Clone: ");
    for ( i = 0; i < tam; i++ )
        printf("%.2f ", pClone[i] );

    free( pClone );

    return 0;
}

float *clone( float *v, int n )
{
    int i;
    float *clone = malloc( sizeof(float) * n );
    for( i = 0; i < n; i++ )
        clone[i] = v[i];

    return clone;
}