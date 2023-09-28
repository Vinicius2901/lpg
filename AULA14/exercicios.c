#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contem( char s[], char c );

int main()
{
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