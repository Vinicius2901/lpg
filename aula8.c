#include <stdio.h>

// Retomando a torre de Hanoi da aula passada - foto no celular sobre a explicação da recursão.

/*
void hanoi ( int n, char origem, char destino, char aux);

int main()
{
    int n;
    printf("Quantos discos? ");
    scanf("%i", &n);
    hanoi (n, 'A', 'B', 'C');

    return 0;
}


void hanoi ( int n, char origem, char destino, char aux)
{
    if (n == 1)
    {
        printf("Mova disco 1 de %c para %c.\n", origem, destino);
    }
    else
    {
        hanoi (n-1, origem, aux, destino);
        printf("Mova o disco %i de %c para %c.\n", n, origem, destino);
        hanoi (n-1, aux, destino, origem);
    }
}*/



// Vetores

/*
    - Vetores são variáveis multivaloradas;
    - Variáveis Homogêneas -> Todos os valores tem mesmo tipo (int, float, char...);
    - Vetor é sempre um bloco único na memória e tem seus valores adjacentes entre si;
    - Capacidade colocada na declaração;
    - Índices variam de 0 até a capacidade-1; -> [0,capacidade-1]
    - Índices permitem acesso as posições do vetor;
    - Valores dos índices são armazenados em uma variável, percorrendo de 0 até capacidade-1
    - Variável para índice DEVE ser int ou long long int; 
*/

// Exemplo de codigo com vetor: (entregará lixo de memória a partir do estouro da capacidade)

/*int main()
{
    int v[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20}; // Vetor de capacidade 10 já inicializado;
    int i;
    printf("%p\n\n", v); // printar o endereço de memória
    for( i = 0; i < 10; i++)
    {
        printf("(%p) %i : %i\n", &v[i], i, v[i]); // Printar o endereço de memória de cada elemento do vetor, seu índice e o elemento.
    }
    return 0;
}*/

/* Continuação:

    - Strings podem ser inicializadas de duas formas:
      -> char nome1[] = {'M', 'a', 'r', 'i', 'a'};
      -> char nome2[] = "Maria";

    
*/

// Determinar o menor valor de um vetor:

/*int main() -> criando variável para armazenar o menor numero
{
    int v[8] = {4, 12, 8, 25, 2, 11, -1, 9};
    int n = 8, i;
    int menor = v[0];
    int i_menor = 0;
    for (i = 0; i < 8; i++)
    {
        if (v[i] < menor)
        {
            menor = v[i];
            i_menor = i;
        }
    }
    printf("Menor: %i no indice %i\n", menor, i_menor);
    return 0;
}*/

/*int main() -> usando apenas o index
{
    int v[8] = {4, 12, 8, 25, 2, 11, -1, 9};
    int n = 8, i;
    //int menor = v[0];
    int i_menor = 0;
    for (i = 0; i < 8; i++)
    {
        if (v[i] < v[i_menor])
        {
            //menor = v[i];
            i_menor = i;
        }
    }
    printf("Menor: %i no indice %i\n", v[i_menor], i_menor);
    return 0;
}*/

// Ordenar os valores por selection sort

int main()
{
    int v[8] = {4, 12, 8, 25, 2, 11, -1, 9};
    int n = 8, i;
    //int menor = v[0];
    for (i = 0; i < n; i++)
    {
        int i_menor = i, j;
        for (j = i+1; j < n; j++)
        {
            if (v[j] < v[i_menor])
            {
                //menor = v[i];
                i_menor = j;
            }
        }
        int aux = v[i];
        v[i] = v[i_menor];
        v[i_menor] = aux;
    }
    for (i = 0; i < n; i++)
    {
        printf("%i : %i\n", i+1, v[i]);
    }
    return 0;
}
