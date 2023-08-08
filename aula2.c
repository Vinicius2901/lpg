    /* AULA 2 DE LPG */

    //break sai do bloco em que está. Utiliza-se principalmente em loops para sair deles assim que achar o necessário ou em switch case, para sair do switch case.
    //case 8 ... 15 (8 até 15).
    //default em switch case seria equivalente a "else".

    #include <stdio.h>


    //codigo com switch case, que poderia ser substituido com if else:

    /*int main()
    {
        int codigo;
        printf("Digite um codigo de produto: ");
        scanf("%i", &codigo);
        switch (codigo)
        {
            case 1:
                printf("Nao perecivel\n");
                break;
            case 2:
            case 3:
                printf("Perecivel\n");
                break;
            case 8 ... 15:
                printf("Higiene\n");
                break;
            default:
                printf("Erro!\n");
                break;
        }
        return 0;
    }*/


    //Ler o nome e o sexo de uma pessoa apresentando "Ilmo. Sr." para homem e "Ilma. Sra." para mulher:
    
    /*int main()
    {
        char nome[30], sexo;
        printf("Digite o nome: ");
        scanf("%[^\n]", nome);
        printf("'f' para feminino");
        printf(" ou 'm' para masculino: ");
        scanf(" %c", &sexo);
        switch (sexo)
        {
            case 'f':
                printf("Ilma. Sra.%s\n", nome);
                break;
            case 'm':
                printf("Ilmo. Sr.%s\n", nome);
                break;
            default:
                printf("Entrada Invalida!\n");
        }
    }*/

    //Estruturas de repetição = estruturas de iteração.
    //while: numero de repetição indeterminado -> sem contador
    
    //Cálculo do fatorial:

    /*int main()
    {
        int n;
        printf("Digite um numero: ");
        scanf("%i", &n);
        int fat = 1; //Acumulador.
        while (n > 0)
        {
            fat *= n;//-> fat = fat * n; -> Acumula n em fat .
            n--;//-> n = n - 1; -> Decrementa n.
        }
        printf("Fatorial: %i\n", fat);
        return 0;
    }*/
    //ou
    /*int main()
    {
        int n;
        printf("Digite um numero: ");
        scanf("%i", &n);
        int fat = 1;  //Acumulador.
        int cont = 1; //Contador
        while (cont <= n)
        {
            fat *= cont; //-> fat = fat * cont; -> Acumula cont em fat.
            cont++;      //-> cont = cont + 1; -> Incrementa cont.
        }
        printf("Fatorial de %i: %i\n", n, fat);
        return 0;
    }*/

    //for -> para entradas determinadas -> com contador
    //for (condição inicial "cont = 1"; Booleano "cont <=n"; o que acontece ao final do loop "cont++")
    //for (inicialização; teste; incremento/decremento)

    /*int main()
    {
        int n;
        printf("Digite um numero: ");
        scanf("%i", &n);
        int fat = 1;  //Acumulador.
        int cont;     //Contador
        for (cont = 1; cont <= n; cont++)
        {
            fat *= cont; //-> fat = fat * cont; -> Acumula cont em fat.
        }
        printf("Fatorial de %i: %i\n", n, fat);
        return 0;
    }*/

    //do while é melhor para menus ou repetição do programa inteiro
