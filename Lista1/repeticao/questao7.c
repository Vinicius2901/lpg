#include <stdio.h>

int main()
{
    int n, x, y, i, aux = 0, simpares = 0, j;

    printf("Digite o numero de casos que deseja: ");
    scanf("%i", &n);

    for (j = 1; j <= n; j++)
    {
        printf("Digite dois numeros inteiros: ");
        scanf("%i%i", &x,&y);
        
        if (x > y)
        {
            aux = y;
            y = x;
            x = aux;
        }
        if (x == y || x == y-1 || (x == y-2 && x % 2 != 0))
        {
            printf("\nCaso %i : %i\n\n", j, simpares);
        }
        else
        {
            if (x % 2 == 0)
            {
                i = x+1;
            }
            else
            {
                i = x+2;
            }
            while (i < y)
            {
                simpares += i;
                i += 2;
            }
            printf("\nCaso %i : %i\n\n", j, simpares);
        }
        simpares = 0;
    }
    return 0;
}