#include <stdio.h>
#include <math.h>

int nprimos (int div, int k, int n);

int main()
{
    int k, n, div = 2, i;

    printf("Digite um numero e quantos primos apos ele deseja: ");
    scanf("%i%i", &k, &n);

    int resultado = k;

    printf("Aqui estao os %i primos acima de %i:\n", n, k);
    for (i = 1; i <= n; i++)
    {
        resultado = nprimos (div, resultado+1, n);
        printf("%i : %i\n", i, resultado);
    }
    return 0;
}

int nprimos (int div, int k, int n)
{
    if (div > sqrt(k) && k != 1 && k != 0)
    {
        return k;
    }
    if (k % div == 0 || k == 1 || k == -1)
    {
        return nprimos(2, k+1, n);
    }
    if (k % div != 0)
    {
        return nprimos(div+1, k, n);
    }

}