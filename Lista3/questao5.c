#include <stdio.h>

void gera_vetor_input_int( int x[], int n );
int busca_seq_rec(int v[], int n, int chave);

int main()
{
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%i", &n);

    int v[n];
    gera_vetor_input_int( v, n );

    int chave;
    printf("Digite qual valor deseja encontrar: ");
    scanf("%i", &chave);

    int resultado = busca_seq_rec( v, n-1, chave );
    if (resultado != -1)
        printf("%i encontra-se no indice %i\n", chave, resultado);
    else
        printf("%i nao se encontra no vetor.\n", chave);
}

void gera_vetor_input_int( int x[], int n )
{
    int i;
    printf("Digite os termos do vetor: ");
    for( i = 0; i < n; i++ )
        scanf("%i", &x[i]);
}

int busca_seq_rec(int v[], int n, int chave)
{
    if (n >= 0)
    {
        if(v[n] == chave)
            return n;
        else
            return busca_seq_rec( v, n-1, chave);
    }
    return -1;
}