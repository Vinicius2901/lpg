#include <stdio.h>

void gera_vetor_input_int( int x[], int n );
void busca_todos(int v[], int n, int chave, int indices[]);
void mostra_vetor( int v[], int n );

int main()
{
    int n, chave;
    printf("Digite a capacidade do vetor: ");
    scanf("%i", &n);

    printf("Digite a chave que deseja: ");
    scanf("%i", &chave);

    int v[n], ind[n];
    gera_vetor_input_int( v, n );
    
    busca_todos(v, n, chave, ind);
    printf("A chave encontra-se nas posicoes: ");
    mostra_vetor( ind, n );

}

void gera_vetor_input_int( int x[], int n )
{
    int i;
    printf("Digite os termos do vetor: ");
    for( i = 0; i < n; i++ )
        scanf("%i", &x[i]);
}

void busca_todos(int v[], int n, int chave, int indices[])
{
    int i, count = 0;
    for( i = 0; i < n; i++ )
    {
        indices[i] = -1;
        if( chave == v[i] )
        {
            indices[count] = i;
            count++;
        }
    }
}

void mostra_vetor( int v[], int n )
{
    int i;
    printf("indices = { ");
    for( i = 0; i < n; i++ )
        printf("%i ", v[i]);
    printf("}\n");
}