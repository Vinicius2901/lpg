#include <stdio.h>

int eh_digito (char x);

int main()
{
    char k;
    printf("Digite um caracter: ");
    scanf("%c", &k);

    if (eh_digito(k))
    {
        printf("Eh digito\n");
    }
    else
    {
        printf("Nao eh digito\n");
    }
    return 0;
}


int eh_digito (char x)
{
    return x >= '0' && x <= '9';
}