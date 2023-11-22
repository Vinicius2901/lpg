#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *tira_letra( char *s, char c );

int main()
{
    char s[20];
    printf("Digite uma palavra: ");
    scanf("%s", s );
    char key;
    printf("Digite uma letra: ");
    scanf(" %c", &key );
    
    char *r = tira_letra( s, key );
    
    printf("A palavra '%s' sem '%c' eh: %s\n", s, key, r );
    
    return 0;
    
}

char *tira_letra( char *s, char c )
{
    int i, aux = 0;
    int n = strlen( s );
    char *strrem = malloc( 0 );
    for( i = 0; i < n+1; i++ )
        if( s[i] != c )
        {
            strrem[aux] = s[i];
            aux++;
            strrem = realloc( strrem, aux );
        }
    strrem = realloc(strrem, aux+1 );
    return strrem;
}
