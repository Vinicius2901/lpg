#include <stdio.h>
#include <stdlib.h>

#define M 8
#define N 10

void menu();
int seq_search( int m[], int n, int chave );
void inserir( int m[M][N], int conj);
void remover( int m[M][N], int rem );
void unir( int m[M][N], int conj1, int conj2, int unidos);
void interseccao( int m[M][N], int conj1, int conj2, int interseccao );
void mostra_um_conj( int m[] );
void mostra_conj ( int m[M][N] ,int count );
void busca_val ( int m[M][N], int valor, int limite );

int main()
{
    int m[M][N];
    int i, j, count = 0;
    for( i = 0; i < M; i++ )
        for( j = 0; j < N; j++ )
            m[i][j] = 0;
    int opt, conj, conj1, conj2, key;
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
                if( count == 0 ) // Se o contador for = 0, não terão conjuntos criados.
                {
                    printf("Voce precisa criar um conjunto primeiro.\n");
                    break;
                }
                printf("Qual conjunto voce deseja? ");
                scanf("%i", &conj);

                while( conj >= count )
                {
                    printf("Esse conjunto nao existe ainda, digite novamente: ");
                    scanf("%i", conj);
                }
                
                if( count <= conj || conj < 0 ) // O contador será sempre um número acima do conjunto e o conjunto nunca será negativo.
                    printf("Esse conjunto nao existe!\n");
                else
                    inserir( m, conj );
                //system( "pause" );
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
                //system( "pause" );
                break;

            case 4:
                if( count <= 1 )
                {
                    printf("Voce precisa criar pelo menos dois conjuntos primeiro.\n");
                    break;
                }
                if( count == M )
                {
                    printf("Limite de conjuntos atingidos, por favor remova algum conjunto.\n");
                    break;
                }
                printf("Digite o numero do primeiro conjunto da uniao: ");
                scanf("%i", &conj1);
                while( conj1 >= count)
                {
                    printf("O conjunto que voce colocou ainda nao existe, digite novamente: ");
                    scanf("%i", &conj1);
                }
                printf("Digite o numero do segundo conjunto da uniao: ");
                scanf("%i", &conj2);
                while( conj2 >= count)
                {
                    printf("O conjunto que voce colocou ainda nao existe, digite novamente: ");
                    scanf("%i", &conj2);
                }

                count++;

                unir( m, conj1, conj2, count-1);
                //system( "pause" );
                break;

            case 5:
                if( count <= 1 )
                {
                    printf("Voce precisa criar pelo menos dois conjuntos primeiro.\n");
                    break;
                }
                if( count == M )
                {
                    printf("Limite de conjuntos atingidos, por favor remova algum conjunto.\n");
                    break;
                }
                printf ("Digite o numero do primeiro conjunto da interseccao: ");
                scanf("%i", &conj1);
                while( conj1 >= count)
                {
                    printf("O conjunto que voce colocou ainda nao existe, digite novamente: ");
                    scanf("%i", &conj1);
                }
                printf("Digite o numero do segundo conjunto da interseccao: ");
                scanf("%i", &conj2);
                while( conj2 >= count)
                {
                    printf("O conjunto que voce colocou ainda nao existe, digite novamente: ");
                    scanf("%i", &conj2);
                }

                count++;

                interseccao( m, conj1, conj2, count-1 );
                break;
            case 6:
                if( count == 0 )
                {
                    printf("Voce precisa criar um conjunto primeiro.\n");
                    break;
                }
                printf("Qual conjunto deseja mostrar? ");
                scanf("%i", &conj);
                while( conj >= count )
                {
                    printf("Esse conjunto nao existe ainda, digite novamente: ");
                    scanf("%i", conj);
                }
                
                mostra_um_conj( m[conj] );

                system( "pause" );
                break;
            case 7:
                if ( count == 0 )
                {
                    printf("Voce precisa criar um conjunto primeiro.\n");
                    break;
                }
                else 
                    mostra_conj (m, count);
                
                system( "pause" );
                break;
                
            case 8:
                if ( count == 0 )
                {
                    printf("Voce precisa criar um conjunto primeiro.\n");
                    break;
                }
                else 
                {
                    printf ("Digite o valor a ser buscado: ");
                    scanf ("%i", &key);
                    busca_val (m, key, count);
                    system( "pause" );
                    break;
                }
            case 9:
                break;

            default:
                while ( opt < 1 || opt > 9)
                {
                    printf("Por favor, digite um valor de 1 a 9: ");
                    scanf("%i", &opt);
                }
                break;
            system( "pause" );
        }
    } while (opt < 9 && opt > 0);
    return 0;
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

void inserir( int m[M][N], int conj )
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
        if( !seq_search( m[conj1], N, m[conj2][i] ) )
            count++;
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

void interseccao( int m[M][N], int conj1, int conj2, int interseccao )
{
    int i, j = 0, count;
    for( count = 0; m[conj2][count]; count++ ) ; // Ver ate onde vai o segundo conjunto.

    for( i = 0; m[conj1][i]; i++ )
        if( seq_search( m[conj2], count, m[conj1][i] ) ) // Verificar termo a termo do primeiro conjunto em relação ao segundo.
        {
            m[interseccao][j] = m[conj1][i];
            j++;
        }
}

void mostra_um_conj( int m[] )
{
    int i;
    for( i = 0; m[i]; i++ )
        printf("%i\t", m[i]);
    printf("\n");
}

void mostra_conj( int m[M][N] , int count ) {
    int i, j;
    for ( i = 0; i < count; i++ ) 
    {
        for ( j = 0; j < N; j++ ) 
            printf ("%i\t", m[i][j]);
        printf("\n");
    }
}

void busca_val ( int m[M][N], int valor, int limite ) {
    int v[limite];
    int i, j, k = 0;
    printf("O valor foi encontrado nos conjuntos: ");
    for( i = 0; i < limite; i++ )
        v[i] = -1;
    for( i = 0; i < limite; i++ )
        for( j = 0; m[i][j]; j++ )
            if( m[i][j] == valor )
                printf("%i ", i);
    
    /*for( i = 0; v[i] != -1; i++ )
        printf("%i ", v[i] );*/

    printf("\n");

    /*for( i = 0; i < limite; i++ )
        v[i] = -1;*/
}
