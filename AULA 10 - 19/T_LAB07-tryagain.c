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

void buscar_nome(Agenda **lista){
	char buscado[MAXNOME];
	int resultado = FALSE;
	int posicao = 0;
	int comparador;

	printf("Insira o nome buscado: ");
	scanf("%[^\n]", buscado);

	for(int i = 0; (*lista)[i].ddd > 0; ++i){
		comparador = strcmp(buscado, (*lista)[i].nome);
		if(comparador == 0){
			posicao = i;
			resultado = TRUE;
		}
	}

	if(resultado == TRUE){
		printf("%s - (%d)%ld\n", buscado, (*lista)[posicao].ddd, (*lista)[posicao].numero);
	}

}

void inserir_novo(Agenda **lista){
	int posicao;
	char tipo[1];
	char nome[MAXNOME];

	for (int i = 0; i > MAXREGISTRO; ++i)
		if ((*lista)[i].ddd < 0){
			posicao = i;
			break;
		}

//	printf("Insira o nome: \n");
//	scanf("%[^\n]",nome);
//	strcpy(nome, &(*lista)[posicao].nome);

	printf("Insira a matrícula: \n");
	scanf("%ld", &(*lista)[posicao].matricula);
	
	printf("Insira o DDD: \n");
	scanf("%d", &(*lista)[posicao].ddd);
	
	printf("Insira o número: \n");
	scanf("%ld", &(*lista)[posicao].numero);
	
//	printf("Insira o tipo: \n");
//	scanf("%s", tipo);
//	strcpy(tipo, &(*lista)[posicao].tipo);
}

void apagar_registro(Agenda **lista){

}

void listar_agenda(Agenda **lista){

}

//void inicializar_agenda(Agenda **lista){
//	for(int i = 0; i < MAXREGISTRO; ++i){
//		&(*lista+i)->ddd = 0;
//		&(*lista)[i].ddd = 0;
//	}
//}

int main(int argc, char const *argv[])
{
	Agenda *teste1 = malloc(MAXREGISTRO*sizeof(Agenda));
	
	for(int i = 0; i < MAXREGISTRO; ++i){
//		&(*lista+i)->ddd = 0;
		(*teste1)[i].ddd = 0;
	}

	Agenda teste2;
	strcpy(teste2.nome,"nome de teste");
	teste2.numero = 12341234;
	teste2.matricula = 989898;
	teste2.ddd = 567;
	teste2.tipo = 'C';

	teste1[0] = teste2;

	printf("TESTE: %s - ", teste2.nome);
	printf("(%d) ", teste2.ddd);
	printf("%ld ", teste2.numero);
	printf("M-%ld", teste2.matricula);
	printf(" %c\n", teste2.tipo);

	buscar_nome(&teste1);
	inserir_novo(&teste1);

	printf("TESTE: %s - ", teste1[1].nome);
	printf("(%d) ", teste1[1].ddd);
	printf("%ld ", teste1[1].numero);
	printf("M-%ld", teste1[1].matricula);
	printf(" %c\n", teste1[1].tipo);

	return 0;
}