#include <stdio.h>
#include <stdlib.h>
#include "Produto.h"

int main()
{
    Produto *v = NULL;
    int n = 0;
    int opcao;
    int i;

    FILE *f = fopen( "produtos.txt", "rt" );
    if( f == NULL )
    {
        printf("Arquico nao encontrado!\n");
    }
    else
    {
        fscanf( f, "%d", &n );
        v = malloc( sizeof(Produto) * n );
        for( i = 0; i < n; i++ )
        {
            fscanf( f, "%d", &v[i].codigo );
	        fscanf( f, " %[^\n]", v[i].descricao );
	        fscanf( f, "%f", &v[i].preco );
            fscanf( f, "%d %d %d", &v[i].validade.dia, v[i].validade.mes, &v[i].validade.ano );
        }
        fclose( f );
        printf("%d registros foram carregados!\n", n);
    }

    do
    {
        printf("1-Cadastrar\n2-Mostrar produtos\n3-Sair\n");
        scanf("%d", &opcao );
        switch( opcao )
        {
                case 1:
                    n++;
                    v = realloc( v, sizeof(Produto) * n );
                    le_produto( &v[n-1] );
                    break;
                case 2:
                    if( n == 0 )
                        printf("Cadastro vazio!\n");
                    else
                    {
                        printf("Produtos cadastrados:\n");
                        for( i = 0; i < n; i++ )
                        {
                            printf("Produto %d:\n", i+1 );
                            mostra_produto( &v[i] );
                        }
                    }
                    break;
        }
    } while ( opcao !=3 );

    // Salva vetor v no aruivo.
    FILE *f = fopen( "produtos.txt", "wt" );
    if( f == NULL )
    {
        printf("Erro no arquivo da saida!\n");
        return 1;
    }
    fprintf( f, "%d\n", n );
    for( i = 0; i < n; i++ )
    {
        fprintf( f, "%d\n", v[i].codigo );
        fprintf( f, "%s\n", v[i]. descricao );
        fprintf( f, "%.2f\n", v[i].preco );
        fprintf( f, "%d %d %d\n", v[i].validade.dia, v[i].validade.mes, v[i].validade.ano );
    }
    
    fclose( f ); // Fundamental! Da comit no txt.

    free( v );
    return 0;    
}