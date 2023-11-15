#include <stdio.h>
#include <stdlib.h>

void imprime_vetor_int( int *v, int n );

int main()
{
    int tam;
    printf("Digite quantos numeros deseja armazenar: ");
    scanf("%i", &tam );
    int *v = malloc( sizeof(int) * tam);
    printf("Digite os elementos do vetor: ");
    int i;
    for( i = 0; i < tam; i++ )
    {
        scanf("%i", v+i );
    }
    int par = 0, impar = 0;
    int *vp = malloc( 0 );
    int *vi = malloc( 0 );
    for( i = 0; i < tam; i++ )
    {
        if( v[i] % 2 == 0 )
        {
            par++;
            vp = realloc( vp, par );
            vp[par-1] = v[i];
        }
        else
        {
            impar++;
            vi = realloc( vi, impar );
            vi[impar-1] = v[i];
        }
    }
    printf("Vetor original: ");
    imprime_vetor_int( v, tam );

    printf("Vetor par: ");
    imprime_vetor_int( vp, par );

    printf("Vetor impar: ");
    imprime_vetor_int( vi, impar );

    free( v );
    free( vp );
    free( vi );

    return 0;
}

void imprime_vetor_int( int *v, int n )
{
    int i;
    for( i = 0; i < n; i++ )
        printf("%i ", v[i] );
    printf("\n");
}