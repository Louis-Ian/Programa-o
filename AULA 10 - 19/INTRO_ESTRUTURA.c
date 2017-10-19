#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNOME 100
#define MAXREGISTROS 1000

typedef struct agenda{
	unsigned long int numero;
	int ddd;
	char tipo;
	char nome[MAXNOME];
} Agenda;

int main(int argc, char const *argv[]){
	Agenda x;
	x.numero = 84255686;

	printf("%ld \n", x.numero);

	return 0;
}