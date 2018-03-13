#include "tudo3.h"

int main(){

	int placar_humano=0;
	int placar_pc=0;

	clear_screen();

	srand(time(NULL));

	no* fila;
	inicializar_fila(&fila);

	int continuar;
	printf("Deseja Jogar? [1-Sim / 0-Nao]\n");
	scanf("%d", &continuar);
	getchar();

	while(continuar==1){

		celula** mapaJogador;	
		inicializar_mapa(&mapaJogador);	
		criar_mapa(&mapaJogador);
		mapear(&mapaJogador);
		distribuir_embarcacoes(&mapaJogador);

		celula** mapaPC;
		inicializar_mapa(&mapaPC);
		criar_mapa(&mapaPC);
		mapear(&mapaPC);
		pc(&mapaPC);
		limpar_mostrar(&mapaPC);

		distribuir_embarcacoes(&mapaPC);
		printmap(&mapaJogador,&mapaPC);

		jogo(&mapaPC,&mapaJogador,&fila,&placar_humano,&placar_pc);

		clean_mapa(&mapaPC);
		clean_mapa(&mapaJogador);
		printf("Deseja continua jogando? [1-Sim / 0-Nao]\n");
		scanf("%d", &continuar);
		if(continuar==1){
			printf("Deseja Resetar o placar? [1-Sim / 0-Nao]\n");
			scanf("%d", &continuar);
			getchar();
			if(continuar==1){
				placar_humano=0;
				placar_pc=0;
			}
			continuar=1;
		}
	}

	return 0;
}