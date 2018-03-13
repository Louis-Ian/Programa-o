#include <stdio.h>
#include <stdlib.h>

void *criar_vetor(int tam)
{
	void *v = malloc(tam*sizeof(double));
	return v;
}

double obter_vetor(void *mem, int x)
{
	return ((double*)mem)[x];
}

void atribuir_vetor(void *mem, int x, double valor)
{
	((double*)mem)[x] = valor;
}

void liberar_vetor(void *mem)
{
	free(mem);
}

void *criar_matriz(int tam_x, int tam_y)
{
	void *mt = malloc((tam_x*tam_y)+1*sizeof(double));
	((double*)mt)[0] = tam_x;
	return mt;
}

double obter_matriz(void *mem, int x, int y)
{
	int tam = ((double*)mem)[0];
	return((double*)mem)[x*tam+y];
}

void atribuir_matriz(void *mem, int x, int y, double valor)
{
	int tam = ((double*)mem)[0];
	((double*)mem)[x*tam+y] = valor;
}

void liberar_matriz(void *mem)
{
	free(mem);
}

int main(int narg, char *argv[]) {
	void *p_m, *p_v;
	
	p_v = criar_vetor(16);
	atribuir_vetor(p_v, 8, 456); // Atribui o valor 456 na posição 8 do vetor
	printf("A pos. 8 do vetor contém %f.\n", obter_vetor(p_v, 8));
	liberar_vetor(p_v);
	
	p_m = criar_matriz(10,10);
	atribuir_matriz(p_m, 5, 4, 12); // Atribui o valor 12 na posição (5,4)
	printf("A pos. (5,4) da matriz = %f.\n", obter_matriz(p_m, 5, 4));
	liberar_matriz(p_m);

	return EXIT_SUCCESS;
}