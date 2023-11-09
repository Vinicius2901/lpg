#include <stdio.h>

void inc_dec( int *p1, int *p2 );

int main()
{
    int a, b;
    printf("Digite dois numeros: ");
    scanf("%i%i", &a, &b);

    inc_dec( &a, &b );

    printf("Os numeros digitados incrementado e decrementado, respectivamente sao: %i, %i\n", a, b);

    return 0;
}

void inc_dec( int *p1, int *p2 )
{
    (*p1)++;
    (*p2)--;
}
