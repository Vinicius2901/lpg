#include <stdio.h>
#include <stdlib.h>

void max_vetor(float vet[], int tam, float *pMax, int *pIndice);

int main()
{
    int tam, i;
    printf("Digite o tamanho do vetor: ");
    scanf("%i", &tam );
    float v[tam];
    printf("Vetor: ");
    for( i = 0; i < tam; i++ )
    {
        v[i] = (rand() % 100 + 1) / 10;
        printf("%.2f ", v[i] );
    }

    float max;
    int indice;
    max_vetor( v, tam, &max, &indice );
    
    printf("\nMaior valor: %.2f\n", max);
    printf("Indice: %i", indice );
}

void max_vetor(float vet[], int tam, float *pMax, int *pIndice)
{
    int i;
    *pMax = vet[0];
    *pIndice = 0;
    for( i = 0; i < tam; i++ )
    {
        if( *pMax < vet[i] )
        {
            *pMax = vet[i];
            *pIndice = i;
        }
    }
}