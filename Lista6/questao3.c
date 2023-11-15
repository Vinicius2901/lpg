#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tam, i, count = 0;
    printf("Digite o tamanho do vetor: ");
    scanf("%i", &tam );

    float *v = malloc( sizeof(float) * tam );

    float soma = 0, media;

    printf("Digite os valores do vetor: ");
    for( i = 0; i < tam; i++ )
    {
        scanf("%f", v+i);
        soma += v[i];
    }
    float *maior = malloc( 0 );
    media = soma/tam;
    
    for( i = 0; i < tam; i++ )
        if( v[i] > media )
        {
            count++;
            maior = realloc( maior, count);
            maior[count-1] = v[i];
        }
    printf("Os numeros que superam a media sao: ");
    for( i = 0; i < count; i++ )
        printf("%i : %.2f\n", i, maior[i] );

    free( v );
    free( maior );
    return 0;
}