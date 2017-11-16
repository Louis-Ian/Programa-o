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

void inserir_inteiro(LCP **listaInput, int keyInput, int val){
	LCP (*aux) = (LCP*)malloc(sizeof(LCP));
	aux = (*listaInput);
	while((aux->next)->key > keyInput)
		aux = aux->next;

	aux->info = (int*)val;
	aux->type = 0;
	aux->prev = (aux->prev)->next;
	(aux->prev)->next = aux;
	(aux->next)->prev = aux;
}

/*void inserir_p_flutuante (LCP **listaInput, int keyInput, double val){
	LCP (*aux) = (LCP*)malloc(sizeof(LCP));
	aux = (*listaInput);
	while(aux->key < keyInput)
		aux = aux->next;

	double *fInput = malloc(sizeof(double));
	*fInput = val;

	aux->info = (double*)fInput;
	//aux->info = (double**)val;
	aux->type = 1;
	aux->prev = (aux->prev)->next;
	(aux->prev)->next = aux;
	(aux->next)->prev = aux;
}*/

void inserir_caracteres(LCP **listaInput, int keyInput, char val){
	LCP (*aux) = (LCP*)malloc(sizeof(LCP));
	aux = (*listaInput);

	while(aux->key > keyInput)
		aux = aux->next;

	aux->info = (char*)val;
	aux->type = 2;
	aux->prev = (aux->prev)->next;
	(aux->prev)->next = aux;
	(aux->next)->prev = aux;
}

void inserir_c_caracteres(LCP **listaInput, int keyInput, char *val){
	LCP (*aux) = (LCP*)malloc(sizeof(LCP));
	aux = (*listaInput);
	while(aux->key > keyInput)
		aux = aux->next;

	aux->info = (char*)val;
	aux->type = 3;
	aux->prev = (aux->prev)->next;
	(aux->prev)->next = aux;
	(aux->next)->prev = aux;
}

int obter_tipo(LCP **listaInput, int keyInput){
	LCP (*aux) = (LCP*)malloc(sizeof(LCP));
	aux = (*listaInput);
	while(aux->key > keyInput)
		aux = aux->next;

	if(aux->type == 0)
		return 0;
	else if(aux->type == 1)
		return 1;
	else if(aux->type == 2)
		return 2;
	else if(aux->type == 3)
		return 3;
	else
		return 4;
}

int obter_inteiro(LCP **listaInput, int keyInput){
	LCP (*aux) = (LCP*)malloc(sizeof(LCP));
	aux = (*listaInput);
	while(aux->key > keyInput)
		aux = aux->next;

	printf("%d\n", aux->info);
}

float obter_p_flutuante(LCP **listaInput, int keyInput){
	LCP (*aux) = (LCP*)malloc(sizeof(LCP));
	aux = (*listaInput);
	while(aux->key > keyInput)
		aux = aux->next;

	printf("%f\n", aux->info);
}

char *obter_c_caracteres(LCP **listaInput, int keyInput){
	LCP (*aux) = (LCP*)malloc(sizeof(LCP));
	aux = (*listaInput);
	while(aux->key > keyInput)
		aux = aux->next;

	printf("%s\n", aux->info);
}

char obter_caractere(LCP **listaInput, int keyInput){
	LCP (*aux) = (LCP*)malloc(sizeof(LCP));
	aux = (*listaInput);
	while(aux->key > keyInput)
		aux = aux->next;

	printf("%c\n", aux->info);
}

void listar_elementos(LCP **listaInput){
	LCP (*aux) = (LCP*)malloc(sizeof(LCP));
	aux = (*listaInput);
	int end = 0;
	int tipo;
	int i = 0;

	while(aux->key >= 0 && end < 1){
		if(aux->key == 0)
			end++;
	
		tipo = obter_tipo(aux, i);
		if(tipo == 0)
			printf("%d\n", (int)aux->info);
		else if(tipo == 1)
			printf("%f\n", (float*)aux->info);
		else if(tipo == 2)
			printf("%c\n", (char)aux->info);
		else if(tipo == 3)
			printf("%s\n", (char*)aux->info);
		else
			printf("ahhhhhh\n");
		i++;
	}
}

int main(int argc, char const *argv[]){
	LCP *lcp;
	inicializar(&lcp);

	inserir_inteiro(&lcp, 1, 10);
	inserir_inteiro(&lcp, 3, 12);
	//inserir_inteiro(&lcp, 2, 11);

	obter_tipo(&lcp, 1);
	obter_inteiro(&lcp, 1);
	obter_inteiro(&lcp, 3);
	//obter_inteiro(&lcp, 3);

	listar_elementos(&lcp);

	//inserir_p_flutuante(&lcp, 2, 3.14);
	//inserir_caracteres(&lcp, 3, 'M');
	//inserir_c_caracteres(&lcp, 5, "CADeia");

	//printf("%d\n", (int)(*lcp).info );
	//printf("%f\n", (double*)(*lcp).info );
	//printf("%c\n", (char)(*lcp).info );
	//printf("%s\n", (char*)(*lcp).info );

	return 0;
}