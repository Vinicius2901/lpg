#include <stdio.h>

void inverte_string( char str[] );

int main()
{
    char str[20];
    printf("Digite uma string: ");
    scanf("%s", str);
    printf("A string original eh: %s\n", str);

    inverte_string( str );
    printf("A string invertida eh: %s\n", str);

    return 0;
}

void inverte_string( char str[] )
{
    int i, j;
    for( i = 0; str[i]; i++ ) ;
    j = i-1;
    char aux;
    for( i = 0; i <= j; i++ )
    {
        aux = str[i];
        str[i] = str[j];
        str[j] = aux;
        j--;
    }
}