#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

typedef struct listaCircularPolimorfica{
	struct listaCircularPolimorfica *next;
	struct listaCircularPolimorfica *prev;
	void *info;
	int key;
	int type;
} LCP;

void inicializar(LCP **listaInput){
	(*listaInput) = (LCP*)malloc(sizeof(LCP));
	(*listaInput)->key = 0;
	(*listaInput)->next = (*listaInput);
	(*listaInput)->prev = (*listaInput);
}

void inserir_inteiro (LCP **listaInput, int keyInput, int val){
	LCP (*aux) = (LCP*)malloc(sizeof(LCP));
	aux = (*listaInput);
	while(aux->key > keyInput)
		aux = aux->next;

	aux->info = (int*)val;
	aux->type = (int*)0;
	aux->prev = (aux->prev)->next;
	(aux->prev)->next = aux;
	(aux->next)->prev = aux;
}

/*void inserir_inteiro (LCP **listaInput, int keyInput, int val){
	LCP (*aux) = (LCP*)malloc(sizeof(LCP));
	aux = (*listaInput);
	while(aux->key > keyInput)
		aux = aux->next;

	aux->prev = (aux->prev)->next;
	(aux->prev)->next = aux;
	(aux->next)->prev = aux;
}*/



int main(int argc, char const *argv[]){
	LCP *lcp;
	inicializar(&lcp);
	inserir_inteiro(&lcp, 1, 10);

	printf("%d\n", (int)(*lcp).info);


	return 0;
}