#include "tudo3.h"

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

	printf("                 HUMANO                                               COMPUTADOR\n");
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
celula* gerar_coord_pc_valida(celula ***mapa, celula* p){
	int tentativaLinha, tentativaColuna;
	celula *it;

	int i;
	do{	

		tentativaLinha = range(-1,1);
		tentativaColuna = range(-1,1);
		i=range(0,1); // 0 horizontal 1 vertical
		if(i){
			if(p->linha+tentativaLinha>=0 && p->linha+tentativaLinha<=11 )it=acessar_coordenada(mapa,p->linha+tentativaLinha,p->coluna);
		}else{
			if(p->coluna+tentativaColuna>=0 && p->coluna+tentativaColuna<=11 ) it=acessar_coordenada(mapa,p->linha,p->coluna+tentativaColuna);
		}

	}while(it->atingido == true);

	return it;
}
celula *seguir_direcao(celula ***mapa, celula *a, int *diferenca_linha, int *diferenca_coluna){
		//printf("linha : %d columa: %d\n", a->linha, a->coluna );
		//printf("diferenca_linha%d diferenca_coluna%d\n", (*diferenca_linha), (*diferenca_coluna) );
		//printf("mostrando %c conteudo %c\n", a->mostrar, a->conteudo );
	if((a->linha+(*diferenca_linha))<0 ||(a->linha+(*diferenca_linha))>11 || (a->coluna+(*diferenca_coluna))<0 ||(a->coluna+(*diferenca_coluna))>11 || a->mostrar=='O' ||a->mostrar=='&'){
		//printf("muda de direcao1\n");
		(*diferenca_coluna)=(*diferenca_coluna)*(-1);
		(*diferenca_linha)=(*diferenca_linha)*(-1);
	}

	return acessar_coordenada(mapa,(a->linha+*diferenca_linha),(a->coluna+*diferenca_coluna));
}

void pc(celula ***mapa){
	celula *it=(*mapa)[0];
	while(it!=NULL){
		it->pc=1;
		it=it->dir;
	}
}
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

void atualizar_cell_pc( celula** a){
	int tipo=embarcacao(*a);
	if(tipo==1){
		if((*a)->mostrar=='*'){printf("O Humano atingiu a jangada\n"); (*a)->mostrar=(*a)->conteudo;}
	}
	if(tipo==2){
		if((*a)->mostrar=='*'){printf("O Humano derrubou um submarino\n"); (*a)->mostrar=(*a)->conteudo;}
	}
	if(tipo==3){ 
		if ((*a)->mostrar=='*' && (*a)->dir->mostrar=='*') {
			(*a)->mostrar=(*a)->conteudo;
			(*a)->dir->mostrar=(*a)->dir->conteudo;
			printf("O Humano derrubou uma fragata\n");
		}
	}
	if(tipo==4){
		if ((*a)->mostrar=='*' && (*a)->dir->mostrar=='*' && (*a)->dir->dir->mostrar=='*') {
			(*a)->mostrar=(*a)->conteudo;
			(*a)->dir->mostrar=(*a)->dir->conteudo;
			(*a)->dir->dir->mostrar=(*a)->dir->dir->conteudo;
			printf("O Humano derrubou um destroyer\n");		
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
		}
	}
	if(tipo==6){ 
		if ((*a)->mostrar=='*' && (*a)->esq->mostrar=='*') {
			(*a)->mostrar=(*a)->conteudo;
			(*a)->esq->mostrar=(*a)->esq->conteudo;
			printf("O Humano derrubou uma fragata\n");
		}
	}
	if(tipo==7){
		if ((*a)->mostrar=='*' && (*a)->esq->mostrar=='*' && (*a)->esq->esq->mostrar=='*') {
			(*a)->mostrar=(*a)->conteudo;
			(*a)->esq->mostrar=(*a)->esq->conteudo;
			(*a)->esq->esq->mostrar=(*a)->esq->esq->conteudo;
			printf("O Humano derrubou um destroyer\n");		
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
		}
	}

	if(tipo==9){
		if((*a)->dir->mostrar=='*' && (*a)->esq->mostrar=='*' && (*a)->mostrar=='*'){
			(*a)->dir->mostrar=(*a)->dir->conteudo;
			(*a)->esq->mostrar=(*a)->esq->conteudo;
			(*a)->mostrar=(*a)->conteudo;
			printf("O Humano derrubou um destroyer\n");
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
		}
		if((*a)->dir->conteudo=='#' && (*a)->esq->conteudo=='<' && (*a)->dir->mostrar=='*' && (*a)->mostrar=='*' && (*a)->esq->mostrar=='*' && (*a)->dir->dir->mostrar=='*' && (*a)->dir->dir->dir->mostrar=='*'){
			(*a)->mostrar=(*a)->conteudo;
			(*a)->dir->mostrar=(*a)->dir->conteudo;
			(*a)->esq->mostrar=(*a)->esq->conteudo;
			(*a)->dir->dir->mostrar=(*a)->dir->dir->conteudo;
			(*a)->dir->dir->dir->mostrar=(*a)->dir->dir->dir->conteudo;
			printf("O Humano derrubou um portaaviao\n");
		}
		if((*a)->dir->conteudo=='>' && (*a)->esq->conteudo=='#' && (*a)->dir->mostrar=='*' && (*a)->mostrar=='*' && (*a)->esq->mostrar=='*' && (*a)->esq->esq->esq->mostrar=='*' && (*a)->esq->esq->mostrar=='*')
		{
			(*a)->mostrar=(*a)->conteudo;
			(*a)->dir->mostrar=(*a)->dir->conteudo;
			(*a)->esq->mostrar=(*a)->esq->conteudo;
			(*a)->esq->esq->mostrar=(*a)->esq->esq->conteudo;
			(*a)->esq->esq->esq->mostrar=(*a)->esq->esq->esq->conteudo;	
			printf("O Humano derrubou um portaaviao\n");
		}
	}
	if(tipo==11){ 
		if ((*a)->mostrar=='*' && (*a)->bot->mostrar=='*') {
			(*a)->mostrar=(*a)->conteudo;
			(*a)->bot->mostrar=(*a)->bot->conteudo;
			printf("O Humano derrubou uma fragata\n");
		}
	}
	if(tipo==12){
		if ((*a)->mostrar=='*' && (*a)->bot->mostrar=='*' && (*a)->bot->bot->mostrar=='*') {
			(*a)->mostrar=(*a)->conteudo;
			(*a)->bot->mostrar=(*a)->bot->conteudo;
			(*a)->bot->bot->mostrar=(*a)->bot->bot->conteudo;
			printf("O Humano derrubou um destroyer\n");		
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
		}
	}
	if(tipo==14){ 
		if ((*a)->mostrar=='*' && (*a)->top->mostrar=='*') {
			(*a)->mostrar=(*a)->conteudo;
			(*a)->top->mostrar=(*a)->top->conteudo;
			printf("O Humano derrubou uma fragata\n");
		}
	}
	if(tipo==15){
		if ((*a)->mostrar=='*' && (*a)->top->mostrar=='*' && (*a)->top->top->mostrar=='*') {
			(*a)->mostrar=(*a)->conteudo;
			(*a)->top->mostrar=(*a)->top->conteudo;
			(*a)->top->top->mostrar=(*a)->top->top->conteudo;
			printf("O Humano derrubou um destroyer\n");		
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
		}
	}
	if(tipo==17){
		if((*a)->bot->mostrar=='*' && (*a)->top->mostrar=='*' && (*a)->mostrar=='*'){
			(*a)->bot->mostrar=(*a)->bot->conteudo;
			(*a)->top->mostrar=(*a)->top->conteudo;
			(*a)->mostrar=(*a)->conteudo;
			printf("O Humano derrubou um destroyer\n");
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
		}
		if((*a)->bot->conteudo=='#' && (*a)->top->conteudo=='^' && (*a)->bot->mostrar=='*' && (*a)->mostrar=='*' && (*a)->top->mostrar=='*' && (*a)->bot->bot->mostrar=='*' && (*a)->bot->bot->bot->mostrar=='*'){
			(*a)->mostrar=(*a)->conteudo;
			(*a)->bot->mostrar=(*a)->bot->conteudo;
			(*a)->top->mostrar=(*a)->top->conteudo;
			(*a)->bot->bot->mostrar=(*a)->bot->bot->conteudo;
			(*a)->bot->bot->bot->mostrar=(*a)->bot->bot->bot->conteudo;
			printf("O Humano derrubou um portaaviao\n");
		}
		if((*a)->bot->conteudo=='v' && (*a)->top->conteudo=='#' && (*a)->bot->mostrar=='*' && (*a)->mostrar=='*' && (*a)->top->mostrar=='*' && (*a)->top->top->top->mostrar=='*' && (*a)->top->top->mostrar=='*'){
			(*a)->mostrar=(*a)->conteudo;
			(*a)->bot->mostrar=(*a)->bot->conteudo;
			(*a)->top->mostrar=(*a)->top->conteudo;
			(*a)->top->top->mostrar=(*a)->top->top->conteudo;
			(*a)->top->top->top->mostrar=(*a)->top->top->top->conteudo;	
			printf("O Humano derrubou um portaaviao\n");
		}
	}
}
void atualizar_cell( celula** a){
	int tipo=embarcacao(*a);
	if(tipo==1){
		if((*a)->mostrar=='*')printf("O PC atingiu a jangada\n"); 
	}
	if(tipo==2){
		if((*a)->mostrar=='*')printf("O PC derrubou um submarino\n");
	}
	if(tipo==3){ 
		if ((*a)->mostrar=='*' && (*a)->dir->mostrar=='*') {
			printf("O PC derrubou uma fragata\n");
		}
	}
	if(tipo==4){
		if ((*a)->mostrar=='*' && (*a)->dir->mostrar=='*' && (*a)->dir->dir->mostrar=='*') {
			printf("O PC derrubou um destroyer\n");		
		}
	}
	if(tipo==5){
		if ((*a)->mostrar=='*' && (*a)->dir->mostrar=='*' && (*a)->dir->dir->mostrar=='*' && (*a)->dir->dir->dir->mostrar=='*' && (*a)->dir->dir->dir->dir->mostrar=='*') {
			printf("O PC derrubou um portaaviao\n");
		}
	}
	if(tipo==6){ 
		if ((*a)->mostrar=='*' && (*a)->esq->mostrar=='*') {
			printf("O PC derrubou uma fragata\n");
		}
	}
	if(tipo==7){
		if ((*a)->mostrar=='*' && (*a)->esq->mostrar=='*' && (*a)->esq->esq->mostrar=='*') {
			printf("O PC derrubou um destroyer\n");		
		}
	}
	if(tipo==8){
		if ((*a)->mostrar=='*' && (*a)->esq->mostrar=='*' && (*a)->esq->esq->mostrar=='*' && (*a)->esq->esq->esq->mostrar=='*' && (*a)->esq->esq->esq->esq->mostrar=='*') {
			printf("O PC derrubou um portaaviao\n");
		}
	}

	if(tipo==9){
		if((*a)->dir->mostrar=='*' && (*a)->esq->mostrar=='*' && (*a)->mostrar=='*'){
			printf("O PC derrubou um destroyer\n");
		}
	}

	if(tipo==10){
		if((*a)->dir->conteudo=='#' && (*a)->esq->conteudo=='#' && (*a)->dir->mostrar=='*' && (*a)->mostrar=='*' && (*a)->esq->mostrar=='*' && (*a)->dir->dir->mostrar=='*' && (*a)->esq->esq->mostrar=='*'){
			printf("O PC derrubou um portaaviao\n");
		}
		if((*a)->dir->conteudo=='#' && (*a)->esq->conteudo=='<' && (*a)->dir->mostrar=='*' && (*a)->mostrar=='*' && (*a)->esq->mostrar=='*' && (*a)->dir->dir->mostrar=='*' && (*a)->dir->dir->dir->mostrar=='*'){
			printf("O PC derrubou um portaaviao\n");
		}
		if((*a)->dir->conteudo=='>' && (*a)->esq->conteudo=='#' && (*a)->dir->mostrar=='*' && (*a)->mostrar=='*' && (*a)->esq->mostrar=='*' && (*a)->esq->esq->esq->mostrar=='*' && (*a)->esq->esq->mostrar=='*')
		{
			printf("O PC derrubou um portaaviao\n");
		}
	}
	if(tipo==11){ 
		if ((*a)->mostrar=='*' && (*a)->bot->mostrar=='*') {
			printf("O PC derrubou uma fragata\n");
		}
	}
	if(tipo==12){
		if ((*a)->mostrar=='*' && (*a)->bot->mostrar=='*' && (*a)->bot->bot->mostrar=='*') {
			printf("O PC derrubou um destroyer\n");		
		}
	}
	if(tipo==13){
		if ((*a)->mostrar=='*' && (*a)->bot->mostrar=='*' && (*a)->bot->bot->mostrar=='*' && (*a)->bot->bot->bot->mostrar=='*' && (*a)->bot->bot->bot->bot->mostrar=='*') {
			printf("O PC derrubou um portaaviao\n");
		}
	}
	if(tipo==14){ 
		if ((*a)->mostrar=='*' && (*a)->top->mostrar=='*') {
			printf("O PC derrubou uma fragata\n");
		}
	}
	if(tipo==15){
		if ((*a)->mostrar=='*' && (*a)->top->mostrar=='*' && (*a)->top->top->mostrar=='*') {
			printf("O PC derrubou um destroyer\n");		
		}
	}
	if(tipo==16){
		if ((*a)->mostrar=='*' && (*a)->top->mostrar=='*' && (*a)->top->top->mostrar=='*' && (*a)->top->top->top->mostrar=='*' && (*a)->top->top->top->top->mostrar=='*') {
			printf("O PC derrubou um portaaviao\n");
		}
	}
	if(tipo==17){
		if((*a)->bot->mostrar=='*' && (*a)->top->mostrar=='*' && (*a)->mostrar=='*'){
			printf("O PC derrubou um destroyer\n");
		}
	}

	if(tipo==18){
		if((*a)->bot->conteudo=='#' && (*a)->top->conteudo=='#' && (*a)->bot->mostrar=='*' && (*a)->mostrar=='*' && (*a)->top->mostrar=='*' && (*a)->bot->bot->mostrar=='*' && (*a)->top->top->mostrar=='*'){
			printf("O PC derrubou um portaaviao\n");
		}
		if((*a)->bot->conteudo=='#' && (*a)->top->conteudo=='^' && (*a)->bot->mostrar=='*' && (*a)->mostrar=='*' && (*a)->top->mostrar=='*' && (*a)->bot->bot->mostrar=='*' && (*a)->bot->bot->bot->mostrar=='*'){
			printf("O PC derrubou um portaaviao\n");
		}
		if((*a)->bot->conteudo=='v' && (*a)->top->conteudo=='#' && (*a)->bot->mostrar=='*' && (*a)->mostrar=='*' && (*a)->top->mostrar=='*' && (*a)->top->top->top->mostrar=='*' && (*a)->top->top->mostrar=='*'){
			printf("O PC derrubou um portaaviao\n");
		}
	}
}

int derrubou( celula* a){
	int tipo=embarcacao(a);
	if(tipo==1){
		if(a->mostrar=='*'){
			return 1;
		}
	}
	if(tipo==2){
		if(a->mostrar=='*'){
			return 1;
		}
	}
	if(tipo==3){ 
		if (a->mostrar=='*' && a->dir->mostrar=='*') {
			return 1;
		}
	}
	if(tipo==4){
		if (a->mostrar=='*' && a->dir->mostrar=='*' && a->dir->dir->mostrar=='*') {
				return 1;	
		}
	}
	if(tipo==5){
		if (a->mostrar=='*' && a->dir->mostrar=='*' && a->dir->dir->mostrar=='*' && a->dir->dir->dir->mostrar=='*' && a->dir->dir->dir->dir->mostrar=='*') {
			return 1;
		}
	}
	if(tipo==6){ 
		if (a->mostrar=='*' && a->esq->mostrar=='*') {
			return 1;
		}
	}
	if(tipo==7){
		if (a->mostrar=='*' && a->esq->mostrar=='*' && a->esq->esq->mostrar=='*') {
			return 1;		
		}
	}
	if(tipo==8){
		if (a->mostrar=='*' && a->esq->mostrar=='*' && a->esq->esq->mostrar=='*' && a->esq->esq->esq->mostrar=='*' && a->esq->esq->esq->esq->mostrar=='*') {
			return 1;
		}
	}

	if(tipo==9){
		if(a->dir->mostrar=='*' && a->esq->mostrar=='*' && a->mostrar=='*'){
			return 1;
		}
	}

	if(tipo==10){
		if(a->dir->conteudo=='#' && a->esq->conteudo=='#' && a->dir->mostrar=='*' && a->mostrar=='*' && a->esq->mostrar=='*' && a->dir->dir->mostrar=='*' && a->esq->esq->mostrar=='*'){
			return 1;
		}
		if(a->dir->conteudo=='#' && a->esq->conteudo=='<' && a->dir->mostrar=='*' && a->mostrar=='*' && a->esq->mostrar=='*' && a->dir->dir->mostrar=='*' && a->dir->dir->dir->mostrar=='*'){
			return 1;
		}
		if(a->dir->conteudo=='>' && a->esq->conteudo=='#' && a->dir->mostrar=='*' && a->mostrar=='*' && a->esq->mostrar=='*' && a->esq->esq->esq->mostrar=='*' && a->esq->esq->mostrar=='*')
		{
			return 1;
		}
	}
	if(tipo==11){ 
		if (a->mostrar=='*' && a->bot->mostrar=='*') {
			return 1;
		}
	}
	if(tipo==12){
		if (a->mostrar=='*' && a->bot->mostrar=='*' && a->bot->bot->mostrar=='*') {
			return 1;		
		}
	}
	if(tipo==13){
		if (a->mostrar=='*' && a->bot->mostrar=='*' && a->bot->bot->mostrar=='*' && a->bot->bot->bot->mostrar=='*' && a->bot->bot->bot->bot->mostrar=='*') {
			return 1;
		}
	}
	if(tipo==14){ 
		if (a->mostrar=='*' && a->top->mostrar=='*') {
			return 1;
		}
	}
	if(tipo==15){
		if (a->mostrar=='*' && a->top->mostrar=='*' && a->top->top->mostrar=='*') {
				return 1;	
		}
	}
	if(tipo==16){
		if (a->mostrar=='*' && a->top->mostrar=='*' && a->top->top->mostrar=='*' && a->top->top->top->mostrar=='*' && a->top->top->top->top->mostrar=='*') {
			return 1;
		}
	}
	if(tipo==17){
		if(a->bot->mostrar=='*' && a->top->mostrar=='*' && a->mostrar=='*'){
			return 1;
		}
	}

	if(tipo==18){
		if(a->bot->conteudo=='#' && a->top->conteudo=='#' && a->bot->mostrar=='*' && a->mostrar=='*' && a->top->mostrar=='*' && a->bot->bot->mostrar=='*' && a->top->top->mostrar=='*'){
			return 1;
		}
		if(a->bot->conteudo=='#' && a->top->conteudo=='^' && a->bot->mostrar=='*' && a->mostrar=='*' && a->top->mostrar=='*' && a->bot->bot->mostrar=='*' && a->bot->bot->bot->mostrar=='*'){
			return 1;
		}
		if(a->bot->conteudo=='v' && a->top->conteudo=='#' && a->bot->mostrar=='*' && a->mostrar=='*' && a->top->mostrar=='*' && a->top->top->top->mostrar=='*' && a->top->top->mostrar=='*'){
			return 1;
		}
	}
return 0;
}
	
celula* procurar_submarino(celula*** mapa){
	celula *it=(*mapa)[0];
	while(it!=NULL){
		if(it->conteudo == '@') return it;
		it=it->dir;
	}
	return it;
}

int vitoria1(celula ***mapa){
	celula *it=(*mapa)[0];
	while(it!=NULL){
		if(it->mostrar!=' ' && it->mostrar!='*'  && it->mostrar!='O' && it->mostrar!='&') return 0;
		it=it->dir;
	}
	return 1;
}
int vitoria2(celula ***mapa){
	int k=0;
	celula *it=(*mapa)[0];
	while(it!=NULL){
		if(it->mostrar!=' ' && it->mostrar!='*'  && it->mostrar!='O') k++;
		it=it->dir;
	}
	if(k==20) return 1;
	return 0;
}

void jogo(celula ***mapaPC,celula ***mapaJogador,no **fila,int *placar_humano,int *placar_pc){
	char ultimaJogadaH0;
	int ultimaJogadaH1, ultimaJogadaH2;
	
	char ultimaJogadaPC0;
	int ultimaJogadaPC1, ultimaJogadaPC2;

	int v=0;
	celula* jogadasalva;
	int diferenca_linha,diferenca_coluna;
	diferenca_coluna=diferenca_linha=0;

	int jogar_novamente_pc, jogar_novamente_humano;
	jogar_novamente_humano=jogar_novamente_pc=0;

	celula *jangada;

	celula* jogadaH;
	celula* jogadaPC;

	while(1){
		
			if(jogar_novamente_pc==0){
			jogadaH = receber_coord_jogador(fila,mapaPC);
			//clear_screen();

			ultimaJogadaH0 = (char)jogadaH->coluna+65;
			if(jogadaH->linha < 9){
				ultimaJogadaH2 = jogadaH->linha+1;
				ultimaJogadaH1 = 0;
			}else{
				ultimaJogadaH1 = 1;
				ultimaJogadaH2 = jogadaH->linha - 9;
			}		
			ataque_contra_PC(mapaPC, jogadaH->linha, jogadaH->coluna);
			}	
			if(jogar_novamente_humano==0){

			if(v==1) {
				if(diferenca_linha==0 && diferenca_coluna==0){
					jogadaPC = gerar_coord_pc_valida(mapaJogador,jogadasalva);
					if(jogadaPC->mostrar!=' ' && jogadaPC->mostrar!='O') {
						diferenca_linha=jogadaPC->linha - jogadasalva->linha;
						diferenca_coluna=jogadaPC->coluna - jogadasalva->coluna;
					}
				} 
				else{
					int c=100;
					do{
						c--;
						printf("c");
						jogadaPC=seguir_direcao(mapaJogador,jogadaPC,&diferenca_linha,&diferenca_coluna);
					}while(jogadaPC->atingido==true && c>=0);
					if(c==-1){
						jogadaPC=gerar_coord_pc_valida(mapaJogador,jogadasalva);
					}

				}
			}else{
				jogadaPC = gerar_coord_pc(mapaJogador);
				if(jogadaPC->conteudo!=' '){
					jogadasalva=jogadaPC;
					v=1;
				}
			}
			ultimaJogadaPC0 = (char)jogadaPC->coluna+65;
			if(jogadaPC->linha < 9){
				ultimaJogadaPC2 = jogadaPC->linha+1;
				ultimaJogadaPC1 = 0;
			}else{
				ultimaJogadaPC1 = 1;
				ultimaJogadaPC2 = jogadaPC->linha - 9;
			}

			ataque_contra_jogador(mapaJogador, jogadaPC->linha, jogadaPC->coluna);
			}

			if(derrubou(jogadaPC)){
				v=0;
				diferenca_coluna=0;
				diferenca_linha=0;
				jogar_novamente_pc=1;
				if(jogadaPC->conteudo=='&'){ //acerta jangada
					jogadaPC->mostrar='&';
					jogar_novamente_pc=0;
					jangada=procurar_submarino(mapaPC);
					if(jangada!=NULL){
						jangada->atingido=1;
						jangada->existe=1;
						jangada->repetido=1;
						ataque_contra_PC(mapaPC,jangada->linha,jangada->coluna);
						atualizar_cell_pc(&jangada);
					}
				}else{
				}
			}
			else{
				jogar_novamente_pc=0;
			} 
			atualizar_cell(&jogadaPC);


			if(derrubou(jogadaH)){
				jogar_novamente_humano=1;
				if(jogadaH->conteudo=='&'){ //acerta jangada
					jogar_novamente_humano=0;
					jangada=procurar_submarino(mapaJogador);
					if(jangada!=NULL){
						jangada->atingido=1;
						jangada->existe=1;
						jangada->repetido=1;
						ataque_contra_jogador(mapaJogador,jangada->linha,jangada->coluna);
						atualizar_cell(&jangada);
					}
				}else{
				}
			}else{
				jogar_novamente_humano=0;
			}
			atualizar_cell_pc(&jogadaH);

			if(jogar_novamente_humano && jogar_novamente_pc){
				jogar_novamente_pc=0;
				jogar_novamente_humano=0;
			}
			printmap(mapaJogador, mapaPC);
			printf("\n Último ataque - Jogador: %c%d%d \n", ultimaJogadaH0, ultimaJogadaH1, ultimaJogadaH2);
			printf("\n Último ataque - Computador: %c%d%d \n", ultimaJogadaPC0, ultimaJogadaPC1, ultimaJogadaPC2);

			if (vitoria1(mapaJogador)){
				printf("O PC venceu!\n");
				(*placar_pc)++;
				printf("Placar Geral: Humano - %d X %d -PC \n", (*placar_humano), (*placar_pc));
				return ;
			}

			if (vitoria2(mapaPC)){
				printf("O Humano venceu!\n");
				*placar_humano++;
				printf("Placar Geral: Humano - %d X %d -PC \n", *placar_humano, *placar_pc);
				return ;
			}

		}
	}

void clean_mapa(celula ***mapa){
	celula* it=(*mapa)[0];
	while(it!=NULL){
		free(it);
		it=it->dir;
	}
}