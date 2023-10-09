#include <stdio.h>

void concatena( char str1[], char str2[] );

int main()
{
    char str1[20], str2[20];
    printf("Digite uma palavra: ");
    scanf("%s", str1);
    printf("Digite outra palavra: ");
    scanf("%s", str2);

    concatena( str1, str2 );
    printf("A string concatenada eh: %s\n", str1);
    return 0;
}

void concatena( char str1[], char str2[] )
{
    int i;
    for( i = 0; str1[i] != 0; i++ ) ;

    int j;
    for( j = 0; str2[j] != 0 && i < 20; j++ )
    {
        str1[i] = str2[j];
        i++;
    }
}