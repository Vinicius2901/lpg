/* AULA 3 DE LPG */
#include <stdio.h>

void mostra_asterisco (int n);

int main () {
    int n, i;
    char letras[10000];
    int coord[][2] = {{1,1}, {1,2},
                      {1,3}, {1,4},
                      {1,5}, {2,1},
                      {2,2}, {2,3},
                      {2,4}, {2,5},
                      {1,3}, {3,1},
                      {3,2}, {3,3},
                      {3,4}, {3,5},
                      {4,1}, {4,2},
                      {4,3}, {4,4},
                      {4,5}, {5,1},
                      {5,2}, {5,3},
                      {5,4}, {5,5} };
    scanf ("%d%s", &n, letras);
    for (i = 0; letras[i]!='\0'; i++) {
        if (i != 0)
        {
            printf(" ");
        }
        char c = letras[i];
        int x = coord[c - 'A'][0];
        int y = coord[c - 'A'][1];
        mostra_asterisco(x);
        printf(" ");
        mostra_asterisco(y);
    }
    printf("\n");
}

void mostra_asterisco (int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("*");
    }
}
