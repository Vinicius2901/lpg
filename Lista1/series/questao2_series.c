#include <stdio.h>

int main()
{
    int i, k;

    printf("Digite o numero de termos: ");
    scanf("%i", &k);

    float termo = 0;
    for (i = 1; i <= k; i++)
    {
        if (i % 2 == 1)
        {
            termo += 1.0/i;
        }
        else
        {
            termo -= 1.0/i;
        }
        printf("%i : %.6f\n", i, termo);
    }
    return 0;
}