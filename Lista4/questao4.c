#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int palindrome( char str[] );

int main()
{
    char str[20];
    printf("Digite uma palavra: ");
    scanf("%s", str);

    if( palindrome( str ) )
        printf("%s eh um palindorme.\n", str);
    else
        printf("%s nao eh um palindrome.\n", str);

    return 0;
}

int palindrome( char str[] )
{
    int i, j;
    for( i = 0; str[i] != 0; i++ )
    {
        toupper( str[i] );
    }

    j = i-1;
    for( i = 0; i <= j; i++ )
    {
        if( str[i] != str[j] )
            return 0;
        j--;
    }
    return 1;
}