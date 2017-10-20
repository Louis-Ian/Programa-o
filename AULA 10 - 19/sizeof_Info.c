#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNOME 101
#define MAXREGISTROS 1001

typedef struct info{
	char nome[MAXNOME];
	long int matricula;
	long int numero;
	int ddd;
	char tipo[2];
} Info;

int main(int argc, char const *argv[])
{
	int tam;
	tam = sizeof(Info);
	printf("%d\n", tam);
	return 0;
}