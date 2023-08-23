#include <stdio.h>

int main()
{
    float x, y;
    printf("Digite dois pontos cartesianos: ");
    scanf("%f%f", &x, &y);
    if (x == 0)
    {
        if (y == 0)
        {
            printf("Origem\n");
        }
        else
        {
            printf("Eixo X\n");
        }
    }
    else
    {
        if (y == 0)
        {
            printf("Eixo Y");
        }
        else if (x > 0)
        {
            if (y > 0)
            {
                printf("Q1\n");
            }
            else
            {
                printf("Q4\n");
            }
        }
        else
        {
            if (y > 0)
            {
                printf("Q2\n");
            }
            else
            {
                printf("Q3\n");
            }
        }
    }

    return 0;
}