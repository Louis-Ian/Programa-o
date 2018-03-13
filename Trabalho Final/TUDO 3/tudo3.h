#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

void inicializar_mapa(celula*** mapa);
void inserir_celula(celula** lista);
void criar_mapa(celula ***mapa);
void mapear(celula ***mapa);
void printmap(celula ***mapaJogador, celula ***mapaPC);
celula* acessar_coordenada(celula*** mapa, int linha, int coluna);
int range(int i,int j);
int distribuir_embarcacoes(celula ***mapa);

typedef struct no{
	char c;
	struct no* prox;
	struct no* fim;
}no;

void inicializar_fila(no** fila);
void incluir_fila(no** fila, char x);
void remover_fila(no** fila);
int tamanho_fila(no** fila);
void percorrer_fila(no** fila);
int entrada_linha(no** fila);
int entrada_coluna(no** fila);
celula* receber_coord_jogador(no** fila, celula*** mapa);
void ataque_contra_PC(celula*** mapa, int linha, int coluna);
void ataque_contra_jogador(celula*** mapa, int linha, int coluna);
celula* gerar_coord_pc(celula ***mapa);
celula* gerar_coord_pc_valida(celula ***mapa, celula* p);
celula *seguir_direcao(celula ***mapa, celula *a, int *diferenca_linha, int *diferenca_coluna);
void pc(celula ***mapa);
void limpar_mostrar(celula ***mapa);
int embarcacao( celula *a);
void atualizar_cell_pc( celula** a);
void atualizar_cell( celula** a);
int derrubou( celula* a);
celula* procurar_submarino(celula*** mapa);
int vitoria1(celula ***mapa);
int vitoria2(celula ***mapa);
void jogo(celula ***mapaPC,celula ***mapaJogador,no **fila,int *placar_humano,int *placar_pc);
void clean_mapa(celula ***mapa);
