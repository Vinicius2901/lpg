#include <stdio.h>

int digito( char str[] );

int main()
{
    char str[20];
    printf("Digite algo: ");
    scanf("%s", str);

    if( digito( str ) )
        printf("A string eh composta apenas por digitos\n");
    else
        printf("A string nao eh composta apenas por digitos.\n");
    return 0;
}

int digito( char str[] )
{
    int i;
    for( i = 0; str[i] != 0; i++ )
        if( str[i] <= '0' || str[i] >= '9')
            return 0;
    return 1;
}