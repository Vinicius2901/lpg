#include <stdio.h>

int compara( char str1[], char str2[] );

int main()
{
    char str1[250], str2[250];
    printf("Digite uma palavra: ");
    scanf("%s", str1);
    printf("Digite outra palavra: ");
    scanf(" %s", str2);

    if( compara( str1, str2 ) < 0 )
        printf("A string 1 eh menor que a string 2.\n");
    else if( compara( str1, str2 ) == 0 )
        printf("As strings sao iguais.\n");
    else
        printf("A string 1 eh maior que a string2.\n");

    return 0;
}

int compara( char str1[], char str2[] )
{
    int i, j;
    for( i = 0; str1[i]; i++ ) ;
    for( j = 0; str2[j]; j++ ) ;
    if( i < j )
    {
        for( i = 0; str1[i]; i++ )
        {
            if( str1[i] < str2[i] )
                return -1;
            if( str1[i] > str2[i] )
                return 1;
        }
        return -1;
    }
    if( i > j )
    {
        for( i = 0; str2[i]; i++ )
        {
            if( str1[i] < str2[i] )
                return -1;
            if( str1[i] > str2[i] )
                return 1;
        }
        return 1;
    }
    for( i = 0; str1[i]; i++ )
    {
        if( str1[i] < str2[i] )
            return -1;
        if( str1[i] > str2[i] )
            return 1;
    }
    return 0;
}