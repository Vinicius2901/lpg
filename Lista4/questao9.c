#include <stdio.h>

void trim( char str[] );

int main()
{
    char str[250];
    printf("Digite algo: ");
    scanf("%[^\n]s", str);
    printf("A string sem trim eh: %s", str);

    trim( str );
    printf("A string com trim eh: %s\n", str);

    return 0;
}

void trim(char str[])
{
    int i, j = 0;
    for ( i = 0; str[i] != '\0'; i++ ) 
    {
        if( str[i] != ' ' || (str[i] == ' ' && str[i-1] != ' ' && str[i+i] != ' ') )
            str[j++] = str[i];
    }
    str[j] = '\0'; // Termina a string após a remoção dos espaços em branco
}
