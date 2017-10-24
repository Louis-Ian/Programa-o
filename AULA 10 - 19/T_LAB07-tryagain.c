#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNOME 100
#define MAXREGISTRO 1000

#define FALSE 0
#define TRUE 1

typedef struct agenda{
	char nome[MAXNOME+1];
	long int matricula;
	long int numero;
	int ddd;
	char tipo;
} Agenda;

void buscar_nome(Agenda *lista){
	char buscado[MAXNOME];
	int resultado = FALSE;
	int posicao = 0;
	int comparador;

	printf("Insira o nome buscado: ");
	scanf("%[^\n]", buscado);

	for(int i = 0; lista[i].ddd > 0; ++i){
		comparador = strcmp(buscado, lista[i].nome);
		if(comparador == 0){
			posicao = i;
			resultado = TRUE;
		}
	}

	if(resultado == TRUE){
		printf("%s - (%d)%ld\n", buscado, lista[posicao].ddd, lista[posicao].numero);
	}

}

void inserir_novo(){

}

void apagar_registro(){

}

void listar_agenda(){

}

int main(int argc, char const *argv[])
{
	Agenda teste;
	strcpy(teste.nome,"nome de teste");
	teste.numero = 12341234;
	teste.matricula = 989898;
	teste.ddd = 567;
	teste.tipo = 'C';

	printf("TESTE: %s - ", teste.nome);
	printf("(%d) ", teste.ddd);
	printf("%ld ", teste.numero);
	printf("M-%ld", teste.matricula);
	printf(" %c\n", teste.tipo);

	return 0;
}