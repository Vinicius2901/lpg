#include <stdio.h>

float taylor_it(int n);
float taylor_rec(int n, int den, float termo1, float termo);

int main()
{
    int n;
    printf("Quantos termos deseja? ");
    scanf("%i", &n);
    
    float resultado = taylor_it(n);
    printf("Resultado iterativo: %f\n", resultado);
    
    float resultado2 = taylor_rec(n, 1, 1, 0);
    printf("Resultado recursivo: %f\n", resultado2);

    return 0;
}

float taylor_it (int n)
{
    int i;
    float termo = 1, termo1 = 1;
    for(i = 1; i <= n; i++)
    {
        termo1 *= 1.0/i;
        termo += termo1;
    }
    return termo;
}

float taylor_rec(int n, int den, float termo1, float termo) {
    if (n > 0)
    {
        return taylor_rec(n - 1, den + 1, termo1 * 1.0 / den, termo + termo1);
    } 
    return termo;
}
