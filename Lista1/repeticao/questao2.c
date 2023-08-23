#include <stdio.h>
#include <math.h>

int main()
{
    float A, B, C;
    float maior, medio, menor;
    printf("Digite os lados do triangulo: ");
    scanf("%f%f%f", &A, &B, &C);

    if (A > B && A > C)
    {
        maior = A;
        if (B >= C)
        {
            medio = B;
            menor = C;
        }
        else if (C >= B)
        {
            medio = C;
            menor = B;
        }
    }
    else if (B > A && B > C)
    {
        maior = B;
        if (A >= C)
        {
            medio = A;
            menor = C;
        }
        else if (C >= A)
        {
            medio = C;
            menor = A;
        }
    }
    else if (C > A && C > B)
    {
        maior = C;
        if (A >= B)
        {
            medio = A;
            menor = B;
        }
        else if (B >= A)
        {
            medio = B;
            menor = A;
        }
    }
    else if (A == B && A == C)
    {
        maior = A;
        medio = B;
        menor = C;
    }

    A = maior;
    B = medio;
    C = menor;

    if (A >= B + C)
    {
        printf("NAO FORMA TRIANGULO\n");
        return 0;
    }
    if (pow(A,2) == pow(B,2) + pow(C,2))
    {
        printf("TRIANGULO RETANGULO\n");
    }
    if (pow(A,2) > pow(B,2) + pow(C,2))
    {
        printf("TRIANGULO OBTUSANGULO\n");
    }
    if (pow(A,2) < pow(B,2) + pow(C,2))
    {
        printf("TRIANGULO ACUTANGULO\n");
    }
    if (A == B && B == C)
    {
        printf("TRIANGULO EQUILATERO\n");
    }
    else if (A == B || A == C || B == C)
    {
        printf("TRIANGULO ISOSCELES\n");
    }
    else
    {
        printf("TRIANGULO ESCALENO\n");
    }
    return 0;
}