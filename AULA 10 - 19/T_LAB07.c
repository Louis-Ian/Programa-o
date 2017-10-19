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

void inserir_numero( Agenda agenda, long int numeroInsert = -1){
	if (numeroInsert == -1){
		long int numeroScan;
		scanf("%ld" , &numeroScan);
		agenda.numero = numeroScan;
	}
	else
		agenda.numero = numeroInsert;
}

void inserir_ddd( Agenda agenda, int dddInsert){
	if (!dddInsert){
		int dddScan;
		scanf("%d" , &dddScan);
		agenda.ddd = dddScan;
	}
	else
		agenda.ddd = dddInsert;
}

void inserir_matricula( Agenda agenda, long int matriculaInsert){
	if (!matriculaInsert){
		long int matriculaScan;
		scanf("%ld" , &matriculaScan);
		agenda.matricula = matriculaScan;
	}
	else
		agenda.matricula = matriculaInsert;
}

void inserir_tipo( Agenda agenda, char tipoInsert){
	if (!tipoInsert){
		char tipoScan;
		scanf("%c" , &tipoScan);
		agenda.tipo = tipoScan;
	}
	else
		agenda.tipo = tipoInsert;
}

void inserir_nome( Agenda agenda, char nomeInsert){
	if (!nomeInsert){
		char nomeScan[MAXNOME];
		scanf("%s",nomeScan);
		*agenda.nome = nomeScan;
	}
	else
		*agenda.nome = nomeInsert;
}

int main(int argc, char const *argv[]){
	

	Agenda x;
	inserir_numero(x);

	printf("%ld \n", x.numero);

	return 0;
}