#include <stdio.h>

int contem( char str[], char key );

int main()
{
    char s[100];
    char key;
    printf("Digite uma palavra: ");
    scanf("%s", s);
    printf("Digite uma letra: ");
    scanf(" %c", &key);

    if( contem( s, key ) )
        printf("'%c' se encontra em '%s'\n", key, s);
    else
        printf("'%c' nao se encontra em '%s'\n", key, s);

    return 0;
}

int contem( char str[], char key )
{
    int i;
    for( i = 0; str[i] != 0; i++ )
        if( str[i] == key )
            return 1;

    return 0;
}