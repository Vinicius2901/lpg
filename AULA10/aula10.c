#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vetores.h"

#define MAX 1000

int binary_search (int v[], int n, int key);
void gera_valores (int x[], int k, int limite);
void gera_valores_ordem(int x[], int k, int limite);
void mostra_vetor(int x[]/*o vetor é um ponteiro*/, int k, char nome[]);
void mostra_vetor_2(int x[]/*o vetor é um ponteiro*/, int k, char nome[]);
void selection_sort(int x[], int k);
void bubble_sort(int x[], int k);


int main()
{
    int v[MAX];

    gera_valores_ordem (v, MAX, 10);
    mostra_vetor_2 (v, MAX, "Vetor: ");

    int key;
    printf("Digite o valor a ser buscado: ");
    scanf("%d", &key);

    int indice = binary_search(v, MAX, key);
    if(indice == -1)
        printf("Não encontrado!\n");
    else
        printf("Encontrado em %d.\n", indice);
}

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
    for (i = 0; i < MAX; i++)
    {
        x[i] = rand() % limite + 1; // Gera um número entre 1 e o limite.
    }
}

void gera_valores_ordem(int x[], int k, int limite)
{
    int i;
    srand(time(0)); // Define a "semente" do rand() como sendo a hora atual.
    x[0] = rand () % limite + 1; // Gera o 1o valor
    for (i = 1; i < MAX; i++)
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
    for (i = 0; i < MAX-1; i++)
    {
        int i_menor = i;
        for(j = i+1; j < MAX; j++)
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

        for (i = 0; i < MAX-1; i++)
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