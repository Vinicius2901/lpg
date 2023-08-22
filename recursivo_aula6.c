#include <stdio.h>

void f (int x);
void g (int x);


/*int main()
{
    printf("\n... Antes da funcao...\n");
    f( 5 );
    printf("\n... Voltei pra main...\n");

    return 0;
}

void f (int x)
{
    //printf("Estou em f:\n");
    printf("%d\n", x);
    //system("PAUSE");
    if (x > 0)
    {
        f (x - 1);
        printf("[Voltei da chamada... (%d)...]\n", x);
    }
    /*printf("Voltei pra f...\n");
    printf("%d\n", x);
}*/

/*void g (int x)
{
    printf("Estou em g:\n");
    printf("%d\n", x);
}*/
/*  
    AULA 6 - RECURSIVIDADE

    Recursividade
    - Método para solução de provlemas que depende da solução de partes menores do problema principal;
    - Função que chama a si mesma;
    - Cada invocação resolve parte do problema;
    - Efeito equivalente a um processo de repetição;
    - Para garantir que o processo se encerre, precisa-se de um caso base;
    
    Caso base:
    - Valor trivial esperado para a função, sem necessidade de realizar recursão;

    Exemplo:
    x! -> 1, se x = 0 (caso base) -> encerra o processo recursivo.
       -> x*(x-1)!, caso contrário (caso recursivo) -> onde ocorre a recursão.
       Chamadas: 4! -> 4*3! -> 3.2! -> 2*1! -> 1*0!
       Retorno: 1*1 -> 2*1 -> 2*3 -> 6*4 -> 24 (Calculo é feito efetivamente)


*/

int fatorial (int x);

int main()
{
    int n;
    printf("Digite um numero: ");
    scanf("%i", &n);

    printf("Fatorial de %i : %i\n", n, fatorial(n));

    return 0;
}

int fatorial (int x)
{
    if (x == 0)
    {
        printf("[Caso base: retorna 1]\n");
        return 1;
    }
    else
    {
        printf("[Calculando fatorial de %i: %i*%i!...]\n", x, x, x-1);
        int y = fatorial (x-1);
        printf ("[Retorno da chamada recursiva: %i! : %i]\n", x-1, y);
        return x * y;

    }
}