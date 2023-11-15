#include <stdio.h>

void inc_dec( float *p1, float *p2 );

int main()
{
    float a, b;
    printf("Digite dois numeros: ");
    scanf("%f%f", &a, &b);

    printf("A: %f\nB: %f\n", a, b);

    inc_dec( &a, &b );

    printf("\nOs numeros trocados sao: \n");
    printf("A: %f\nB: %f\n", a, b);

    return 0;
}

void inc_dec( float *p1, float *p2 )
{
    int aux = *p1;
    *p1 = *p2;
    *p2 = aux;
}
