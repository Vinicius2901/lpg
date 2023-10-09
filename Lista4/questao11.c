#include <stdio.h>

void ocorrencias( char str[], char key );

int main()
{
    char str[250];
    printf("Digite uma string: ");
    scanf("%s", str);
    printf("A string original eh: %s\n", str);

    char key;
    printf("Digite uma letra que deseja retirar da string: ");
    scanf(" %c", &key);

    ocorrencias( str, key );
    printf("A string modificada eh: %s\n", str);

    return 0;
}

void ocorrencias( char str[], char key )
{
    int i, j = 0;
    for ( i = 0; str[i] != '\0'; i++ ) 
    {
        if( str[i] != key )
            str[j++] = str[i];
    }
    str[j] = '\0'; // Termina a string após a remoção dos espaços em branco
}