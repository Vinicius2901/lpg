#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contem( char s[], char c );
int eh_digito( char x );
int eh_numero( char s[] );
int converte_int( char s[] );

int main()
{
    // Exercício 1:

    /*
    int n;
    printf("Coloque o tamanho da string: ");
    scanf("%i", &n);

    char s[n+1];
    printf("Digite o conteudo da string: ");
    scanf(" %[^\n]s", s);

    char c;
    printf("Digite um caracter: ");
    scanf(" %c", &c);

    if (contem( s, c ))
        printf("'%c' se encontra em %s\n", c, s);
    else
        printf("'%c' nao se encontra em '%s'\n", c, s);
    */

    // Exercício 2 e 3:
    char str[20];
    printf("Digite uma string: ");
    scanf("%s", str);
    if( eh_numero )
    {
        printf("Eh numero.\n");
        int x = converte_int( str );
        printf("x + 1 = %i\n", x+1);
    }
    else
        printf("Nao eh numero.\n");


    return 0;
}

int contem( char s[], char c )
{
    int i;
    for( i = 0; s[i] != 0; i++)
        if( c == s[i] )
            return 1;
    return 0;
}

int eh_digito( char x )
{
    return x >= '0' && x <= '9';
}

int eh_numero( char s[] )
{
    int i;
    for( i = 0; s[i] != 0; i++)
        if( !eh_digito )
            return 0;

    return 1;
}

int converte_int( char s[] )
{
    int i;
    for( i = 0; s[i] != 0; i++ )
        if( !eh_digito( s[i] ) )
            return -1;

    int soma = 0, pot = 1, j;
    for( j = i-1; j >= 0; j-- )
    {
        int n = s[j] - '0'; // Convertendo char para int (dígito)
        soma += n * pot;    // Acumula no somatório (* potência de 10)
        pot *= 10;          // Atualiza potência de 10
    }
    return soma;
}
