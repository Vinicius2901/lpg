#include <stdio.h> //#include eh diretiva de compilação, usada para permitir funções específicas

int main(int argc, char *argv[]/*Parametros*/) {
    
    //aqui vai o código
    //unsigned int y; -> vai até 4bi postitivo
    //int x; -> 16bits ou 32 bits
    //long int z; -> 32bits
    //long long int k; -> 64bits "%lld"
    //scanf() -> entrada via teclado
    //printf() -> saída no console
    int x;
    printf("Digite um numero: ");
    scanf("%d", &x);
    
    char k;
    printf("Digite um caractere: ");
    /*scanf("%c", &k) não vai funcionar, pois o scanf pegará o enter dado no scanf anterior, pois enter é considerado um caracter. Uma das soluções é:*/ scanf(" %c", &k);
    /*pois o enter será consumido no espaço.*/

    printf("Voce digitou %d e '%c' (%d)\n", x, k, k);

    //scanf(" %[^\n]s") -> [^\n] significa qualquer coisa menos \n
    //\x, sendo x um código ASCII qualquer, dentro do printf printará o caracter que você colocou
    //% indica um tipo de dado e a expressão que vem após deve casar com o tipo indicado na %
    //\ indica caracter especial.
    //Para fazer uma divisão passar de inteira para real, basta um operando ser float.

    return 0;
}