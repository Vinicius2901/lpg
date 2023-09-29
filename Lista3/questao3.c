#include <stdio.h>
#include <math.h>

int eh_primo( int x );
int soma_primos( int v[], int n );
void gera_vetor_input_int( int x[], int n );

int main()
{
    int n;
    printf("Digite quantos termos deseja no vetor: ");
    scanf("%i", &n);

    int v[n];
    gera_vetor_input_int( v, n );

    int resultado = soma_primos( v, n );
    printf("A soma dos primos do vetor eh: %i\n", resultado);

    return 0;
}

int eh_primo( int x )
{
	if( x == 1 )
		return 0;

	int i; 
	int r = sqrt( x );
	for( i = 2 ; i <= r ; i++ ){
		if( x % i == 0 )
			return 0; //  Falso, n�o � primo!
	}
	return 1; // Verdadeiro, � primo!
}

int soma_primos(int v[], int n)
{
    int i;
    int resultado = 0;
    for( i = 0; i < n; i++)
        if (eh_primo( v[i] ))
            resultado += v[i];
    return resultado;
}

void gera_vetor_input_int( int x[], int n )
{
    int i;
    printf("Digite os termos do vetor: ");
    for( i = 0; i < n; i++ )
        scanf("%i", &x[i]);
}
