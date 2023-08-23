#include <stdio.h>

int main()
{
    float x;
    int n, i, j, termos, aux = 2;
    printf("Digite um angulo em radianos: ");
    scanf("%f", &x);
    printf("Digite o numero de termos: ");
    scanf("%i", &termos);

    float cosseno = 1;
    for (i = 1; i <= termos; i++)
    {
        float cosseno1 = 1;
        for (j = 1; j <= aux; j++)
        {
             cosseno1 *= x/j;
        }
        if (i % 2 == 0)
        {
            cosseno += cosseno1;
        }
        else
        {
            cosseno -= cosseno1;
        }
        aux += 2;
    }
    printf("O seno de %.2f eh %f", x, cosseno);
    return 0;
}