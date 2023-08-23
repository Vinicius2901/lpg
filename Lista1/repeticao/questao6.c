#include <stdio.h>

int main()
{
    int x, y, i, aux = 0, impares = 0;

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
        printf("%i\n", impares);
        return 0;
    }
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
        impares++;
        i += 2;
    }
    printf("%i\n", impares);
    return 0;
}