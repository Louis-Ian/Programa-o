#include <stdio.h>
#include <stdlib.h>
//#include "ABB.h"

typedef struct _abb{
	struct _abb *esq, *dir;
	int key;
} abb;

void inicializar_arvore(abb **a){
	abb *aux;
	aux = (abb*)malloc(sizeof(abb));
	aux->esq = NULL;
	aux->dir = NULL;
};

int inserir_interativo(abb **a, int k){
	abb *aux = (abb*)malloc(sizeof(abb));
	//while(()())
};

int inserir_recursivo(abb **a, int k){
	abb *aux;

	if((a->key) == NULL)
		a = aux;
	else{
		*aux = (abb*)malloc(sizeof(abb));
		aux->esq = NULL;
		aux->dir = NULL;
		aux->key = k;

		if(a->key != k)
			if(a->key > k)
				inserir_recursivo(a->esq,k);
			else
				inserir_recursivo(a>dir,k);
		else{
			free(aux);
			pritf("chave já existente.\n");
		}
	}
};

float buscar_interativo(abb *a, int k){

};

float buscar_recursivo(abb *a, int k){

};

int percorrer(abb **a){

};

int main(int argc, char const *argv[]){
	abb *teste;
	inicializar_arvore(&teste);
	inserir_recursivo(&teste, 5);
	inserir_recursivo(&teste, 2);

	return 0;
}