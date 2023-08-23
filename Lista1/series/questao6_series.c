#include <stdio.h>

int main()
{
    float x;
    int n, i, j, termos, aux = 1;
    printf("Digite um angulo em radianos: ");
    scanf("%f", &x);
    printf("Digite o numero de termos: ");
    scanf("%i", &termos);

    float seno = 0;
    for (i = 1; i <= termos; i++)
    {
        float seno1 = 1;
        for (j = 1; j <= aux; j++)
        {
            seno1 *= x/j;
        }
        if (i % 2 == 1)
        {
            seno += seno1;
        }
        else
        {
            seno -= seno1;
        }
        aux += 2;
    }
    printf("O seno de %.2f eh %f", x, seno);
    return 0;
}