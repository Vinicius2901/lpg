#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *repetidor( char *s, int n );

int main()
{
    char s[1000];
    printf("Digite uma palavra: ");
    scanf("%s", s);
    
    int rep;
    printf("Digite quantas vezes deseja repetir a palavra: ");
    scanf("%i", &rep);

    char *nRep = repetidor( s, rep );

    printf("A string digitada repetida %i vezes eh: %s", rep, nRep);

    free( nRep );

    return 0;
}

char *repetidor( char *s, int n )
{
    int i, j;
    int rep = 0;
    int tam = strlen( s );
    char *nRep = malloc( tam * n + 1);
    for( i = 0; i < n; i++ )
    {
        for( j = 0; j < tam * n; j++ )
            nRep[j+rep] = s[j];
        rep += tam;
    }
    nRep[tam*n+1] = '\0';
    return nRep;
}