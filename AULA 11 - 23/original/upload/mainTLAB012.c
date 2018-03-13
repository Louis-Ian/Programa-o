#include <stdio.h>
#include <stdlib.h>
#include "TLAB012.h"

int main(int argc, char const *argv[])
{
//	int pausa;

	ArvBB *teste;
	inicializar(teste);
	inserir_recursivo(teste,4,10.0);
	listar_elementos(teste);

//	scanf("%d",pausa);
	return 0;
}