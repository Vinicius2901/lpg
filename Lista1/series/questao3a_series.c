#include <stdio.h>

int main()
{
    int i, count = 1, k;

    printf("Digite a quantidade de termos: ");
    scanf("%i", &k);

    float termo = 0;

    for (i = 1; i <= k; i++)
    {
        if (i % 2 == 1)
        {
            termo += 4.0/count;
        }
        else
        {
            termo -= 4.0/count;
        }
        printf("%i : %.6f\n", i, termo);
        count += 2;
    }
    return 0;
}