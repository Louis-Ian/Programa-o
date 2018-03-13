#include <stdio.h>

typedef struct _abb{
	struct _abb *esq, *dir;
	int key;
} abb;

void inicializar_arvore(abb**);
int inserir_interativo(abb**,int);
int inserir_recursivo(abb**,int);
float buscar_interativo(abb*,int);
float buscar_recursivo(abb*,int);
int percorrer(abb**);