#include <stdio.h>
#include <stdlib.h>

#define false 1
#define true 0

typedef struct listaCircularPolimorfica{
	struct listaCircularPolimorfica *prox;
	struct listaCircularPolimorfica *ante;
	void *info;
	int chave;
	int tipo;
} LCP;

void inicializar(LCP **listaInput/*ponteiro pra ponteiro*/){
	(*listaInput) = (LCP*)malloc(sizeof(LCP));
	(*listaInput)->chave = 0;
	(*listaInput)->tipo = 0;
	(*listaInput)->prox = (*listaInput);
	(*listaInput)->ante = (*listaInput);
}

int main(int argc, char const *argv[])
{
	LCP *listaP;
	inicializar(&listaP);

	printf("%d\n", listaP->chave);
	return 0;
}
