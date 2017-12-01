#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _lde{
	int key;
	float val;
	struct _lde **prox;
	struct _lde **ant;
} lde;

typedef struct _abb{
	int key;
	float val;
	struct _abb *esq;
	struct _abb *dir;
} abb;

void inserir_abb(abb **a, int k, float f){
	printf("entrando na inserir.\n");
	if((*a) == (NULL)){-
		printf("if NULL\n");
		abb *aux = (abb*)malloc(sizeof(abb));
		aux->esq = NULL;
		aux->dir = NULL;
		aux->key = k;
		aux->val = f;
		(*a) = aux;
		//return 0;
	}else{
		if((*a)->key != k){
			if((*a)->key > k){
				printf("a->key > k\n");
				inserir_abb((*a)->esq,k,f);
			}else{
				printf("a->key < k\n");
				inserir_abb((*a)->dir,k,f);
			}
		}else{
			printf("chave já existente.\n");
			//return 1;
		}
	}
};

int inserir_lde(){ //INCOMPLETO

};

void recebe_nTuplas(abb **a, lde ***l, int n){
	float rFlutuante;
	int rKey;

	int abbReturn;
	int ldeReturn;

/*	for(int i = 0; i < n; i++){
		do{
			rFlutuante = rand()%32000;
			rKey = rand()%32000;
		}while(((abbReturn = inserir_abb(a,rKey,rFlutuante)) == 1) || ((ldeReturn = inserir_lde(l, rKey, rFlutuante)) == 1));
	}
*/
};

void abb_tranf_vetor(abb **a, int *v){ //INCOMPLETO
	int k = 0;
	abb **aux = a;
	//while(()()){}
};

int busca_binaria_recursiva_vetor(int *v){ //INCOMPLETO

};

int busca_sequencial_vetor(int *v, int k){
	int tam_V = sizeof(v)/sizeof(int);
	for(int i = 0; i < tam_V; i++){
		if(v[i] == k){
			return 0;
		}
	}
	return 1;
};

float calcular_clock_abb(){ //CONCEITO

};

int main(int argc, char const *argv[]){
/*	clock_t tz = clock();
	for(unsigned long long int i = 0; i < 1040090000; i++){}

	clock_t tf = clock();

	printf("t0:%d\ntf:%d\nD:%.9f\n",tz,tf,((((float)tf)/CLOCKS_PER_SEC)-(((float)tz)/CLOCKS_PER_SEC)));
*/
	
	abb **teste = (abb**)malloc(sizeof(abb));
	(*teste)->key = 11;
	(*teste)->val = 1.1;
	(*teste)->esq = NULL;
	(*teste)->dir = NULL;

	inserir_abb(teste, 5, 3.5);
	printf("key:%d - val:%f\n", (*teste)->esq->key, (*teste)->esq->val);

	inserir_abb(teste, 4, 5.3);
	printf("key:%d - val:%f\n", (*teste)->esq->esq->key, (*teste)->esq->esq->val);

	return 0;
}