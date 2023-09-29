#include <stdio.h>

void fibonacci( int v[], int n );
void mostra_vetor( int v[], int n );

int main()
{
    int n;
    printf("Digite a quantidade de termos que deseja no Fibonacci: ");
    scanf("%i", &n);

    int v[n];
    fibonacci( v, n );

    printf("A sequencia ate %i eh: ", n);
    mostra_vetor( v, n );
    
    return 0;
}

void fibonacci( int v[], int n )
{
    int i;
    v[0] = 1;
    v[1] = 1;
    for( i = 2; i < n; i++ )
        v[i] = v[i-1] + v[i-2];
}

void mostra_vetor( int v[], int n )
{
    int i;
    for( i = 0; i < n; i++ )
        printf("%i ", v[i]);
    printf("\n");
}