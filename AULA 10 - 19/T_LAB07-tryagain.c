#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNOME 100
#define MAXREGISTRO 1000

#define FALSE 0
#define TRUE 1

typedef struct agenda{
	char nome[MAXNOME+1];
	char tipo[1];
	long int matricula;
	long int numero;
	int ddd;
} Agenda;

void buscar_nome(Agenda **lista){
	printf("\n");
	char buscado[MAXNOME];
	int resultado = FALSE;
	int posicao = 0;
	int comparador;

	printf("Insira o nome buscado: ");
	scanf("%s", buscado);

	//não rodam...
	//scanf("%[^\n]", buscado);
	//gets(buscado);

	for(int i = 0; (*lista)[i].ddd > 0; ++i){
		comparador = strcmp(buscado, (*lista)[i].nome);
		if(comparador == 0){
			posicao = i;
			resultado = TRUE;
		}
	}

	if(resultado == TRUE)
		printf("RESULTADO: %s - (%d)%ld M-%ld %s\n\n", buscado, (*lista)[posicao].ddd, (*lista)[posicao].numero,(*lista)[posicao].matricula,(*lista)[posicao].tipo);
	else
		printf("RESULTADO: não encontrado.\n\n");
}

void inserir_novo(Agenda **lista){
	printf("\n");
	int brk = FALSE;
	char tipo[1];
	
	for (int i = 0; i <= MAXREGISTRO && brk == FALSE; i++){
		if ((*lista)[i].ddd == 0){
			printf("Insira o nome: \n");
			scanf("%s",(*lista)[i].nome);
			//scanf("%[^\n]",(*lista)[i].nome);
			//gets((*lista)[i].nome);

			printf("Insira a matrícula: \n");
			scanf("%ld", &(*lista)[i].matricula);
			
			printf("Insira o DDD: \n");
			scanf("%d", &(*lista)[i].ddd);
			
			printf("Insira o número: \n");
			scanf("%ld", &(*lista)[i].numero);
			
		 	printf("Insira o tipo: \n");
	//não recebe o tipo, mas não atrapalha a busca
	//	gets(tipo);
	//	strcpy((*lista)[i].tipo, tipo); 
			//gets((*lista)[i].tipo);

	//recebe o tipo, mas atrapalha(va) a busca
			scanf("%s",(*lista)[i].tipo);
	//	scanf("%s", tipo);
	//	strcpy((*lista)[i].tipo, tipo);
		  
		  brk = TRUE;
		}
	}
}

void apagar_registro(Agenda **lista){
	printf("\n");
	char busca[MAXNOME];
	int resultado = FALSE, posicao = 0;
	int comparador;

	printf("Insira o nome a ser apagado: \n");
	scanf("%s",busca);
	//scanf("%[^\n]",busca);
	//gets(busca);

	for(int i = 0; (*lista)[i].ddd > 0; i++){
		comparador = strcmp(busca, (*lista)[i].nome);
		if(comparador == 0){
			posicao = i;
			resultado = TRUE;
		}
	}

	if(resultado == TRUE){
		(*lista)[posicao].numero = 0;
		(*lista)[posicao].ddd = 0;
		strcpy((*lista)[posicao].tipo,"");
		strcpy((*lista)[posicao].nome,"");
		(*lista)[posicao].matricula = 0;
		printf("\n");
	}
	else
		printf("Nome não encontrado.\n\n");
}

void listar_agenda(Agenda **lista){
	printf("\nLISTA:\n");
	for(int i = 0; i <= MAXREGISTRO; i++)
		if((*lista)[i].ddd > 0)
			printf("%s (%d)-%ld M-%ld %s\n", (*lista)[i].nome,(*lista)[i].ddd,(*lista)[i].numero,(*lista)[i].matricula,(*lista)[i].tipo);
		printf("\n");
}

int menu(Agenda **lista){
	char Escolha[1];
	printf("Escreva: \n");
	printf("'I' para inserir um número,\n");
	printf("'B' para buscar um nome,\n");
	printf("'A' para apagar um nome salvo,\n");
	printf("'L' para listar os números salvos e\n");
	printf("'S' para sair:\n");
	scanf("%s",Escolha);

	if(strcmp(Escolha,"A") == 0 || strcmp(Escolha,"a") == 0)
			apagar_registro(lista);
	else if(strcmp(Escolha,"B") == 0 || strcmp(Escolha,"b") == 0)
			buscar_nome(lista);
	else if(strcmp(Escolha,"I") == 0 || strcmp(Escolha,"i") == 0)
			inserir_novo(lista);
	else if(strcmp(Escolha,"L") == 0 || strcmp(Escolha,"l") == 0)
			listar_agenda(lista);
	else if(strcmp(Escolha,"S") == 0 || strcmp(Escolha,"s") == 0)
			return TRUE;
	else{
		printf("Insira uma opção válida.\n");
		menu(lista);
	}
}


int main(int argc, char const *argv[]){
	
	Agenda* listaTeste = (Agenda*)malloc(MAXREGISTRO*sizeof(Agenda));
	if(listaTeste == NULL){
		printf("ERRO de memória!\n");
		return 1;
	}

	for(int i = 0; i <= MAXREGISTRO; i++)
		listaTeste[i].ddd = 0;

	if(argc == 1){
		int fim = FALSE;
		while(fim != TRUE){
			fim = menu(&listaTeste);
		}
	}

	FILE *arquivo;
	arquivo = fopen(argv[1], "rt");

	if (arquivo == NULL)
	{
		printf("Falha ao abrir arquivo.\n");
		return 1;
	}

	char c;
	char *registro = (char*)malloc(7*sizeof(char));
	char numAUX[10];
	char matAUX[10];
	char dddAUX[5];
	int countM=0;
	int countNome=0;
	int countDdd=0;
	int countNum=0;
	int i = 0;

	while((c=fgetc(arquivo)) != EOF){
		if(c != '\n'){
			*(matAUX+countM) = c;
			countM++;
		}
		else{
			listaTeste[i].matricula = atoi(matAUX);
			if(c != '\n'){
				*(listaTeste+countNome)[i].nome = c;
				countNome++;
			}
			else{
				if(c != '\n'){
					*(dddAUX+countDdd) = c;
					countDdd++;
				}
				else{
					listaTeste[i].ddd = atoi(dddAUX);
					if(c != '\n'){
						*(numAUX+countNum) = c;
						countNum++;
					}
					else{
						listaTeste[i].numero = atoi(numAUX);
						if (c != '\n')
						{
							*(listaTeste)[i].tipo = c;
							countM = 0;
							countNome = 0;
							countDdd = 0;
							countNum = 0;
						}
					}
				}
			}
		}
		i++;
	}

	fclose(arquivo);

/* TESTES: concluidos uhuu

	Agenda teste2;
	strcpy(teste2.nome,"Nome1");
	teste2.numero = 12341234;
	teste2.matricula = 989898;
	teste2.ddd = 567;
	strcpy(teste2.tipo,"C");

	listaTeste[0] = teste2;

	strcpy(teste2.nome,"Nome2");
	teste2.numero = 90456456;
	teste2.matricula = 212121;
	teste2.ddd = 777;
	strcpy(teste2.tipo,"T");

	listaTeste[1] = teste2;

	listar_agenda(&listaTeste);
	inserir_novo(&listaTeste);
	//printf("TESTE: %s - ", listaTeste[0].nome);
	//printf("(%d) ", listaTeste[0].ddd);
	//printf("%ld ", listaTeste[0].numero);
	//printf("M-%ld", listaTeste[0].matricula);
	//printf(" %s\n", listaTeste[0].tipo);
	listar_agenda(&listaTeste);
	buscar_nome(&listaTeste);
	listar_agenda(&listaTeste);
	apagar_registro(&listaTeste);
	listar_agenda(&listaTeste);
	menu(&listaTeste);
*/
	return 0;
}