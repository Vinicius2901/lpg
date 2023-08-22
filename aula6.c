#include <stdio.h>
#include <math.h>

int eh_primo (int x);
int raiz_quad (int x);


int main (int argc, char *argv[]) {
    int a, b, x;
    printf ("Digite A: ");
    scanf ("%d", &a);
    printf ("Digite B: ");
    scanf ("%d", &b);

    int cont_p = 0;
    for (x = a; x <= b; x++){
        if (eh_primo(x)){
            cont_p++;
            printf ("%d : %d\n",cont_p, x);
        }
    }

    return 0;
}

int eh_primo (int x)
{
    int i;
    float r = raiz_quad( x );
    if (x == 1)
    {
        return 0;
    }
    for (i = 2; i <= r; i++){
        if (x % i == 0) {
            return 0; // Falso, não é primo!
        }
    }
    return 1; // Verdadeiro, é primo!
}

int raiz_quad (int x)
{
    int cont = 0, impar = 1;
    while (x >= impar)
    {
        x -= impar;
        cont++;
        impar += 2;
    }
    return cont;
}