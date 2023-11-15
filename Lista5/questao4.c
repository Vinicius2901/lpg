#include <stdio.h>

void cacula_hora(int totalMinutos, int *ph, int *pm);

int main()
{
    int tempo, horas, minutos;
    printf("Digite quantos minuitos se passaram no dia (a partir da meia-noite): ");
    scanf("%i", &tempo );

    cacula_hora( tempo, &horas, &minutos );

    printf("A hora atual eh %ih%imin", horas, minutos);

    return 0;
}

void cacula_hora(int totalMinutos, int *ph, int *pm)
{
    *ph = totalMinutos / 60;
    *pm = totalMinutos % 60;
}