#include <stdio.h>
#define TAM 10

void max_min(int vet[], int tam, int *pMin, int *pMax);

int main()
{
    int v[TAM] = {-1, 5, 16, -79, 21, 3, 45, 6, 5, 7};
    int min, max;

    max_min( v, TAM, &min, &max );

    printf("Menor valor do vetor: %i\n", min );
    printf("Maior valor do vetor: %i\n", max );

    return 0;
}

void max_min(int vet[], int tam, int *pMin, int *pMax)
{
    int i;
    *pMin = vet[0];
    *pMax = vet[0];

    for( i = 0; i < tam; i++ )
    {
        if( vet[i] < *pMin )
            *pMin = vet[i];
        if( vet[i] > *pMax )
            *pMax = vet[i];
    }
}