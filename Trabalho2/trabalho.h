#include "Data.h"

typedef struct
{
    int hora, min;
} Horario;

typedef struct
{
    Data event;
    Horario inicio;
    Horario fim;
    char info[50];
    char local[50];
} Evento;

void carrega_registro( Evento *v, int n, char *nome_arq );

void menu();

void mostrar_evento( Evento *x );

void mostra_todos_eventos( Evento *x, int n );

void mostra_evento_data( Evento *x, int n );

void mostra_evento_desc( Evento *x, int n );

int insere_evento( Evento *x, int n );

void le_horario( Horario *x );

int compara_horario( Horario *a, Horario *b );