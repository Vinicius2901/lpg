#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vetores.h"

int binary_search(int v[], int n, int key)
{
    int ini = 0, fim = n-1, meio;
    int cont = 0;

    do
    {
        cont++; // Conta a quantidade de iterações
        meio = ( ini + fim ) / 2;
        if(v[meio] == key)
        {
            printf("[Busca executada em %i iteracoes.]\n", cont);
            return meio; // Encontrado em meio!
        }
        if(v[meio] < key)
            ini = meio + 1;
        else
            fim = meio - 1;
    }   while(ini <= fim);

    return -1; // Não encontrado!
}

void gera_valores(int x[], int k, int limite)
{
    int i;
    srand(time(0)); // Define a "semente" do rand() como sendo a hora atual.
    for (i = 0; i < k; i++)
    {
        x[i] = rand() % limite + 1; // Gera um número entre 1 e o limite.
    }
}

void gera_valores_ordem(int x[], int k, int limite)
{
    int i;
    srand(time(0)); // Define a "semente" do rand() como sendo a hora atual.
    x[0] = rand () % limite + 1; // Gera o 1o valor
    for (i = 1; i < k; i++)
    {
        x[i] = x[i-1] + rand() % limite + 1; // Gera um número entre 1 e o limite.
    }
}

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
    for (i = 0; i < k-1; i++)
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
