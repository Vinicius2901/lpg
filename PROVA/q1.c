#include <stdio.h>
#include <stdlib.h>

void max_matriz( float mat[5][5], float *pMax, int *pI, int *pJ );

int main()
{
    float m[5][5];
    int i, j;
    for( i = 0; i < 5; i++ )
        for( j = 0; j < 5; j++ )
            m[i][j] = rand() % 100 + 1;
     
    printf("Matriz:\n");        
    for( i = 0; i < 5; i++ )
    {
        for( j = 0; j < 5; j++ )
            printf("%.2f\t", m[i][j] );
        printf("\n");
    }
    
    float nm;
    int lm, cm;
    max_matriz( m, &nm, &lm, &cm );
    
    printf("O maior numero da matriz eh %f na linha %i e coluna %i", nm, lm, cm );
    
    return 0;
    
}

void max_matriz( float mat[5][5], float *pMax, int *pI, int *pJ )
{
    int i, j;
    *pMax = mat[0][0];
    *pI = 0;
    *pJ = 0;
    for( i = 0; i < 5; i++ )
        for( j = 0; j < 5; j++ )
            if( mat[i][j] > *pMax )
            {
                *pMax =  mat[i][j];
                *pI = i;
                *pJ = j;
            }
}
