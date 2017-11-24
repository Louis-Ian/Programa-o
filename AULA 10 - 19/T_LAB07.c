#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXNOME 101
#define MAXREGISTROS 1001

typedef struct info{
	char nome[MAXNOME];
	long int matricula;
	long int numero;
	int ddd;
	char tipo[2];
} Info;

void inserir_dados(Info **lista){
	int posicao;
	for (int i = 0; i > MAXREGISTROS; ++i)
		if ((*lista)[i].ddd < 0){
			posicao = i;
			break;
		}

	printf("Insira o nome: \n");
	scanf("%[^\n]", (*lista)[posicao].nome);
	printf("Insira a matrícula: \n");
	scanf("%ld", &(*lista)[posicao].matricula);
	printf("Insira o DDD: \n");
	scanf("%d", &(*lista)[posicao].ddd);
	printf("Insira o número: \n");
	scanf("%ld", &(*lista)[posicao].numero);
	printf("Insira o tipo: \n");
	scanf("%s", (*lista)[posicao].tipo);
}

void buscar_nome(Info **lista){
	char busca[MAXNOME];
	printf("Insira o nome buscado: \n");
	scanf("%[^\n]", busca);
	int resultado = false, posicao = 0;
	int comparador;

	for (int i = 0; (*lista)[i].ddd > 0; ++i)
	{
		comparador = strcmp(busca, (*lista)[i].nome);
		if (comparador == 0){
			posicao = i;
			resultado = true;
		}
	}

	if(resultado == true){
		printf("%s - (%d)%ld\n", busca, (*lista)[posicao].ddd, (*lista)[posicao].numero);
	}
	else{
		printf("Nome não encontrado.\n");
	}
}	

void apagar_nome(Info **lista){
	char busca[MAXNOME];
	printf("Insira o nome a ser apagado: \n");
	scanf("%[^\n]",busca);
	int resultado = false, posicao = 0;
	int comparador;

	for(int i = 0; (*lista)[i].ddd > 0; ++i){
		comparador = strcmp(busca, (*lista)[i].nome);
		if(comparador == 0){
			posicao = i;
			resultado = true;
		}
	}

	if(resultado == true){
		(*lista)[posicao].numero = 0;
		(*lista)[posicao].ddd = -1;
		strcpy((*lista)[posicao].tipo,"");
		strcpy((*lista)[posicao].nome,"");
		(*lista)[posicao].matricula = 0;
	}
	else
		printf("Nome não encontrado.\n");
}

void listar_todos(Info **lista){
	int i = 0;
	while(lista[i]->ddd > 0){
		printf("%s - (%d)%ld\n", lista[i]->nome, lista[i]->ddd, lista[i]->numero);
		i++;
	}
}

void menu(char Insert, Info **lista){
	printf("Escreva 'I' para inserir um número,\n'B' para buscar um nome,\n'A' para apagar um nome salvo,\n'L' para listar os números salvos e\n'S' para sair:\n\n");

	switch(Insert){
		case 'A':
			apagar_nome(lista);
		break;
		case 'L':
			listar_todos(lista);
		break;
		case 'I':
			inserir_dados(lista);
		break;
		case 'B':
			buscar_nome(lista);
		break;
		case 'a':
			apagar_nome(lista);
		break;
		case 'l':
			listar_todos(lista);
		break;
		case 'i':
			inserir_dados(lista);
		break;
		case 'b':
			buscar_nome(lista);
		break;
	};
}

int main(int argc, char const *argv[]){
	
	/*FILE *arquivo;
	arquivo = fopen(argv[1], "rt");

	if(arquivo == NULL)
	{
		printf("Falha ao abrir arquivo.");
		return 1;
	}*/

	char *agenda[MAXREGISTROS];
	printf("Bem vindo à sua agenda:\n");
	char user;
	scanf("%c", user);

	while(user != 'S'){
		menu(user,&agenda);
	}

	return 0;
}