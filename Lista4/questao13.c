#include <stdio.h>

void substring( char str[], int ini, int n, char sub[] );

int main()
{
    char str[250];
    printf("Digite algo: ");
    scanf("%[^\n]s", str);

    char sub[250];
    
    int ini, n;
    printf("Digite o indice da string em que deseja iniciar a sua copia e o numero de letras: ");
    scanf(" %i%i", &ini, &n);

    substring( str, ini, n, sub );
    printf("A substring gerada eh: %s\n", sub);

    return 0;
}

void substring( char str[], int ini, int n, char sub[] )
{
    int i, j = 0;
    for( i = ini; j < 5; i++)
    {
        sub[j] = str[i];
        j++;
    }
    sub[j] = '\0';
}