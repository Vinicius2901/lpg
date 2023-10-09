#include <stdio.h>

void maiuscula( char str[] );

int main()
{
    char str[20];
    printf("Digite uma palavra: ");
    scanf("%s", str);

    maiuscula( str );
    printf("A palavra em maiusculo eh: %s\n", str);
    return 0;
}

void maiuscula( char str[] )
{
    int i;
    for( i = 0; str[i] != 0; i++ )
        if( str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
}