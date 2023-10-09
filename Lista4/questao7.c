#include <stdio.h>
#include <stdlib.h>

int eh_numero( char s[] );
int eh_digito( char x );
int converte_int( char s[] );

int main()
{
	char str[20];
	printf("Digite algo: ");
	scanf("%s", str);
	if( eh_numero( str ) ){
		printf("'%s' eh um numero!\n", str );
		int x = converte_int( str );
		printf("x + 1 = %d\n", x+1);		
	}
	else
		printf("'%s' nao eh um numero!\n", str );
	
	return 0;
}


int eh_numero( char s[] )
{
	int i;
	for( i = 0 ; s[i] != 0 ; i++ )
    {
		if( !eh_digito( s[i] ) )
			return 0;
	}
	return 1;
}

int eh_digito( char x )
{
	return x >= '0' && x <= '9';
}

int converte_int( char s[] )
{
	int i;
	for( i = 0 ; s[i] != 0 ; i++ )
    {
		if( !eh_digito( s[i] ) )
			return -1;
	}
	int soma = 0, pot = 1, j;
	for( j = i-1 ; j >= 0 ; j-- )
    {
		int n = s[j] - '0'; // Convertendo char para int (d�gito)
		soma += n * pot;    // Acumula no somat�rio (* pot�ncia de 10)
		pot *= 10;			// Atualiza pot�ncia de 10
	}
	return soma;
}

