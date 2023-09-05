#include <stdio.h>


int tipo_triangulo(float x, float y, float z);

int main()
{
    float a, b, c;
    printf("Digite o tamanho dos tres lados: ");
    scanf("%f%f%f", &a, &b, &c);
    if (tipo_triangulo(a, b, c) == 0)
    {
        printf("Nao ha triangulo\n");
    }
    else if (tipo_triangulo(a, b, c) == 1)
    {
        printf("Equilatero");
    }
    else if (tipo_triangulo(a, b, c) == 2)
    {
        printf("Escaleno\n");
    }
    else
    {
        printf("Isosceles\n");
    }
}

int tipo_triangulo(float x, float y, float z)
{
    if (x >= y + z || y >= x + z || z >= x + y)
    {
        return 0;
    }
    else if (x == y && x == z)
    {
        return 1;
    }
    else if (x != y && x != z && y != z)
    {
        return 2;
    }
    else
    {
        return 3;
    }
}