#include <stdio.h>
#include <stdlib.h>

/*
***	INTRODUÇÃO À STRING ***
*/

int main(int argc, char const *argv[])
{
	char a = 'a';
	printf("%c\n", a);

	char b[10] = "bbbbbbbbb";
	printf("%s\n", b);

	char *c = "num f0de coroi!";
	int i = 0;
	while(c[i] != '\0') // \0 = fim da string
	{
		printf("%c\n", c[i]);
		i++;
	}

	char d[5];
	scanf("%s\n", d);
	printf("você escreveu: %s\n", d);

	char *a1 = (char*)malloc(10*sizeof(char));
	i = 0;
	a1 = "letra letra";
	while(a1[i] != '\0')
	{
		printf("%c\n", a1[i]);
		i++;
	}
	printf("%d\n", i); // tamanho da string

	return 0;
}
//vai tomar no cu