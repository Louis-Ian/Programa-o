#include <stdio.h>

typedef struct _abb{
	struct _abb *esq, *dir;
	int chave;
} abb; 

void inserir_interativo(abb**,int);
void inserir_recursivo(abb**,int);
void buscar_interativo(abb*,int);
void buscar_recursivo(abb*,int);
int percorrer(abb**);
