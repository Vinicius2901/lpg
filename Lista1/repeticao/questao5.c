#include <stdio.h>

int main()
{
    int n, i;
    float x, y, z, mediap;

    printf("Digite quantos testes deseja fazer: ");
    scanf("%i", &n);

    printf("Digite os casos testes:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%f%f%f", &x, &y, &z);
        mediap = (x*2 + y*3 + z*5)/10;
        
        printf("%.1f\n", mediap);
    }
    return 0;
}