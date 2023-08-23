#include <stdio.h>

int main()
{
    int i, k;
    float termo = 0;

    printf("Quantos termos gostaria na serie? ");
    scanf("%i", &k);

    for(i = 1; i <= k; i++)
    {
        termo += 1.0/i;
        printf("%i : %.6f\n", i, termo);
    }
    return 0;
}