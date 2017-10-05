#include <stdio.h>
#include <stdlib.h>

int str_tamanho (char *s)
{
	int tam = 0;
	while(s[tam] != '\0')
	{
		tam++;
	}

	return tam;
}

void str_copia (char *s, char *d)
{
	int i = 0;
	while(s[i] != '\0')
	{
		d[i] = s[i];
		i++;
	}
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
 		*(V+i) = s[i];
 		i++;
	}
	while(j<D)
	{
		*(V+S+j) = d[j];
		j++;
	}
}

int main(int argc, char const *argv[])
{
	char t1[5] = "12345";
	printf("%s \n", t1);

	int tamanho1 = str_tamanho(t1);
	printf("%d\n", tamanho1);

	char t2[10] = "12345";
	char t3[20] = "";

	str_copia(t1,t3);

	printf("%s\n", t3);

	str_concatena(t2,t3);

	printf("%s\n", t3);

	return 0;
}