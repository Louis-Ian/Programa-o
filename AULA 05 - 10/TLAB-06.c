#include <stdio.h>
#include <stdlib.h>

int str_tamanho (char *s)
{
	int tam = 0;
	while(*(s+tam) != '\0')
	{
		tam++;
	}

	return tam;
}

void str_copia (char *s, char *d)
{
	int i = 0;
	//d = (char*)malloc(str_tamanho(s)*sizeof(char));
	while(*(s+i) != '\0')
	{
		*(d+i) = *(s+i);
		i++;
	}
	//printf("%s\n", d);
}

void str_concatena (char *s, char *d)
{
	int tam = str_tamanho(s);
	tam += str_tamanho(d);
	char *V = (char*)malloc(tam*sizeof(char));

	int S = str_tamanho(s);
	int D = str_tamanho(d);
	int i = 0, j = 0;

	while(i<S)
	{
 		*(V+S+i) = *(s+i);
 		i++;
	}
	while(j<D)
	{
		*(V+j) = *(d+j);
		j++;
	}

	str_copia(V,d);
}

int main(int argc, char const *argv[])
{
	char *t1 = (char*)malloc(5*sizeof(char));
	t1 = "12345";

	char *t2 = (char*)malloc(7*sizeof(char));
	t2 = "6789011";

	char *t3 = (char*)malloc(8*sizeof(char));
	int tamanho1 = str_tamanho(t3);
	printf("tam: %d\n", tamanho1);
	printf("t1: %s\n", t1);
	printf("t2: %s\n", t2);
	printf("t3: %s\n\n", t3);

	str_copia(t1,t3);

	printf("t1: %s\n", t1);
	printf("t2: %s\n", t2);
	printf("t3: %s\n\n", t3);

	str_concatena(t2,t3);

	printf("t1: %s\n", t1);
	printf("t2: %s\n", t2);
	printf("t3: %s\n\n", t3);

	return 0;
}