#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void concat( char a[], char b[] );
void concat_v2( char a[], char b[], char c[] );

int main()
{
    char x[20] = "Alguma";
    char y[20] = "Coisa";
    int n = strlen( x ) + strlen( y ) + 1;
    char s[n]; // V.L.A

    concat_v2( x, y, s );
    printf("S = '%s'\n", s);

    /*
    printf("X = '%s' e Y = '%s'\n", x, y);
    concat( x, " " );
    printf("X = '%s' e Y = '%s'\n", x, y);
    concat( x, y );
    printf("X = '%s' e Y = '%s'\n", x, y);
    */

    return 0;
}

void concat( char a[], char b[] )
{
    int n, i;
    for( n = 0; a[n] != 0; n++)
        ;
    for( i = 0; b[i] != 0; i++)
        a[i+n] = b[i];

    a[i+n] = 0;
}

void concat_v2( char a[], char b[], char c[] )
{
    int n, i;
    // Copia conteúdo de a para c:
    for( i = 0; a[i] != 0; i++)
        c[i] = a[i];
    // Encontra índice do '\0' em a:
    for( n = 0; a[n] != 0; n++)
        ;
    // Copia conteúdo de b para c:
    for( i = 0; b[i] != 0; i++)
        c[i+n] = b[i];

    c[i+n] = 0;
}