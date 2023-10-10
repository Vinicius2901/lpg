#include <stdio.h>
#include <stdlib.h>

#define M 8
#define N 10

void menu();
int seq_search( int m[], int n, int chave );
void inserir( int m[M][N], int conj);
void remover( int m[M][N], int rem );
void unir( int m[M][N], int conj1, int conj2, int unidos);

int main()
{
    int m[M][N];
    int i, j, count = 0;
    for( i = 0; i < M; i++ )
        for( j = 0; j < N; j++ )
            m[i][j] = 0;
    int opt;
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
                    printf("Limite maximo de conjuntos atingido\n");
                system( "pause" );
                break;

            case 2:
                if( count == 0 )
                {
                    printf("Voce precisa criar um conjunto primeiro.\n");
                    break;
                }
                printf("Qual conjunto voce deseja? ");
                int conj;
                scanf("%i", &conj);
                if( count <= conj || conj < 0 )
                    printf("Esse conjunto nao existe!\n");
                else
                    inserir( m, conj );
                system( "pause" );
                break;
            
            case 3:
                if( count == 0 )
                {
                    printf("Voce precisa criar um conjunto primeiro.\n");
                    break;
                }
                printf("Qual conjunto deseja remover? ");
                int rem;
                scanf("%i", &rem);
                remover( m, rem );
                count--;
                system( "pause" );
                break;

            case 4:
                if( count <= 1 )
                {
                    printf("Voce precisa criar pelo menos dois coinjuntos primeiro.\n");
                    break;
                }
                if( count == M-1 )
                {
                    printf("Limite de conjuntos atingidos, por favor remova algum conjunto.\n");
                    break;
                }
                count++;
                printf("Digite o numero do primeiro conjunto que deseja unir: ");
                int conj1, conj2;
                scanf("%i", &conj1);
                printf("Digite o numero do segundo conjunto que deseja unir: ");
                scanf("%i", &conj2);
                
                unir( m, conj1, conj2, count-1);
                system( "pause" );
                break;

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

int seq_search( int m[], int n, int chave )
{
    int i = 0;
    for( i = 0; i < n; i++)
    {
        if( m[i] == chave )
            return 1;
    }
    return 0;
}

void inserir( int m[M][N], int conj)
{
    int i;
    for( i = 0; i < N && m[conj][i]; i++) ; // Loop que determina em que posição o usuário pode inserir valores.

    if ( i == N )
        printf("Conjunto ja esta cheio.\n");
    else
    {
        int conf = 1; // Variável que confirma se o usuário quer ou não continuar e de repetição do vetor.
        while ( i < N && conf )
        {
            printf("Digite o %i elemento do conjunto: ", i+1);
            scanf("%i", &m[conj][i]);
            conf = m[conj][i];
            if( seq_search( m[conj], i, conf ) ) // Verificação de números iguais.
            {
                printf("Valor ja existe no vetor, Digite novamente: ");
                i--;
            }
            i++;
        }
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

void remover( int m[M][N], int rem )
{
    int i;
    for( i = 0; i < N && m[rem][i]; i++) // Zerar a linha removida
        m[rem][i] = 0;
    
    int j;
    for( i = rem; i < M-1; i++) // Trazer as linhas acima para a anterior
        for( j = 0; j < N; j++)
            m[i][j] = m[i+1][j];

    if( i == M-1 ) // Zerar a ultima linha
        for( j = 0; m[i][j] != 0; j++)
            m[i][j] = 0;
}

void unir( int m[M][N], int conj1, int conj2, int unidos)
{
    int i, count = 0;
    for( i = 0; m[conj1][i]; i++ ) // Quantidade de termos do primeiro conjunto.
        count++;
    for( i = 0; m[conj2][i]; i++ ) // Verificar se há valores iguais no primeiro e segundo conjunto e contar o total.
    {
        count++;
        if( seq_search( m[conj1], N, m[conj2][i] ) )
            count--;
    }
    if( count > N )
        printf("Nao eh possivel fazer a uniao, mais elementos que o limite\n");
    else
    {
        int j;
        for( i = 0; m[conj1][i]; i++)
            m[unidos][i] = m[conj1][i]; // Acrescenta o primeiro conjunto a união
        for( j = 0; m[conj2][j]; j++)
        {
            if( seq_search( m[conj1], i, m[conj2][j]) == 0 ) // Se um elemento do segundo conjunto for igual a um do primeiro, ele nao sera acrescentado.
            {
                m[unidos][i] = m[conj2][j];
                i++;
            }
        }
    }
}
