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
	struct _abb *prox;
	struct _abb *ant;
} abb;

void recebe_nTuplas(abb **a, lde l, int n){
	abb *aIN = (abb*)malloc(sizeof(abb));
	lde **lIN = (lde**)malloc(sizeof(lde));
	int keyIN;
	float valIN;

	for(int i = 0; i < n; i++){
		scanf("%d %f", keyIN, valIN);
	}
};

void abb_tranf_vetor(abb a, int *v){

};

int busca_recursiva_vetor(int *v){

};

int busca_sequencial_vetor(int *v){

};

int main(int argc, char const *argv[]){
	clock_t tz = clock();
	for(unsigned long long int i = 0; i < 1040090000; i++){

	}
	clock_t tf = clock();

	printf("t0:%d\ntf:%d\nD:%.9f\n",tz,tf,((((float)tf)/CLOCKS_PER_SEC)-(((float)tz)/CLOCKS_PER_SEC)));
	return 0;
}