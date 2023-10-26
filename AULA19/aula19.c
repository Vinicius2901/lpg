#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//void *malloc ( int n ); -> retorna um ponteiro de quantas casas na memoria voce quer.
char *concat( char *s1, char *s2 );

int main()
{
    char a[] = "Alguma";
    char b[] = "Coisa";

    char *c = concat( a, b );
    printf("%s\n", c);

    free(c);
    
    return 0;
}

char *concat( char *s1, char *s2 )
{
    int n1 = strlen( s1 );
    int n2 = strlen( s2 );
    char *p = malloc( n1+ n2 + 1); // sizeof(char) é 1, então não precisa dele.
    strcpy( p, s1 ); // Copia o conteúdo da primeira string para a concatenação.
    strcpy( p + n1 /* =  &p[n1]*/, s2 ); // Copia o conteúdo da segunda string para p a partir da posição 6 de p.

    return p;
}