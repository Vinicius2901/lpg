#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void min_matriz(float mat[3][4], float *pMin, int *pI, int *pJ);

int main()
{
    float mat[3][4];
    int i, j;
    float min;
    int linha, coluna;
    printf("Matriz:\n");
    srand(time(0));
    for( i = 0; i < 3; i++ )
    {
        for( j = 0; j < 4; j++)
        {
            mat[i][j] = rand() % 100 + 1;
            printf("%.2f\t", mat[i][j] );
        }
        printf("\n");
    }

    min_matriz( mat, &min, &linha, &coluna );

    printf("Menor numero da matriz: %.2f\n", min );
    printf("Linha: %i\n", linha );
    printf("Coluna: %i\n", coluna );
}

void min_matriz(float mat[3][4], float *pMin, int *pI, int *pJ)
{
    int i, j;
    *pMin = mat[0][0];
    *pI = 0;
    *pJ = 0;
    for( i = 0; i < 3; i++ )
        for( j = 0; j < 4; j++ )
            if( mat[i][j] < *pMin )
            {
                *pMin = mat[i][j];
                *pI = i;
                *pJ = j;
            }
}