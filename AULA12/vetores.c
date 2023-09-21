#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vetores.h"

void mostra_vetor(int x[]/*o vetor é um ponteiro*/, int k, char nome[])
{
    int i;
    printf("%s", nome);
    for (i = 0; i < k; i++)
    {
        printf("%i ", x[i]);
    }
    printf("\n");
}

void mostra_vetor_2(int x[]/*o vetor é um ponteiro*/, int k, char nome[])
{
    int i;
    printf("%s", nome);
    for (i = 0; i < k; i++)
    {
        printf("%i : %i\n", i, x[i]);
    }
    printf("\n");
}

void selecion_sort(int x[], int k)
{
    int i, j;
    for (i = 0; i <k-1; i++)
    {
        int i_menor = i;
        for(j = i+1; j < k; j++)
        {
            if(x[j] < x[i_menor])
            {
                i_menor = j;
            }
        }
        int aux = x[i];
        x[i] = x[i_menor];
        x[i_menor] = aux;
    }
}

void bubble_sort(int x[], int k)
{
    int trocou, i;
    do
    {
        trocou = 0;

        for (i = 0; i < k-1; i++)
        {
            if(x[i] > x[i+1])
            {
                int aux = x[i];
                x[i] = x[i+1];
                x[i+1] = aux;
                trocou = 1;
            }
        }
    }
    while (trocou);
}

void gera_valores_matriz (int lin, int col, int x[lin][col])
{
    int i, j;
    for(i = 0; i < lin; i++)
    {
        for(j = 0; j < col; j++)
        {
            x[i][j] = rand() % 10;
        }
    }
}

void mostra_matriz (int lin, int col, int x[lin][col])
{
    int i, j;
    for(i = 0; i < lin; i++)
    {
        for(j = 0; j < col; j++)
        {
            printf("%d\t", x[i][j]); //  \t funciona como tabulação e seria o "TAB", para deixar alinhado.
        }
        printf("\n");
    }
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

void diagonal_principal (int dim, int x[dim][dim])
{
    int i, j;
    printf("Diagonal principal: ");
    /*for(i = 0; i < dim; i++)
    {
        for (j = 0; j < dim; j++)
        {
            if (i == j)
            {
                printf("%d ", x[i][j]);
            }
        }
    }*/
    for (i = 0; i < dim; i++)
    {
        printf("%d ", x[i][i]);
    }
    printf("\n");
}

void diagonal_secundaria (int dim, int x[dim][dim])
{
    int i, j;
    printf("Diagonal secundaria: ");
    /*for(i = 0; i < dim; i++)
    {
        for (j = 0; j < dim; j++)
        {
            if (i + j == dim - 1) // j = dim - 1 - i
            {
                printf("%d ", x[i][j]);
            }
        }
    }*/
    for (i = 0; i < dim; i++)
    {
        printf("%d ", x[i][dim-1-i]);
    }
    printf("\n");
}

float media_pares( int lin, int col, int x[lin][col])
{
    int i, j, soma = 0, cont = 0;
    for( i = 0; i < lin; i++ )
    {
        for( j = 0; j < col; j++)
        {
            if( x[i][j] % 2 == 0)
            {
                soma += x[i][j];
                cont++;
            }
        }
    }
    if( cont == 0) // Gambiarra para não dar erro!
        return 0;

    return (float)soma / cont;
}

void gera_transposta( int lin, int col, int m[lin][col], int t[col][lin] )
{
    int i, j;
    for( i = 0; i < lin; i++ )
    {
        for( j = 0; j < col; j++)
        {
            t[j][i] = m[i][j];
        }
    }
}

void soma_matrizes( int lin, int col, int m1[lin][col], int m2[lin][col], int m3[lin][col] )
{
    int i, j;
    for( i = 0; i < lin; i++)
        for( j = 0; j < col; j++)
            m3[i][j] = m1[i][j] + m2[i][j];
}

void multi_matrizes( int la, int ca, int a[la][ca], int lb, int cb, int b[lb][cb], int c[la][cb] )
{
    int i, j, k;
    for( i = 0; i < la; i++ )
        for( j = 0; j < cb; j++ )
        {
            int soma = 0;
            for( k = 0; k < ca; k++ )
                soma += a[i][k] * b[k][j];
            c[i][j] = soma;
        }
}