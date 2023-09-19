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
            x[i][j] = rand() % 10000;
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
    return 0;
}
