#include <stdio.h>

int main()
{
    int i, k, j, count = 0, ntermo = 1;
    printf("Digite o numero de termos: ");
    scanf("%i", &k);

    float termo = 3;

    printf("%i : %.6f\n", ntermo, termo);
    for (i = 2; i <= k; i++)
    {
        for (j = 2*i; j >= i && count != 3; j--)
        {
            ntermo *= j;
            count++;
        }
        if (i % 2 == 0)
        {
            termo += 4.0/ntermo;
        }
        else
        {
            termo -= 4.0/ntermo;
        }
        printf("%i : %.6f\n", i, termo);
        ntermo = 1;
        count = 0;
    }
    return 0;
}