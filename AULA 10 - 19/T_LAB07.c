#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNOME 100
#define MAXREGISTROS 1000

typedef struct agenda{
	long int numero;
	long int matricula;
	int ddd;
	char tipo;
	char nome[MAXNOME];
} Agenda;

void inserir_numero( Agenda agenda, long int numero){

}

void inserir_ddd( Agenda agenda, int ddd){

}

void inserir_matricula( Agenda agenda, long int matricula){

}

int main(int argc, char const *argv[]){
	

	Agenda x;
	x.numero = 84255686;

	printf("%ld \n", x.numero);

	return 0;
}