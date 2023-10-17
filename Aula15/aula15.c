#include <stdio.h>
#include <math.h>

// PONTEIROS
/*
    - Ponteiros são variáveis que guardam um endereço de memória;
    - Um ponteiro pode apontar para: uma variável, outro ponteiro, uma área de memória alocada dinamicamente, uma função;
    - Tem o endereço e o tipo de dados;
    - Operadores & e *;
    - "int *p = a" -> "'p' aponta para 'a', porque 'p' tem o endereço de 'a'"
*/

void fat_v2( int x, int *p );
void horario( int x, int *h, int *m, int *s );
void raiz( int a, int b, int c, int *x1, int *x2 );

int main()
{
    int a = 5;
    int *p = &a; // Endereço de a.

    // Mostra valor da variável a.
    printf("A = %d\n", *p );

    // Mostra endereço da variável a.
    printf("Endereco de A = %d\n", p );
    
    // Mostra endereço da variável a (em hexa)
    printf("Endereco de A = %p\n", p );


    // Fatorial com ponteiro.
    int n, f;
    printf("\nDigite um numero: ");
    scanf("%i", &n);

    fat_v2( n, &f ); // Envia a variável n e o endereço de f.
    printf("Fatorial de %i eh %i\n", n, f);


    // Conversão segundo - hora/min/s.
    int seg;
    printf("\nDigite o tempo em segundos: ");
    scanf("%i", &seg);

    int h, m, s;
    horario( seg, &h, &m, &s );
    printf("%is sao %ih %imin %is", seg, h, m, s);

    // Raizes da equação:
    int A, B, C, x1, x2;
    printf("\nDigite os coeficientes da equacao de segundo grau: ");
    scanf("%i%i%i", &A, &B, &C);

    raiz( A, B, C, &x1, &x2 );

    if( sqrt(pow(B, 2) - 4*A*C) > 0 && x1 == x2 )
        printf("A raiz de %ix^2 + %ix + %i eh %i\n", A, B, C, x1);
    else if( sqrt(pow(B, 2) - 4*A*C) > 0 && x1 != x2)
        printf("As raizes de %ix^2 + %ix + %i sao %i e %i\n", A, B, C, x1, x2);
    return 0;
}


void fat_v2( int x, int *p )
{
    *p = 1;
    while ( x > 0 )
    {
        *p *= x;
        x--;
    }
}

void horario( int x, int *h, int *m, int *s )
{
    *h = x / 3600;
    int resto = x % 3600;
    *m = resto / 60;
    *s = resto % 60;
}

void raiz( int a, int b, int c, int *x1, int *x2 )
{
    if( sqrt(pow(b, 2) - 4*a*c) >= 0 )
    {
        *x1 = (-b + sqrt(pow(b, 2) - 4*a*c))/(2*a);
        *x2 = (-b - sqrt(pow(b, 2) - 4*a*c))/(2*a);
    }
    else
        printf("Nao ha raiz.");
}