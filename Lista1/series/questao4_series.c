#include <stdio.h>

int main()
{
    int n, i,j;
    printf ("Digite a quantidade de termos n: ");
    scanf ("%d", &n);
    double e_x = 0;
        for (i = 0; i <= n; i++){
            double termo = 1;
                for (j = 1; j <= i; j++){
                    termo *= 1.0/j;
                }
            e_x += termo; // e_x = e_x + termo
        }
    printf ("e vale: %.15lf", e_x);
    return 0;
}