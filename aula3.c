#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*int main (){
    int x, i;
    printf ("Digite um numero: ");
    scanf ("%i", &x);
    for (i = 1; i <= x; i++){
        int cont = 0;
            if (x % i == 0)
                cont++;
    }
    printf ("%i tem %i divisores\n", x, cont);
    if (cont == 2)
        printf ("%i eh primo\n", x);
    else
        printf ("%i nao eh primo\n", x);

    return 0;
}
*/

int main (int argc, char *argv[]) {
    int a, b, x;
    printf ("Digite A: ");
    scanf ("%d", &a);
    printf ("Digite B: ");
    scanf ("%d", &b);

    int cont_p = 0;
    for (x = a; x <= b; x++){
        int i, eh_primo = 1; // Verdadeiro, ou seja, assume-se que é primo
        float r = sqrt( x );
        for (i = 2; i < r && eh_primo; i++){
            if (x % i == 0)
                eh_primo = 0; // Falso, não é primo!
        }
        if (eh_primo){
            cont_p++;
            printf ("%d : %d\n",cont_p, x);
        }
    }

    return 0;
}
