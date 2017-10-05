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
	int j = str_tamanho(d) + 1;
	int i = 0;
	while(s[i] != '\0')
	{
		d[j] = s[i];
		j++;
		i++;
	}
}

int main(int argc, char const *argv[])
{
	char t1[10] = "0123456789";
	printf("%s\n", t1);

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