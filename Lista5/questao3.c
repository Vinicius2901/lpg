#include <stdio.h>

void calcula_circulo(float raio, float *pPerimetro, float *pArea);

int main()
{
    float raio, perimetro, area;
    printf("Digite o raio do circulo: ");
    scanf("%f", &raio );

    calcula_circulo( raio, &perimetro, &area );

    printf("O perimetro do circulo de raio %.2f eh: %.2f\n", raio, perimetro );
    printf("A area do circulo de raio %.2f eh: %.2f\n", raio, area );

    return 0;
}

void calcula_circulo(float raio, float *pPerimetro, float *pArea)
{
    *pPerimetro = 2 * 3.14 * raio;
    *pArea = 3.14 * raio * raio;
}