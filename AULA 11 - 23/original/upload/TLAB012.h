#include <stdio.h>
#include <stdlib.h>

typedef struct abb{
	struct abb *esq,*dir;
	int chave;
	int conteudo;
} ArvBB;

void inicializar(ArvBB *a);
int inserir_interativo(ArvBB *a, int chave, float val);
int inserir_recursivo(ArvBB *a, int chave, float val);
float buscar_interativo(ArvBB *a, int chave);
float buscar_recursivo(ArvBB *a, int chave);
void listar_elementos(ArvBB *a);