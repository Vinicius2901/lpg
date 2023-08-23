#include <stdio.h>

int main()
{
    int comeco, final, duracao;
    printf("Digite o horario de inicio e do final do jogo: ");
    scanf("%i%i", &comeco, &final);

    if (comeco == final)
    {
        duracao = 24;
    }
    else if (comeco > final)
    {
        duracao = (24 + final) - comeco;
    }
    else
    {
        duracao = final - comeco;
    }

    printf("O JOGO DUROU %i HORA(S)", duracao);
    
    return 0;
}