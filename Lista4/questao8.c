#include <stdio.h>

int eh_digito( char x );
int converte_int(char s[] );
int eh_data( char s[] );
int dia_int( char data[] );
int mes_int( char data[] );
int ano_int( char data[] );

int main()
{
    char data[12];
    printf("Digite uma data: (DD/MM/AAAA)\n");
    scanf("%s", data);

    if( eh_data( data ) )
    {
        int dia, mes, ano;
        dia = dia_int( data );
        mes = mes_int( data );
        ano = ano_int( data );
        printf("A data eh: %i/%i/%i\n", dia, mes, ano);
    }
    else
        printf("A data nao foi digitada corretamente.\n");

    return 0;
}

int eh_digito( char x )
{
	return x >= '0' && x <= '9';
}

int converte_int( char s[] )
{
    int i;
    for( i = 0; s[i]; i++ )
        if( !eh_digito( s[i] ) )
            return -1;

    int j, soma = 0, pot = 1;
    for( j = i-1; j >= 0; j-- )
    {
        soma += (s[j] - '0') * pot;
        pot *= 10;
    }
    return soma;
}

int eh_data( char s[] )
{
    int i;
    if( s[2] != '/' || s[5] != '/' )
        return 0;
    for( i = 0; i != 0; i++ )
    {
        if( s[i] = '/' )
            i++;

        if( !eh_digito( s[i] ) )
            return 0;
    }
    return 1;
}

int dia_int( char data[] )
{
    int i, j;
    char dia[] = "00";
    for( j = 0; i < 2; j++ )
    {
        dia[j] = data[i];
        i++;
    }
    int diai = converte_int( dia );
    
    return diai;
}

int mes_int( char data[] )
{
    int i, j = 0;
    char mes[] = "00";
    for( i = 3; i < 5; i++ )
    {
        mes[j] = data[i];
        j++;
    }
    int mesi = converte_int( mes );
    return mesi;
}

int ano_int( char data[] )
{
    int i, j = 0;
    char ano[] = "0000";
    for( i = 6; data[i]; i++)
    {
        ano[j] = data[i];
        j++;
    }
    int anoi = converte_int( ano );
    return anoi;
}