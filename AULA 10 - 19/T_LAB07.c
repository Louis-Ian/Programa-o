#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNOME 100
#define MAXREGISTROS 1000

typedef struct info{
	char nome[MAXNOME];
	long int matricula;
	long int numero;
	int ddd;
	char tipo[1];
} Info;

void buscar_nome(Info *agenda){

}

void inserir(Info *agenda){
	/*printf("Insira o nome: \n");
	scanf("%[^\n]", agenda->nome);
	printf("Insira a matrícula: \n");
	scanf("%ld", &agenda->matricula);
	printf("Insira o DDD: \n");
	scanf("%d", &agenda->ddd);
	printf("Insira o número: \n");
	scanf("%ld", &agenda->numero);
	*/printf("Insira o tipo: \n");
	scanf("%s", agenda->tipo);
}

void menu(Info *agenda){
	if (agenda->tipo == 'A'){
		printf("A...........\n");
	}
}

int main(int argc, char const *argv[]){
	
	Info teste;
	inserir(&teste);
	menu(&teste);

	return 0;
}