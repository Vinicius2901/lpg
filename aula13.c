#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[30] = "Fulano"; // = {'F', 'u', 'l', 'a', 'n', 'o', \0}
    int x = sizeof( s ); // 30
    int y = strlen( s ); // 6

    printf("Tamanho da variavel: %li\n", sizeof( s ));
    printf("'%s' tem %li caracteres.\n", s, strlen( s ));

    int i;
    for( i = 0; s[i] != '\0'; i++)
        printf("s[%i]: %c\n",i, s[i]);

    float v[] = {3, 6, 9, 12, 25, 44, 82, 144, 256};
    int n = sizeof( v ) / sizeof( v[0] ); // Tamanho do vetor de int/float

    char s1[20], s2[20];
    
    printf("Digite alguma coisa: ");
    scanf("%s", s1);
    printf("Digite outra coisa: ");
    scanf("%s", s2);

    int x1 = strcmpi( s1, s2 ); // Analisa letra minuscula = letra maiuscula
    if( x1 == 0 )
        printf("'%s' == '%s'\n", s1, s2);
    else
        if( x1 > 0 )
            printf("'%s' > '%s'\n", s1, s2);
        if( x1 < 0 )
            printf("'%s' < '%s'\n", s1, s2);

    return 0;
}
