#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*		ASCII - LOCALE
#include <locale.h>
setlocale(LC_ALL,"");
mar = 177;
invisivel = 219;
*/

#define true 1
#define false 0

#define clear_screen() printf("\033[H\033[J")

typedef struct celula{
	int linha;
	int coluna;
	int existe;
	int repetido;
	int atingido;
	char conteudo;
	struct celula* dir;
	struct celula* esq;
	struct celula* top;
	struct celula* bot;

	char mostrar;
	int pc;

}celula;

void inicializar_mapa(celula*** mapa){
	(*mapa) = (celula**)malloc(12*sizeof(celula*));
	for (int i = 0; i < 12; i++){
		(*mapa)[i] = NULL;
	}
}

void inserir_celula(celula** lista){

	celula* novo = (celula*)malloc(sizeof(celula));
	novo->top = NULL;
	novo->bot = NULL;
	novo->existe = 0;
	novo->repetido = 0;
	novo->atingido = false;
	novo->conteudo = ' ';
	novo->mostrar=' ';
	novo->pc=0;

	if ((*lista) == NULL){
		(*lista) = novo;
		novo->dir = NULL;
		novo->esq = NULL;
	}else{
		novo->dir = (*lista)->dir;
		novo->esq = (*lista);
		if((*lista)->dir != NULL)
			(*lista)->dir->esq = novo;		
		(*lista)->dir = novo;
	}
}

void criar_mapa(celula ***mapa){
	celula *it3;
	celula *it;
	celula *it2;

	for (int i = 0; i < 12; ++i){

		int c=12;
		while (--c >= 0){
			inserir_celula(&((*mapa)[i]));
		}

	}

	for(int i = 0; i < 11; i++){

		it = ((*mapa)[i]);
		it2 = ((*mapa)[i+1]);

		while(it != NULL){
			it->bot = it2;
			it2->top = it;
			if(it->dir == NULL)
				it3 = it;
			if(it != NULL)
				it = it->dir;
			if(it2 != NULL)
				it2 = it2->dir;
		}

		it3->dir = ((*mapa)[i+1]);
		((*mapa)[i+1])->esq = it3;	
	}
}

void mapear(celula ***mapa){
	celula *it = ((*mapa)[0]);
	int i,j;
	i = j = 0;

	while(it != NULL){
		it->linha = i;
		it->coluna = j;
		if(it != NULL)
			it = it->dir;
		j++;
		if(j ==12){
			i++;
			j %= 12;
		}
	}
}

void printmap(celula ***mapaJogador, celula ***mapaPC){
	celula *it = (*mapaJogador)[0];
	celula *it2;
	int j = 0;
	int i = 1;

	printf("\n                 HUMANO                                           COMPUTADOR\n");
	printf("     ╔══╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╗                       ╔══╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╗\n");
	printf("     ║  ║A║B║C║D║E║F║G║H║I║J║K║L║                       ║  ║A║B║C║D║E║F║G║H║I║J║K║L║\n");

	while(it != NULL){

		if(j == 0 && i < 10)
			printf("     ║%d ",i);
		if(j == 0 && i >= 10)
			printf("     ║%d",i);

		printf("║%c",it->mostrar);
		if(it != NULL)
			it = it->dir;
		j++;

		if(j == 12){
			printf("║                       ");
			it2 = (*mapaPC)[i-1];
			int c = 12;

			while(--c >= 0){
				if(i < 10 && c == 11)
					printf("║%d ",i);
				if(i >= 10 && c == 11)
					printf("║%d",i);

				//if(it2->atingido == false)
			//		printf("║ ");
		//		else
					printf("║%c", it2->mostrar);
				
				if(it2 != NULL)
					it2 = it2->dir;
			}

			j %= 12;
			i++;
			printf("║\n");
		}
	}
	printf("     ╚══╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╝                       ╚══╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╝\n");
}

celula* acessar_coordenada(celula*** mapa, int linha, int coluna){
	celula* it = (*mapa)[linha];

	while(coluna>0){
		it = it->dir;
		coluna--;
	}

	return it;
}

int range(int i,int j){
	return i+(rand()%(j-i+1));
}

int distribuir_embarcacoes(celula ***mapa){
	int n = 9;
	int i, j, d;
	celula* it;
	while(--n >= 0){
		d = range(0,1); // 0 horizonal 1 vertical;
		if(n == 8){	//portaaviao
			if(d == 0){
				do{
				i = range(0,11);
				j = range(0,7);
				it = acessar_coordenada(mapa,i,j);
				}while(it->existe == 1 || it->dir->existe == 1 || it->dir->dir->existe == 1 || it->dir->dir->dir->existe == 1 || it->dir->dir->dir->dir->existe == 1);
				it->conteudo = '<';
				it->dir->conteudo = '#';
				it->dir->dir->conteudo = '#';
				it->dir->dir->dir->conteudo = '#';
				it->dir->dir->dir->dir->conteudo = '>';
				if(it->pc == 0) it->mostrar = '<';
				if(it->pc == 0) it->dir->mostrar = '#';
				if(it->pc == 0) it->dir->dir->mostrar = '#';
				if(it->pc == 0) it->dir->dir->dir->mostrar = '#';
				if(it->pc == 0) it->dir->dir->dir->dir->mostrar = '>';
				it->existe = 1;
				it->dir->existe = 1;
				it->dir->dir->existe = 1;
				it->dir->dir->dir->existe = 1;
				it->dir->dir->dir->dir->existe = 1;
			}else{
				do{
				i = range(0,7);
				j = range(0,11);
				it = acessar_coordenada(mapa,i,j);
				}while(it->existe == 1 || it->bot->existe == 1 || it->bot->bot->existe == 1 || it->bot->bot->bot->existe == 1 || it->bot->bot->bot->bot->existe == 1);
				it->conteudo = '^';
				it->bot->conteudo = '#';
				it->bot->bot->conteudo = '#';
				it->bot->bot->bot->conteudo = '#';
				it->bot->bot->bot->bot->conteudo = 'v';
				if(it->pc == 0) it->mostrar = '^';
				if(it->pc == 0) it->bot->mostrar = '#';
				if(it->pc == 0) it->bot->bot->mostrar = '#';
				if(it->pc == 0) it->bot->bot->bot->mostrar = '#';
				if(it->pc == 0) it->bot->bot->bot->bot->mostrar = 'v';
				it->existe = 1;
				it->bot->existe = 1;
				it->bot->bot->existe = 1;
				it->bot->bot->bot->existe = 1;
				it->bot->bot->bot->bot->existe = 1;
			}
		}
		if(n == 7 || n == 6){ //destroyer
			if(d == 0){
				do{
				i = range(0,11);
				j = range(0,9);
				it = acessar_coordenada(mapa,i,j);
				}while(it->existe == 1 || it->dir->existe == 1 || it->dir->dir->existe == 1);
				it->conteudo = '<';
				it->dir->conteudo = '#';
				it->dir->dir->conteudo = '>';
				if(it->pc == 0) it->mostrar = '<';
				if(it->pc == 0) it->dir->mostrar = '#';
				if(it->pc == 0) it->dir->dir->mostrar = '>';
				it->existe = 1;
				it->dir->existe = 1;
				it->dir->dir->existe = 1;
			}else{
				do{
				i = range(0,9);
				j = range(0,11);
				it = acessar_coordenada(mapa,i,j);
				}while(it->existe == 1 || it->bot->existe == 1 || it->bot->bot->existe == 1);
				it->conteudo = '^';
				it->bot->conteudo = '#';
				it->bot->bot->conteudo = 'v';
				if(it->pc == 0) it->mostrar = '^';
				if(it->pc == 0) it->bot->mostrar = '#';
				if(it->pc == 0) it->bot->bot->mostrar = 'v';
				it->existe = 1;
				it->bot->existe = 1;
				it->bot->bot->existe = 1;
			}
		}
		if(n == 5 || n == 4 || n == 3){ //fragata
			if(d == 0){
				do{
				i = range(0,11);
				j = range(0,10);
				it = acessar_coordenada(mapa,i,j);
				}while(it->existe == 1 || it->dir->existe == 1);
				it->conteudo = '<';
				it->dir->conteudo = '>';
				if(it->pc == 0) if(it->pc == 0) it->mostrar = '<';
				if(it->pc == 0) if(it->pc == 0) it->dir->mostrar = '>';
				it->existe = 1;
				it->dir->existe = 1;
			}else{
				do{
				i = range(0,10);
				j = range(0,11);
				it = acessar_coordenada(mapa,i,j);
				}while(it->existe == 1 || it->bot->existe == 1);
				it->conteudo = '^';
				it->bot->conteudo = 'v';
				if(it->pc == 0) it->mostrar = '^';
				if(it->pc == 0) it->bot->mostrar = 'v';
				it->existe = 1;
				it->bot->existe = 1;
			}
		}
		if(n == 2 || n == 1){ //submarino	
				do{
				i = range(0,11);
				j = range(0,11);
				it = acessar_coordenada(mapa,i,j);
				}while(it->existe == 1);
				it->conteudo = '@';	
				if(it->pc == 0) it->mostrar = '@';	
				it->existe = 1;			
		}
		if(n == 0){ //jangada	
				do{
				i = range(0,11);
				j = range(0,11);
				it = acessar_coordenada(mapa,i,j);
				}while(it->existe == 1);
				it->conteudo = '&';
				if(it->pc == 0) it->mostrar = '&';
				it->existe = 1;			
		}
	}
}

typedef struct no{
	char c;
	struct no* prox;
	struct no* fim;
}no;

void inicializar_fila(no** fila){
	(*fila) = NULL;
}

void incluir_fila(no** fila, char x){
	no* novo = malloc(sizeof(no));
	novo->c = x;
	novo->prox = NULL;
	if ((*fila) == NULL){
		(*fila) = novo;
	}else{	
		(*fila)->fim->prox = novo;
	}
	(*fila)->fim = novo;
}

void remover_fila(no** fila){
		no* i = (*fila);
		(*fila) = (*fila)->prox;
		free(i);
}

int tamanho_fila(no** fila){
	int i = 0;
	no* it = (*fila);
	while(it != NULL){
		i++;
		it = it->prox;
	}
	return i;
}

void percorrer_fila(no** fila){
	no* it = (*fila);
	while(it != NULL){
		printf("%c",it->c);
		it = it->prox;
	}
	printf("\n");
}

int entrada_linha(no** fila){
	no* it = (*fila);
	int num;
	while(it != NULL){
		if((it->c) >= '1' && (int)(it->c) <= '9'){
			num=((int)(it->c))-48-1;
			if(it->prox != NULL && ((it->prox->c) >= '0' && (it->prox->c) <= '9')){
				num++;
				num *= 10;
				num += ((int)(it->prox->c))-48-1;
				return num;
			}
		}	
		it = it->prox;
	}
	return num;
}

int entrada_coluna(no** fila){
	no* it = (*fila);
	char c;
	while(it != NULL){
		if(((it->c) >= 'A' && (it->c) <= 'L') || ((it->c) >= 'a' && (it->c) <= 'l')){
			c = it->c;
		}	
		it = it->prox;
	}
	if (c >= 'A' && c <= 'L')
		return (int)c - 65;
	else
		return (int)c - 97;
}

celula* receber_coord_jogador(no** fila, celula*** mapa){
	int okNum, okChar, ok, i;
	char *entrada = malloc(100*sizeof(char));	
	char c0, c1;
	ok = 0;

	while(ok == 0){
		printf("\nCoordenadas do bombardeio:");		
		scanf("%[^\n]",entrada);
		getchar();
		okNum = okChar = 0;

		for(i = 0; entrada[i] != '\0' && ok == 0; i++){
			
			c0 = entrada[i];
			if(okNum && okChar){
				okNum=0;
				okChar=0;
				ok=1;
			}
			
			if (c0 >= '1' && c0 <= '9'){//numero
				if(okNum){
					okNum = 0;
					ok = 1;
				}else{
					okNum = 1;
					incluir_fila(fila,c0);
					i++;
					if(entrada[i] != '\0'){
						c1 = entrada[i];
						if(!(c1 >= '0' && c1 <= '9') && okNum && okChar){
							if(c1 != ' '){
								okNum = 0;
								ok = 1;
							}
						}//ValidoXX a1... X qqr
						if(c0 == '1'){ //1X
							if(c1 >= '0' && c1 <= '2'){ //10-12
								incluir_fila(fila,c1);
								i++;
								if(entrada[i] != '\0'){
									c1 = entrada[i];
									if(c1 >= '0' && c1 <= '9' || okNum && okChar){ // XXX... ou ValidoXXX a12... X qqr
										if(c1 != ' '){
											okNum=0;
											ok = 1;
										}
									}
								}
							}
							if(c1 >= '3' && c1 <= '9'){ //13-19
								okNum = 0;
								ok = 1;
							}
						}
						if(c0 > '1' && c0 <= '9'){ //X0-X9 X>1
							if(c1 >= '0' && c1 <= '9'){
								okNum = 0;
								ok = 1;
							}
						}
					}
				}
			}

			c0=entrada[i];

			if((c0 >= 'A' && c0 <= 'Z') || (c0 >= 'a' && c0 <= 'z')){ //letrastotais
				if(((c0 >= 'A' && c0 <= 'L') || (c0 >= 'a' && c0 <= 'l')) && !okChar){ //letravalidas
					okChar=1;
					incluir_fila(fila,c0);
					if(entrada[i+1] != '\0'){
						if(okNum && okChar){
							if(entrada[i+1]!=' '){
								okNum=0;
								okChar=0;
								ok=1;
							}
						}//ValidoXXX... X qqr
					}
				}else{
					okNum=0;
					okChar=0;
					ok=1;
				}
			}

			if (okNum && okChar){
				celula* t = acessar_coordenada(mapa,entrada_linha(fila),entrada_coluna(fila));
				if(t->repetido==0){
					t->repetido=1;
					while(tamanho_fila(fila) != 0){
						remover_fila(fila);
					}
					free(entrada);
					return t;
				}
				printf("Jogada já feita - ");
			} 
		}
		ok=0;
		printf("Entrada Invalida\n");
		while(tamanho_fila(fila)!=0){
			remover_fila(fila);
		}
	}
}

void ataque_contra_PC(celula*** mapa, int linha, int coluna){
	celula* it = acessar_coordenada(mapa, linha, coluna);

	if(it->conteudo != ' '){
		it->mostrar = '*';
	}else{
		it->conteudo ='O';
		it->mostrar = 'O';
	}
	it->atingido = true;
}

void ataque_contra_jogador(celula*** mapa, int linha, int coluna){
	celula* it = acessar_coordenada(mapa, linha, coluna);
	

	if(it->mostrar != ' '){
		it->mostrar = '*';
	}else{
		it->mostrar = 'O';
	}
	it->atingido = true;
}

celula* gerar_coord_pc(celula ***mapa){
	int tentativaLinha, tentativaColuna;
	celula *it;

	do{
		tentativaLinha = range(0,11);
		tentativaColuna = range(0,11);

		it = acessar_coordenada(mapa, tentativaLinha, tentativaColuna);
	}while(it->atingido == true);

	return it;
}

celula* prox_jogada_PC(celula ***mapa,celula *jogada,int topAlredy,int botAlredy,int esqAlredy,int dirAlredy){
	int casos;

	if(topAlredy == false && botAlredy == false && esqAlredy == false && dirAlredy == false){
		casos = range(1,4);

		switch(casos){
			case 1:
				if(jogada->top->atingido == false)
					return jogada->top;
				else
					prox_jogada_PC(mapa,jogada,true,botAlredy,esqAlredy,dirAlredy);
			break;
			case 2:
				if(jogada->bot->atingido == false)
					return jogada->bot;
				else
					prox_jogada_PC(mapa,jogada,topAlredy,true,esqAlredy,dirAlredy);
			break;
			case 3:
				if(jogada->esq->atingido == false)
					return jogada->esq;
				else
					prox_jogada_PC(mapa,jogada,topAlredy,botAlredy,true,dirAlredy);
			break;
			case 4:
				if(jogada->dir->atingido == false)
					return jogada->esq;
				else
					prox_jogada_PC(mapa,jogada,topAlredy,botAlredy,esqAlredy,true);
			break;
		}
	}else if(topAlredy == true && botAlredy == false && esqAlredy == false && dirAlredy == false){
		casos = range(1,3);

		switch(casos){
			case 1:
				if(jogada->bot->atingido == false)
					return jogada->bot;
				else
					prox_jogada_PC(mapa,jogada,topAlredy,true,esqAlredy,dirAlredy);
			break;
			case 2:
				if(jogada->esq->atingido == false)
					return jogada->esq;
				else
					prox_jogada_PC(mapa,jogada,topAlredy,botAlredy,true,dirAlredy);
			break;
			case 3:
				if(jogada->dir->atingido == false)
					return jogada->esq;
				else
					prox_jogada_PC(mapa,jogada,topAlredy,botAlredy,esqAlredy,true);
			break;
		}
	}else if(topAlredy == false && botAlredy == true && esqAlredy == false && dirAlredy == false){
		casos = range(1,3);

		switch(casos){
			case 1:
				if(jogada->top->atingido == false)
					return jogada->top;
				else
					prox_jogada_PC(mapa,jogada,true,botAlredy,esqAlredy,dirAlredy);
			break;
			case 2:
				if(jogada->esq->atingido == false)
					return jogada->esq;
				else
					prox_jogada_PC(mapa,jogada,topAlredy,botAlredy,true,dirAlredy);
			break;
			case 3:
				if(jogada->dir->atingido == false)
					return jogada->esq;
				else
					prox_jogada_PC(mapa,jogada,topAlredy,botAlredy,esqAlredy,true);
			break;
		}
	}else if(topAlredy == false && botAlredy == false && esqAlredy == true && dirAlredy == false){
		casos = range(1,3);

		switch(casos){
			case 1:
				if(jogada->top->atingido == false)
					return jogada->top;
				else
					prox_jogada_PC(mapa,jogada,true,botAlredy,esqAlredy,dirAlredy);
			break;
			case 2:
				if(jogada->bot->atingido == false)
					return jogada->bot;
				else
					prox_jogada_PC(mapa,jogada,topAlredy,true,esqAlredy,dirAlredy);
			break;
			case 3:
				if(jogada->dir->atingido == false)
					return jogada->esq;
				else
					prox_jogada_PC(mapa,jogada,topAlredy,botAlredy,esqAlredy,true);
			break;
		}
	}else if(topAlredy == false && botAlredy == false && esqAlredy == false && dirAlredy == true){
		casos = range(1,3);

		switch(casos){
			case 1:
				if(jogada->top->atingido == false)
					return jogada->top;
				else
					prox_jogada_PC(mapa,jogada,true,botAlredy,esqAlredy,dirAlredy);
			break;
			case 2:
				if(jogada->bot->atingido == false)
					return jogada->bot;
				else
					prox_jogada_PC(mapa,jogada,topAlredy,true,esqAlredy,dirAlredy);
			break;
			case 3:
				if(jogada->esq->atingido == false)
					return jogada->esq;
				else
					prox_jogada_PC(mapa,jogada,topAlredy,botAlredy,true,dirAlredy);
			break;
		}
	}else if(topAlredy == true && botAlredy == true && esqAlredy == false && dirAlredy == false){
		casos = range(1,2);

		switch(casos){
			case 1:
				if(jogada->esq->atingido == false)
					return jogada->esq;
				else
					prox_jogada_PC(mapa,jogada,topAlredy,botAlredy,true,dirAlredy);
			break;
			case 2:
				if(jogada->dir->atingido == false)
					return jogada->esq;
				else
					prox_jogada_PC(mapa,jogada,topAlredy,botAlredy,esqAlredy,true);
			break;
		}
	}else if(topAlredy == true && botAlredy == false && esqAlredy == true && dirAlredy == false){
		casos = range(1,2);

		switch(casos){
			case 1:
				if(jogada->bot->atingido == false)
					return jogada->bot;
				else
					prox_jogada_PC(mapa,jogada,topAlredy,true,esqAlredy,dirAlredy);
			break;
			case 2:
				if(jogada->dir->atingido == false)
					return jogada->esq;
				else
					prox_jogada_PC(mapa,jogada,topAlredy,botAlredy,esqAlredy,true);
			break;
		}
	}else if(topAlredy == true && botAlredy == false && esqAlredy == false && dirAlredy == true){
		casos = range(1,2);

		switch(casos){
			case 1:
				if(jogada->bot->atingido == false)
					return jogada->bot;
				else
					prox_jogada_PC(mapa,jogada,topAlredy,true,esqAlredy,dirAlredy);
			break;
			case 2:
				if(jogada->esq->atingido == false)
					return jogada->esq;
				else
					prox_jogada_PC(mapa,jogada,topAlredy,botAlredy,true,dirAlredy);
			break;
		}
	}else if(topAlredy == false && botAlredy == true && esqAlredy == true && dirAlredy == false){
		casos = range(1,2);

		switch(casos){
			case 1:
				if(jogada->top->atingido == false)
					return jogada->top;
				else
					prox_jogada_PC(mapa,jogada,true,botAlredy,esqAlredy,dirAlredy);
			break;
			case 2:
				if(jogada->dir->atingido == false)
					return jogada->esq;
				else
					prox_jogada_PC(mapa,jogada,topAlredy,botAlredy,esqAlredy,true);
			break;
		}
	}else if(topAlredy == false && botAlredy == true && esqAlredy == false && dirAlredy == true){
		casos = range(1,2);

		switch(casos){
			case 1:
				if(jogada->top->atingido == false)
					return jogada->top;
				else
					prox_jogada_PC(mapa,jogada,true,botAlredy,esqAlredy,dirAlredy);
			break;
			case 2:
				if(jogada->esq->atingido == false)
					return jogada->esq;
				else
					prox_jogada_PC(mapa,jogada,topAlredy,botAlredy,true,dirAlredy);
			break;
		}
	}else if(topAlredy == false && botAlredy == false && esqAlredy == true && dirAlredy == true){
		casos = range(1,2);

		switch(casos){
			case 1:
				if(jogada->top->atingido == false)
					return jogada->top;
				else
					prox_jogada_PC(mapa,jogada,true,botAlredy,esqAlredy,dirAlredy);
			break;
			case 2:
				if(jogada->bot->atingido == false)
					return jogada->bot;
				else
					prox_jogada_PC(mapa,jogada,topAlredy,true,esqAlredy,dirAlredy);
			break;
		}
	}else if(topAlredy == false){
		if(jogada->top->atingido == false)
			return jogada->top;
		else
			prox_jogada_PC(mapa,jogada,true,botAlredy,esqAlredy,dirAlredy);
	}else if(botAlredy == false){
		if(jogada->bot->atingido == false)
			return jogada->bot;
		else
			prox_jogada_PC(mapa,jogada,topAlredy,true,esqAlredy,dirAlredy);
	}else if(esqAlredy == false){
		if(jogada->esq->atingido == false)
			return jogada->esq;
		else
			prox_jogada_PC(mapa,jogada,topAlredy,botAlredy,true,dirAlredy);
	}else if(dirAlredy == false){
		if(jogada->dir->atingido == false)
			return jogada->dir;
		else
			prox_jogada_PC(mapa,jogada,topAlredy,botAlredy,esqAlredy,true);
	}else{
		jogada = gerar_coord_pc(mapa);
		return jogada;
	}
}

int vitoria(celula **mapa){
	celula *it=(*mapa);
	while(it!=NULL){
		if(it->conteudo!=' ' || it->conteudo!='*'  || it->conteudo!='O') return 0;
		it=it->dir;
	}
	return 1;
}
void pc(celula ***mapa){
	celula *it=(*mapa)[0];
	while(it!=NULL){
		it->pc=1;
		it=it->dir;
	}
}
//?????

void limpar_mostrar(celula ***mapa){
	celula *it=(*mapa)[0];
	while(it!=NULL){
		it->mostrar=' ';
		it=it->dir;
	}
}

int embarcacao( celula *a){
	if( a -> conteudo == '&') return 1;
	if( a-> conteudo == '@') return 2;
	if ( a -> conteudo == '<'){
		if (a->dir->conteudo == '>') return 3;
		if (a->dir->conteudo == '#' && a->dir->dir->conteudo=='>') return 4;
		if (a->dir->conteudo == '#' && a->dir->dir->conteudo=='#') return 5;
	}
	if ( a -> conteudo == '>'){
		if (a->esq->conteudo == '<') return 6;
		if (a->esq->conteudo == '#' && a->esq->esq->conteudo=='<') return 7;
		if (a->esq->conteudo == '#' && a->esq->esq->conteudo=='#') return 8;
	}
	if( a->conteudo== '#'){
		if(a->dir->conteudo=='>' && a->esq->conteudo=='<') return 9;
		if((a->dir->conteudo=='#' && a->esq->conteudo=='#') || (a->esq->conteudo=='<' && a->dir->conteudo=='#') || (a->esq->conteudo=='#' && a->dir->conteudo=='>')) return 10;
	}
	if ( a -> conteudo == '^'){
		if (a->bot->conteudo == 'v') return 11;
		if (a->bot->conteudo == '#' && a->bot->bot->conteudo=='v') return 12;
		if (a->bot->conteudo == '#' && a->bot->bot->conteudo=='#') return 13;
	}
	if ( a -> conteudo == 'v'){
		if (a->top->conteudo == '^') return 14;
		if (a->top->conteudo == '#' && a->top->top->conteudo=='^') return 15;
		if (a->top->conteudo == '#' && a->top->top->conteudo=='#') return 16;
	}
	if( a->conteudo== '#'){
		if(a->top->conteudo=='^' && a->bot->conteudo=='v') return 17;
		if((a->top->conteudo=='#' && a->bot->conteudo=='#' )|| (a->bot->conteudo=='v' && a->top->conteudo=='#' )||( a->bot->conteudo=='#' && a->top->conteudo=='^')) return 18;
	}
}

int atualizar_cell_pc( celula** a){
	int tipo=embarcacao(*a);
	if(tipo==1){
		if((*a)->mostrar=='*'){
			printf("O Humano atingiu a jangada\n"); (*a)->mostrar=(*a)->conteudo;
			return 1;
		}
	}
	if(tipo==2){
		if((*a)->mostrar=='*'){
			printf("O Humano derrubou um submarino\n"); (*a)->mostrar=(*a)->conteudo;
			return 2;
		}
	}
	if(tipo==3){ 
		if ((*a)->mostrar=='*' && (*a)->dir->mostrar=='*') {
			(*a)->mostrar=(*a)->conteudo;
			(*a)->dir->mostrar=(*a)->dir->conteudo;
			printf("O Humano derrubou uma fragata\n");
			return 3;
		}
	}
	if(tipo==4){
		if ((*a)->mostrar=='*' && (*a)->dir->mostrar=='*' && (*a)->dir->dir->mostrar=='*') {
			(*a)->mostrar=(*a)->conteudo;
			(*a)->dir->mostrar=(*a)->dir->conteudo;
			(*a)->dir->dir->mostrar=(*a)->dir->dir->conteudo;
			printf("O Humano derrubou um destroyer\n");		
			return 4;
		}
	}
	if(tipo==5){
		if ((*a)->mostrar=='*' && (*a)->dir->mostrar=='*' && (*a)->dir->dir->mostrar=='*' && (*a)->dir->dir->dir->mostrar=='*' && (*a)->dir->dir->dir->dir->mostrar=='*') {
			(*a)->mostrar=(*a)->conteudo;
			(*a)->dir->mostrar=(*a)->dir->conteudo;
			(*a)->dir->dir->mostrar=(*a)->dir->dir->conteudo;
			(*a)->dir->dir->dir->mostrar=(*a)->dir->dir->dir->conteudo;
			(*a)->dir->dir->dir->dir->mostrar=(*a)->dir->dir->dir->dir->conteudo;
			printf("O Humano derrubou um portaaviao\n");
			return 5;
		}
	}
	if(tipo==6){ 
		if ((*a)->mostrar=='*' && (*a)->esq->mostrar=='*') {
			(*a)->mostrar=(*a)->conteudo;
			(*a)->esq->mostrar=(*a)->esq->conteudo;
			printf("O Humano derrubou uma fragata\n");
			return 3;
		}
	}
	if(tipo==7){
		if ((*a)->mostrar=='*' && (*a)->esq->mostrar=='*' && (*a)->esq->esq->mostrar=='*') {
			(*a)->mostrar=(*a)->conteudo;
			(*a)->esq->mostrar=(*a)->esq->conteudo;
			(*a)->esq->esq->mostrar=(*a)->esq->esq->conteudo;
			printf("O Humano derrubou um destroyer\n");		
			return 4;
		}
	}
	if(tipo==8){
		if ((*a)->mostrar=='*' && (*a)->esq->mostrar=='*' && (*a)->esq->esq->mostrar=='*' && (*a)->esq->esq->esq->mostrar=='*' && (*a)->esq->esq->esq->esq->mostrar=='*') {
			(*a)->mostrar=(*a)->conteudo;
			(*a)->esq->mostrar=(*a)->esq->conteudo;
			(*a)->esq->esq->mostrar=(*a)->esq->esq->conteudo;
			(*a)->esq->esq->esq->mostrar=(*a)->esq->esq->esq->conteudo;
			(*a)->esq->esq->esq->esq->mostrar=(*a)->esq->esq->esq->esq->conteudo;
			printf("O Humano derrubou um portaaviao\n");
			return 5;
		}
	}

	if(tipo==9){
		if((*a)->dir->mostrar=='*' && (*a)->esq->mostrar=='*' && (*a)->mostrar=='*'){
			(*a)->dir->mostrar=(*a)->dir->conteudo;
			(*a)->esq->mostrar=(*a)->esq->conteudo;
			(*a)->mostrar=(*a)->conteudo;
			printf("O Humano derrubou um destroyer\n");
			return 4;
		}
	}

	if(tipo==10){
		if((*a)->dir->conteudo=='#' && (*a)->esq->conteudo=='#' && (*a)->dir->mostrar=='*' && (*a)->mostrar=='*' && (*a)->esq->mostrar=='*' && (*a)->dir->dir->mostrar=='*' && (*a)->esq->esq->mostrar=='*'){
			(*a)->mostrar=(*a)->conteudo;
			(*a)->dir->mostrar=(*a)->dir->conteudo;
			(*a)->esq->mostrar=(*a)->esq->conteudo;
			(*a)->dir->dir->mostrar=(*a)->dir->dir->conteudo;
			(*a)->esq->esq->mostrar=(*a)->esq->esq->conteudo;
			printf("O Humano derrubou um portaaviao\n");
			return 5;
		}
		if((*a)->dir->conteudo=='#' && (*a)->esq->conteudo=='<' && (*a)->dir->mostrar=='*' && (*a)->mostrar=='*' && (*a)->esq->mostrar=='*' && (*a)->dir->dir->mostrar=='*' && (*a)->dir->dir->dir->mostrar=='*'){
			(*a)->mostrar=(*a)->conteudo;
			(*a)->dir->mostrar=(*a)->dir->conteudo;
			(*a)->esq->mostrar=(*a)->esq->conteudo;
			(*a)->dir->dir->mostrar=(*a)->dir->dir->conteudo;
			(*a)->dir->dir->dir->mostrar=(*a)->dir->dir->dir->conteudo;
			printf("O Humano derrubou um portaaviao\n");
			return 5;
		}
		if((*a)->dir->conteudo=='>' && (*a)->esq->conteudo=='#' && (*a)->dir->mostrar=='*' && (*a)->mostrar=='*' && (*a)->esq->mostrar=='*' && (*a)->esq->esq->esq->mostrar=='*' && (*a)->esq->esq->mostrar=='*')
		{
			(*a)->mostrar=(*a)->conteudo;
			(*a)->dir->mostrar=(*a)->dir->conteudo;
			(*a)->esq->mostrar=(*a)->esq->conteudo;
			(*a)->esq->esq->mostrar=(*a)->esq->esq->conteudo;
			(*a)->esq->esq->esq->mostrar=(*a)->esq->esq->esq->conteudo;	
			printf("O Humano derrubou um portaaviao\n");
			return 5;
		}
	}
	if(tipo==11){ 
		if ((*a)->mostrar=='*' && (*a)->bot->mostrar=='*') {
			(*a)->mostrar=(*a)->conteudo;
			(*a)->bot->mostrar=(*a)->bot->conteudo;
			printf("O Humano derrubou uma fragata\n");
			return 3;
		}
	}
	if(tipo==12){
		if ((*a)->mostrar=='*' && (*a)->bot->mostrar=='*' && (*a)->bot->bot->mostrar=='*') {
			(*a)->mostrar=(*a)->conteudo;
			(*a)->bot->mostrar=(*a)->bot->conteudo;
			(*a)->bot->bot->mostrar=(*a)->bot->bot->conteudo;
			printf("O Humano derrubou um destroyer\n");		
			return 4;
		}
	}
	if(tipo==13){
		if ((*a)->mostrar=='*' && (*a)->bot->mostrar=='*' && (*a)->bot->bot->mostrar=='*' && (*a)->bot->bot->bot->mostrar=='*' && (*a)->bot->bot->bot->bot->mostrar=='*') {
			(*a)->mostrar=(*a)->conteudo;
			(*a)->bot->mostrar=(*a)->bot->conteudo;
			(*a)->bot->bot->mostrar=(*a)->bot->bot->conteudo;
			(*a)->bot->bot->bot->mostrar=(*a)->bot->bot->bot->conteudo;
			(*a)->bot->bot->bot->bot->mostrar=(*a)->bot->bot->bot->bot->conteudo;
			printf("O Humano derrubou um portaaviao\n");
			return 5;
		}
	}
	if(tipo==14){ 
		if ((*a)->mostrar=='*' && (*a)->top->mostrar=='*') {
			(*a)->mostrar=(*a)->conteudo;
			(*a)->top->mostrar=(*a)->top->conteudo;
			printf("O Humano derrubou uma fragata\n");
			return 3;
		}
	}
	if(tipo==15){
		if ((*a)->mostrar=='*' && (*a)->top->mostrar=='*' && (*a)->top->top->mostrar=='*') {
			(*a)->mostrar=(*a)->conteudo;
			(*a)->top->mostrar=(*a)->top->conteudo;
			(*a)->top->top->mostrar=(*a)->top->top->conteudo;
			printf("O Humano derrubou um destroyer\n");		
			return 4;
		}
	}
	if(tipo==16){
		if ((*a)->mostrar=='*' && (*a)->top->mostrar=='*' && (*a)->top->top->mostrar=='*' && (*a)->top->top->top->mostrar=='*' && (*a)->top->top->top->top->mostrar=='*') {
			(*a)->mostrar=(*a)->conteudo;
			(*a)->top->mostrar=(*a)->top->conteudo;
			(*a)->top->top->mostrar=(*a)->top->top->conteudo;
			(*a)->top->top->top->mostrar=(*a)->top->top->top->conteudo;
			(*a)->top->top->top->top->mostrar=(*a)->top->top->top->top->conteudo;
			printf("O Humano derrubou um portaaviao\n");
			return 5;
		}
	}
	if(tipo==17){
		if((*a)->bot->mostrar=='*' && (*a)->top->mostrar=='*' && (*a)->mostrar=='*'){
			(*a)->bot->mostrar=(*a)->bot->conteudo;
			(*a)->top->mostrar=(*a)->top->conteudo;
			(*a)->mostrar=(*a)->conteudo;
			printf("O Humano derrubou um destroyer\n");
			return 4;
		}
	}

	if(tipo==18){
		if((*a)->bot->conteudo=='#' && (*a)->top->conteudo=='#' && (*a)->bot->mostrar=='*' && (*a)->mostrar=='*' && (*a)->top->mostrar=='*' && (*a)->bot->bot->mostrar=='*' && (*a)->top->top->mostrar=='*'){
			(*a)->mostrar=(*a)->conteudo;
			(*a)->bot->mostrar=(*a)->bot->conteudo;
			(*a)->top->mostrar=(*a)->top->conteudo;
			(*a)->bot->bot->mostrar=(*a)->bot->bot->conteudo;
			(*a)->top->top->mostrar=(*a)->top->top->conteudo;
			printf("O Humano derrubou um portaaviao\n");
			return 5;
		}
		if((*a)->bot->conteudo=='#' && (*a)->top->conteudo=='^' && (*a)->bot->mostrar=='*' && (*a)->mostrar=='*' && (*a)->top->mostrar=='*' && (*a)->bot->bot->mostrar=='*' && (*a)->bot->bot->bot->mostrar=='*'){
			(*a)->mostrar=(*a)->conteudo;
			(*a)->bot->mostrar=(*a)->bot->conteudo;
			(*a)->top->mostrar=(*a)->top->conteudo;
			(*a)->bot->bot->mostrar=(*a)->bot->bot->conteudo;
			(*a)->bot->bot->bot->mostrar=(*a)->bot->bot->bot->conteudo;
			printf("O Humano derrubou um portaaviao\n");
			return 5;
		}
		if((*a)->bot->conteudo=='v' && (*a)->top->conteudo=='#' && (*a)->bot->mostrar=='*' && (*a)->mostrar=='*' && (*a)->top->mostrar=='*' && (*a)->top->top->top->mostrar=='*' && (*a)->top->top->mostrar=='*'){
			(*a)->mostrar=(*a)->conteudo;
			(*a)->bot->mostrar=(*a)->bot->conteudo;
			(*a)->top->mostrar=(*a)->top->conteudo;
			(*a)->top->top->mostrar=(*a)->top->top->conteudo;
			(*a)->top->top->top->mostrar=(*a)->top->top->top->conteudo;	
			printf("O Humano derrubou um portaaviao\n");
			return 5;
		}
	}
	return 0;
}

int atualizar_cell( celula** a){
	int tipo=embarcacao(*a);
	if(tipo==1){
		if((*a)->mostrar=='*')printf("O PC atingiu a jangada\n");
		return 1;
	}
	if(tipo==2){
		if((*a)->mostrar=='*')printf("O PC derrubou um submarino\n");
		return 2;
	}
	if(tipo==3){ 
		if ((*a)->mostrar=='*' && (*a)->dir->mostrar=='*') {
			printf("O PC derrubou uma fragata\n");
			return 3;
		}
	}
	if(tipo==4){
		if ((*a)->mostrar=='*' && (*a)->dir->mostrar=='*' && (*a)->dir->dir->mostrar=='*') {
			printf("O PC derrubou um destroyer\n");
			return 4;	
		}
	}
	if(tipo==5){
		if ((*a)->mostrar=='*' && (*a)->dir->mostrar=='*' && (*a)->dir->dir->mostrar=='*' && (*a)->dir->dir->dir->mostrar=='*' && (*a)->dir->dir->dir->dir->mostrar=='*') {
			printf("O PC derrubou um portaaviao\n");
			return 5;
		}
	}
	if(tipo==6){ 
		if ((*a)->mostrar=='*' && (*a)->esq->mostrar=='*') {
			printf("O PC derrubou uma fragata\n");
			return 3;
		}
	}
	if(tipo==7){
		if ((*a)->mostrar=='*' && (*a)->esq->mostrar=='*' && (*a)->esq->esq->mostrar=='*') {
			printf("O PC derrubou um destroyer\n");
			return 4;		
		}
	}
	if(tipo==8){
		if ((*a)->mostrar=='*' && (*a)->esq->mostrar=='*' && (*a)->esq->esq->mostrar=='*' && (*a)->esq->esq->esq->mostrar=='*' && (*a)->esq->esq->esq->esq->mostrar=='*') {
			printf("O PC derrubou um portaaviao\n");
			return 5;
		}
	}

	if(tipo==9){
		if((*a)->dir->mostrar=='*' && (*a)->esq->mostrar=='*' && (*a)->mostrar=='*'){
			printf("O PC derrubou um destroyer\n");
			return 4;
		}
	}

	if(tipo==10){
		if((*a)->dir->conteudo=='#' && (*a)->esq->conteudo=='#' && (*a)->dir->mostrar=='*' && (*a)->mostrar=='*' && (*a)->esq->mostrar=='*' && (*a)->dir->dir->mostrar=='*' && (*a)->esq->esq->mostrar=='*'){
			printf("O PC derrubou um portaaviao\n");
			return 5;
		}
		if((*a)->dir->conteudo=='#' && (*a)->esq->conteudo=='<' && (*a)->dir->mostrar=='*' && (*a)->mostrar=='*' && (*a)->esq->mostrar=='*' && (*a)->dir->dir->mostrar=='*' && (*a)->dir->dir->dir->mostrar=='*'){
			printf("O PC derrubou um portaaviao\n");
			return 5;
		}
		if((*a)->dir->conteudo=='>' && (*a)->esq->conteudo=='#' && (*a)->dir->mostrar=='*' && (*a)->mostrar=='*' && (*a)->esq->mostrar=='*' && (*a)->esq->esq->esq->mostrar=='*' && (*a)->esq->esq->mostrar=='*')
		{
			printf("O PC derrubou um portaaviao\n");
			return 5;
		}
	}
	if(tipo==11){ 
		if ((*a)->mostrar=='*' && (*a)->bot->mostrar=='*') {
			printf("O PC derrubou uma fragata\n");
			return 3;
		}
	}
	if(tipo==12){
		if ((*a)->mostrar=='*' && (*a)->bot->mostrar=='*' && (*a)->bot->bot->mostrar=='*') {
			printf("O PC derrubou um destroyer\n");		
			return 4;
		}
	}
	if(tipo==13){
		if ((*a)->mostrar=='*' && (*a)->bot->mostrar=='*' && (*a)->bot->bot->mostrar=='*' && (*a)->bot->bot->bot->mostrar=='*' && (*a)->bot->bot->bot->bot->mostrar=='*') {
			printf("O PC derrubou um portaaviao\n");
			return 5;
		}
	}
	if(tipo==14){ 
		if ((*a)->mostrar=='*' && (*a)->top->mostrar=='*') {
			printf("O PC derrubou uma fragata\n");
			return 3;
		}
	}
	if(tipo==15){
		if ((*a)->mostrar=='*' && (*a)->top->mostrar=='*' && (*a)->top->top->mostrar=='*') {
			printf("O PC derrubou um destroyer\n");		
			return 4;
		}
	}
	if(tipo==16){
		if ((*a)->mostrar=='*' && (*a)->top->mostrar=='*' && (*a)->top->top->mostrar=='*' && (*a)->top->top->top->mostrar=='*' && (*a)->top->top->top->top->mostrar=='*') {
			printf("O PC derrubou um portaaviao\n");
			return 5;
		}
	}
	if(tipo==17){
		if((*a)->bot->mostrar=='*' && (*a)->top->mostrar=='*' && (*a)->mostrar=='*'){
			printf("O PC derrubou um destroyer\n");
			return 4;
		}
	}

	if(tipo==18){
		if((*a)->bot->conteudo=='#' && (*a)->top->conteudo=='#' && (*a)->bot->mostrar=='*' && (*a)->mostrar=='*' && (*a)->top->mostrar=='*' && (*a)->bot->bot->mostrar=='*' && (*a)->top->top->mostrar=='*'){
			printf("O PC derrubou um portaaviao\n");
			return 5;
		}
		if((*a)->bot->conteudo=='#' && (*a)->top->conteudo=='^' && (*a)->bot->mostrar=='*' && (*a)->mostrar=='*' && (*a)->top->mostrar=='*' && (*a)->bot->bot->mostrar=='*' && (*a)->bot->bot->bot->mostrar=='*'){
			printf("O PC derrubou um portaaviao\n");
			return 5;
		}
		if((*a)->bot->conteudo=='v' && (*a)->top->conteudo=='#' && (*a)->bot->mostrar=='*' && (*a)->mostrar=='*' && (*a)->top->mostrar=='*' && (*a)->top->top->top->mostrar=='*' && (*a)->top->top->mostrar=='*'){
			printf("O PC derrubou um portaaviao\n");
			return 5;
		}
	}

	return 0;
}

int destruir_sub_PC(celula ***mapa){
	celula *aux = acessar_coordenada(mapa,0,0);
	int destruido = false;

	for(int i = 0; destruido == false && i < 144; i++){
		if(aux->conteudo == '@' && aux->atingido == false){
			destruido = true;
			aux->atingido = true;
			aux->mostrar = '@';
			return true;
		}
		else{
			aux = aux->dir;
		}
	}
	return false;
}

int destruir_sub_H(celula ***mapa){
	celula *aux = acessar_coordenada(mapa,0,0);
	int destruido = false;

	for(int i = 0; destruido == false && i < 144; i++){
		if(aux->conteudo == '@' && aux->atingido == false){
			destruido = true;
			aux->atingido = true;
			aux->mostrar = '*';
			return true;
		}
		else{
			aux = aux->dir;
		}
	}
	return false;
}

int main(){

	
	char ultimaJogadaH0 = ' ';
	int ultimaJogadaH1 = 0, ultimaJogadaH2 = 0;
	
	char ultimaJogadaPC0 = ' ';
	int ultimaJogadaPC1 = 0, ultimaJogadaPC2 = 0;

	int primeiraRodada = true;

	clear_screen();

	srand(time(NULL));
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

	no* fila;
	inicializar_fila(&fila);

	celula* jogadaH = (celula*)malloc(sizeof(celula));
	celula* jogadaPC = (celula*)malloc(sizeof(celula));

	int hitH = true;
	int hitPC = true;

	int jangada  = 1;
	int portaaviao = 1;
	int submarino = 2;
	int destroyer = 2;
	int fragata = 3;

	int placarH = 0;
	int placarPC = 0;
	int totalEmbPC = 8;
	int totalEmbH = 8;

	int seqPC = false;
	int top,bot,esq,dir;
	int efeitoJangada;

	while(totalEmbPC > 0 && totalEmbH > 0){
		hitH = true;
		hitPC = true;
		seqPC = false;

		while(hitH == true){
			jogadaH = receber_coord_jogador(&fila,&mapaPC);
			//clear_screen();

			if(jogadaH->conteudo == ' ' || jogadaH->conteudo == '&'){
				hitH = false;
				if(jogadaH->conteudo == '&' && jogadaH->atingido == false){
					efeitoJangada = destruir_sub_H(&mapaJogador);
					if(efeitoJangada == true){
						totalEmbH--;
					}
				}
			}

			ultimaJogadaH0 = (char)jogadaH->coluna+65;
			if(jogadaH->linha < 9){
				ultimaJogadaH2 = jogadaH->linha+1;
				ultimaJogadaH1 = 0;
			}else{
				ultimaJogadaH1 = 1;
				ultimaJogadaH2 = jogadaH->linha - 9;
			}
			
			ataque_contra_PC(&mapaPC, jogadaH->linha, jogadaH->coluna);
			placarH = atualizar_cell_pc(&jogadaH);
			if(placarH != 0 && placarH != 1){
				totalEmbPC -= 1;
			}

			printmap(&mapaJogador, &mapaPC);
			printf("\n Último ataque - Jogador: %c%d%d ", ultimaJogadaH0, ultimaJogadaH1, ultimaJogadaH2);
			printf("\n Último ataque - Computador: %c%d%d \n",ultimaJogadaPC0,ultimaJogadaPC1,ultimaJogadaPC2);
			printf(" Embarcações PC: %d\n", totalEmbPC);
			printf(" Embarcações Humano: %d\n", totalEmbH);
		}
		while(hitPC == true){
			top = 0;
			bot = 0;
			esq = 0;
			dir = 0;
			
			if(seqPC == false){
				jogadaPC = gerar_coord_pc(&mapaJogador);
			}
			else{
				if(jogadaPC->top == NULL){
					if(jogadaPC->esq == NULL){
						jogadaPC = prox_jogada_PC(&mapaJogador,jogadaPC,true,jogadaPC->bot->atingido,true,jogadaPC->dir->atingido);
					}else{
						jogadaPC = prox_jogada_PC(&mapaJogador,jogadaPC,true,jogadaPC->bot->atingido,jogadaPC->esq->atingido,jogadaPC->dir->atingido);
					}
				}else if(jogadaPC->bot == NULL){
					if(jogadaPC->dir == NULL){
						jogadaPC = prox_jogada_PC(&mapaJogador,jogadaPC,jogadaPC->top->atingido,true,jogadaPC->esq->atingido,true);
					}else{
						jogadaPC = prox_jogada_PC(&mapaJogador,jogadaPC,jogadaPC->top->atingido,true,jogadaPC->esq->atingido,jogadaPC->dir->atingido);
					}
				}else{
					jogadaPC = prox_jogada_PC(&mapaJogador,jogadaPC,jogadaPC->top->atingido,jogadaPC->bot->atingido,jogadaPC->esq->atingido,jogadaPC->dir->atingido);
				}
			}
			//clear_screen();

			if(jogadaPC->conteudo == ' ' || jogadaPC->conteudo == '&'){
				hitPC = false;
				if(jogadaPC->conteudo == '&' && jogadaPC->atingido == false){
					efeitoJangada = destruir_sub_PC(&mapaPC);
					if(efeitoJangada == true){
						totalEmbPC--;
					}
				}
			}else{
				seqPC = true;
			}

			ultimaJogadaPC0 = (char)jogadaPC->coluna+65;
			if(jogadaPC->linha < 9){
				ultimaJogadaPC2 = jogadaPC->linha+1;
				ultimaJogadaPC1 = 0;
			}else{
				ultimaJogadaPC1 = 1;
				ultimaJogadaPC2 = jogadaPC->linha - 9;
			}

			ataque_contra_jogador(&mapaJogador, jogadaPC->linha, jogadaPC->coluna);
			placarPC = atualizar_cell(&jogadaPC);
			if(placarPC != 0 && placarPC != 1){
				totalEmbH -= 1;
			}

			printmap(&mapaJogador, &mapaPC);
			printf("\n Último ataque - Jogador: %c%d%d ", ultimaJogadaH0, ultimaJogadaH1, ultimaJogadaH2);
			printf("\n Último ataque - Computador: %c%d%d \n", ultimaJogadaPC0, ultimaJogadaPC1, ultimaJogadaPC2);
			printf(" Embarcações PC: %d\n", totalEmbPC);
			printf(" Embarcações Humano: %d\n", totalEmbH);
		}
	}

	return 0;
}
