#include <stdio.h>

int fibo(int n);

int main()
{
    int n;
    printf("Quantos termos deseja? ");
    scanf("%i", &n);

    int resultado = fibo(n);

    printf("A resoposta eh: %i", resultado);

    return 0;
}

int fibo(int n)
{
    int a = 1, b = 1, termo = 1, i;
    for (i = 2; i < n; i++)
    {
        termo = a + b;
        a = b;
        b = termo;
    }
    return termo;
}