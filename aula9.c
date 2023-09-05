#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

//SelectionSort 1.0:

/*
int main()
{
    int vet[8] = {6, 9, 14, -3, 17, 0, 99, 16};
    int n = 8;
    int i, j;
    for (i = 0; i < n-1; i++)
    {
        int i_menor = i;
        for(j = i+1; j< n; j++)
        {
            if(vet[j] < vet[i_menor])
            {
                i_menor = j;
            }
        }
        int aux = vet[i];
        vet[i] = vet[i_menor];
        vet[i_menor] = aux;
    }

    for (i = 0; i < n; i++)
    {
        printf("%i : %i\n", i, vet[i])
    }
    return 0;
}
*/


//BubbleSort:

/*
int main()
{
    int v[8] = {6, 99, 14, -3, 17, 0, 9, 16};
    int n = 8;
    int i, trocou;
    
    do
    {
        trocou = 0;

        for (i = 0; i < n-1; i++)
        {
            if(v[i] > v[i+1])
            {
                int aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                trocou = 1;
            }
        }
    }
    while (trocou);
    for(i = 0; i < n; i++)
    {
        printf("%i : %i\n", i, v[i]);
    }
    return 0;
}
*/


// SelectionSort 2.0

/*
int main()
{
    int v[MAX];
    int i, j;
    srand(time(0)); // Define a "semente" do rand() como sendo a hora atual.
    for (i = 0; i < MAX; i++)
    {
        v[i] = rand() % 100 + 1; // Gera um número entre 1 e 100.
    }

    printf("Vetor original:\n");
    for (i = 0; i < MAX; i++)
    {
        printf("%d : %d\n", i, v[i]);
    }

    for (i = 0; i < MAX-1; i++)
    {
        int i_menor = i;
        for(j = i+1; j < MAX; j++)
        {
            if(v[j] < v[i_menor])
            {
                i_menor = j;
            }
        }
        int aux = v[i];
        v[i] = v[i_menor];
        v[i_menor] = aux;
    }
    printf("\nVetor ordenado:\n");

    for (i = 0; i < MAX; i++)
    {
        printf("%i : %i\n", i+1, v[i]);
    }

    return 0;
}
*/

// Codigo com funções:

void gera_valores(int x[], int k, int limite);
void mostra_vetor(int x[]/*o vetor é um ponteiro*/, int k, char nome[]);
void selection_sort(int x[], int k);
void bubble_sort(int x[], int k);

int main()
{
    int v[MAX];
    int i, j;

    gera_valores(v, MAX, 100);

    mostra_vetor(v, MAX, "Vetor original: ");

    bubble_sort(v, MAX);

    mostra_vetor(v, MAX, "\nVetor ordenado: ");

    return 0;
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
