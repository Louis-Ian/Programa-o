#include "TLAB012.h"
#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

/*typedef struct abb{
	struct abb *esq,*dir;
	int chave;
	int conteudo;
} ArvBB;*/

void inicializar(ArvBB *a){
	a->chave = NULL;
	a->conteudo = NULL;
	a->dir = NULL;
	a->esq = NULL;
};

int inserir_interativo(ArvBB *a, int chaveIN, float val){

	ArvBB *in = malloc(sizeof(ArvBB));
	in->chave = chaveIN;
	in->esq = in->dir = NULL;
	in->conteudo = val;

	ArvBB *aux = a;
	int achou = FALSE;

	while(achou == FALSE){
		if(chaveIN < aux->chave){
			if(aux->esq == NULL){
				aux->esq = in;
				//printf("%f\n", aux->esq->conteudo);
				achou = TRUE;
			}
		}
		else if(chaveIN > aux->chave){
			if(aux->dir == NULL){
				aux->dir = in;
				//printf("%f\n", aux->dir->conteudo);
				achou = TRUE;
			}
		}
		else{
			return 0;
		}
	}
	return 1;
};

int inserir_recursivo(ArvBB *a, int chaveIN, float val){
	if(a->chave < chaveIN){
		if(a->dir == NULL){
			ArvBB *aux = (ArvBB*)malloc(sizeof(ArvBB));
			aux->chave = chaveIN;
			aux->conteudo = val;
			aux->esq = NULL;
			aux->dir = NULL;
			a->dir = aux;
		}
		else{
			a->dir = inserir_recursivo(a->dir, chaveIN, val);
		}
	}
	else if(a->chave > chaveIN){
		if(a->esq == NULL){
			ArvBB *aux = (ArvBB*)malloc(sizeof(ArvBB));
			aux->chave = chaveIN;
			aux->conteudo = val;
			aux->esq = NULL;
			aux->dir = NULL;
			a->esq = aux;
		}
		else{
			a->esq = inserir_recursivo(a->esq, chaveIN, val);
		}
	}
	else if(a->chave == chaveIN)
		return 0;

	return 1;
};

float buscar_interativo(ArvBB *a, int chaveIN){
	ArvBB *aux = a;
	float valor;
	int achou = FALSE;

	while(achou == FALSE){
		if(chaveIN == aux->chave){
			valor = aux->conteudo;
			//printf("valor:%f\n", valor);
			//printf("chave:%d\n", aux->esq->chave);
			achou = TRUE;
		}
		else if(chaveIN > aux->chave){
			valor = aux->conteudo;
			//printf("valor:%d\n", valor);
			//printf("chave:%d\n", aux->dir->chave);
			achou = TRUE;
		}
		else{
			return 9999.9;
		}
	}
	return 1;
};

float buscar_recursivo(ArvBB *a, int chaveIN){
	ArvBB *aux;

	if(a->chave == chaveIN)
		return a->conteudo;
	else if(chaveIN < a->chave)
		buscar_recursivo(a->esq, chaveIN);
	else if(chaveIN > a->chave)
		buscar_recursivo(a->dir, chaveIN);
	else
		return 9999.9;
};

void listar_elementos(ArvBB *a){
	float imprimir;
	for (int i = 0; i < 1000000; ++i)
	{
		imprimir = buscar_recursivo(a,i);
		if(imprimir != 9999.9)
			printf("elemento %d: %f\n", i, imprimir);
	}
};

/*int main(int argc, char const *argv[])
{
//	int pausa;

	ArvBB *teste;
	inicializar(teste);
	inserir_interativo(teste,4,10.0);
	listar_elementos(teste);

//	scanf("%d",pausa);
	return 0;
}*/