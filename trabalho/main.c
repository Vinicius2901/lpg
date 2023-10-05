#include <stdio.h>
#include <stdlib.h>

#define M 8
#define N 10

void menu();
int seq_search( int m[M][N], int conj, int conf, int count );
void inserir( int m[M][N], int conj);

int main()
{
    int m[M][N];
    int i, j, count = 0;
    for( i = 0; i < M; i++ )
        for( j = 0; j < N; j++ )
            m[i][j] = 0;
    int opt, conj;
    do
    {
        system( "cls" );
        menu();
        scanf("%i", &opt);
        switch( opt )
        {
            case 1:
                if( count < M)
                {
                    count++;
                    printf("Conjunto %i foi criado!\n", count-1);
                }
                else
                    printf("Nao eh possivel criar um novo conjunto\n");
                system( "pause" );
                break;

            case 2:
                if( count == 0 )
                {
                    printf("Voce precisa criar um conjunto primeiro.\n");
                    break;
                }
                printf("Qual conjunto voce deseja? ");
                scanf("%i", &conj);
                if( count <= conj )
                    printf("Esse conjunto nao existe!\n");
                else
                    inserir( m, conj );
                system( "pause" );
                break;
            
            //case 3:
        
            system( "pause" );
        }
    } while (opt != 9);
    
    for( i = 0; i < M; i++ )
    {
        for( j = 0; j < N; j++ )
            printf("%i ", m[i][j]);
        printf("\n");
    }
    
}

void menu()
{
    printf("Escolha qual opcao deseja: \n\n");
    printf("( 1 ) Criar um novo conjunto vazio\n");
    printf("( 2 ) Inserir dados em um conjunto\n");
    printf("( 3 ) Remover um conjunto\n");
    printf("( 4 ) Uniao entre conjuntos\n");
    printf("( 5 ) Interseccao entre conjuntos\n");
    printf("( 6 ) Mostrar um conjunto\n");
    printf("( 7 ) Mostrar todos os conjuntos\n");
    printf("( 8 ) Busca por valor\n");
    printf("( 9 ) Sair do programa\n\n");
}

int seq_search( int m[M][N], int conj, int conf, int count )
{
    int i = 0;
    for( i = 0; m[conj][i] != 0 && i < count; i++)
    {
        if( m[conj][i] == conf )
            return 1;
    }
    return 0;
}

void inserir( int m[M][N], int conj)
{
    int i;
    for( i = 0; i < N && m[conj][i]; i++) ; // Loop que determina em que posição o usuário pode inserir valores.

    int conf = 1; // Variável que confirma se o usuário quer ou não continuar e de repetição do vetor.
    while ( i < N && conf )
    {
        printf("Digite o %i elemento do conjunto: ", i+1);
        scanf("%i", &m[conj][i]);
        conf = m[conj][i];
        if( seq_search( m, conj, conf, i ) ) // Verificação de números iguais.
        {
            printf("Valor ja existe no vetor, Digite novamente: ");
            i--;
        }
        i++;
    }

    // Verificação de números iguais
    /*int j, k;
    for( i = 0; i < N && m[conj][i]; i++)
        for( j = i+1; j < N && m[conj][j]; j++ )
            if(m[conj][j] == m[conj][i])
            {
                for( k = j; k < N-1 && m[conj][k]; k++)
                    m[conj][k] = m[conj][k+1];
                j--;
            }

    if( i > N )
        printf("Limite do conjunto ultrapassado");*/
}
