// Funções para vetores

int binary_search (int v[], int n, int key);
void gera_valores (int x[], int k, int limite);
void gera_valores_ordem(int x[], int k, int limite);
void mostra_vetor(int x[]/*o vetor é um ponteiro*/, int k, char nome[]);
void mostra_vetor_2(int x[]/*o vetor é um ponteiro*/, int k, char nome[]);
void selection_sort(int x[], int k);
void bubble_sort(int x[], int k);

// Funções para matrizes
void mostra_matriz (int lin, int col, int x[lin][col]); // Você precisa dizer o número de colunas de uma matriz para passar como parametro em uma função.
void gera_valores_matriz (int lin, int col, int x[lin][col]);
void diagonal_principal (int dim, int x[dim][dim]);
void diagonal_secundaria (int dim, int x[dim][dim]);
float media_pares( int lin, int col, int x[lin][col] );
void gera_transposta( int lin, int col, int m[lin][col], int t[col][lin] );
void soma_matrizes( int lin, int col, int m1[lin][col], int m2[lin][col], int m3[lin][col] );
void multi_matrizes( int la, int ca, int a[la][ca], int lb, int cb, int b[lb][cb], int c[la][cb] );
