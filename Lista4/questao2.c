#include <stdio.h>

int vezes_aparece( char str[], char key );

int main()
{
    char s[100];
    char key;
    printf("Digite uma palavra: ");
    scanf("%s", s);
    printf("Digite uma letra: ");
    scanf(" %c", &key);

    int count = vezes_aparece( s, key );

    if( count )
        printf("'%c' se encontra em '%s' %i vezes\n", key, s, count);
    else
        printf("'%c' nao se encontra em '%s'\n", key, s);

    return 0;
}

int vezes_aparece( char str[], char key )
{
    int i, count = 0;
    for( i = 0; str[i] != 0; i++ )
        if( str[i] == key )
            count++;

    return count;
}