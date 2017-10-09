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
	if(V == NULL)
	{
		printf("Memória insuficiente!\n");
		return (void)1;
	}
	
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

void str_concatena_E (char *s, char *d)
{
	int tam = str_tamanho(s);
	tam += str_tamanho(d);
	char *V = (char*)malloc((tam+3)*sizeof(char));
	if(V == NULL)
	{
		printf("Memória insuficiente!\n");
		return (void)1;
	}
	
	int S = str_tamanho(s);
	int D = str_tamanho(d);
	int i = 0, j = 0;

	while(j<D)
	{
		*(V+j) = *(d+j);
		++j;
	}

	*(V+j) = " e ";
	//*(V+j+1) = "e"
	//*(V+j+2) = " ";

	while(i<S)
	{
 		*(V+S+i+3) = *(s+i);
 		i++;
	}

	str_copia(V,d);
}

char switches(char *numero)
{
	char *centena = (char*)malloc(10*sizeof(char));
	char *dezena = (char*)malloc(9*sizeof(char));
	char *unidade = (char*)malloc(6*sizeof(char));

	int dezes = (int)(*(numero+1))*10 + (int)(*(numero+2));

	char *numExtenso;

	switch (*(numero+0))
	{
		case 0:
			centena = "";
		break;

		case 1:
			if ((int)(*(numero+1))*10 + (int)(*(numero+2)) == 0 )
				centena = "cem";
			else
				centena = "cento";
		break;

		case 2:
			centena = "duzentos";
		break;

		case 3:
			centena = "trezentos";
		break;

		case 4:
			centena = "quatrocentos";
		break;

		case 5:
			centena = "quinhentos";
		break;

		case 6:
			centena = "seiscentos";
		break;

		case 7:
			centena = "setecentos";
		break;

		case 8:
			centena = "oitocentos";
		break;

		case 9:
			centena = "novecentos";
		break;
	}

	switch (*(numero+1))
	{
		case 0:
			dezena = "";
		break;

		case 2:
			dezena = "vinte";
		break;

		case 3:
			dezena = "trinta";
		break;

		case 4:
			dezena = "quarenta";
		break;

		case 5:
			dezena = "cinquenta";
		break;

		case 6:
			dezena = "sessenta";
		break;

		case 7:
			dezena = "setenta";
		break;

		case 8:
			dezena = "oitenta";
		break;

		case 9:
			dezena = "noventa";
		break;
	}

	if ((int)(*(numero+1))*10 + (int)(*(numero+2)) < 20 || (int)(*(numero+1))*10 + (int)(*(numero+2)) > 10 )
	{
		switch (dezes)
		{
			case 11:
				dezena = "onze";
			break;

			case 12:
				dezena = "doze";
			break;

			case 13:
				dezena = "treze";
			break;

			case 14:
				dezena = "catorze";
			break;

			case 15:
				dezena = "quinze";
			break;

			case 16:
				dezena = "dezesseis";
			break;

			case 17:
				dezena = "dezessete";
			break;

			case 18:
				dezena = "dezoito";
			break;

			case 19:
				dezena = "dezenove";
			break;
		}
	}
	else
	{
		switch (*(numero+2))
		{
			case 0:
				unidade = "";
			break;

			case 1:
				unidade = "um";
			break;

			case 2:
				unidade = "dois";
			break;

			case 3:
				unidade = "três";
			break;

			case 4:
				unidade = "quatro";
			break;

			case 5:
				unidade = "cinco";
			break;

			case 6:
				unidade = "seis";
			break;

			case 7:
				unidade = "sete";
			break;

			case 8:
				unidade = "oito";
			break;

			case 9:
				unidade = "nove";
			break;
		}
	}

	if (centena != "" && centena != "cem")
	{
		if (dezes < 20 || dezes > 10)
		{
			if (dezena =! "")
				str_concatena_E(dezena,numExtenso);
				str_concatena(unidade, numExtenso);
		}
		else
		{
			str_concatena(dezena, numExtenso);
		}
	}
	else
	{
		str_concatena(centena, numExtenso);
	}
		
	return (char*)numExtenso;
}

/*
void criar_extensos()
{
	char **CriaExt = (char**)malloc(1000*sizeof(char*));
	if(CriaExt == NULL)
	{
		printf("Memória insuficiente!\n");
		return (void)1;
	}
}
			*** Teste ***
	
	char *t1 = (char*)malloc(5*sizeof(char));
	t1 = "12345";

	char *t2 = (char*)malloc(7*sizeof(char));
	t2 = "67890";

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
	*/

int main(int argc, char const *argv[])
{
	char *n = "1";
	n = switches(n);
	//FILE *fArquivo = fopen("C://Intro_T-06.c","r");
	//char  = argv[1];
	//fprintf(fArquivo, "\n");
	//fclose(fArquivo);
//	char entrada[3];
//	printf("Insira um número de 1 à 999: ");
//	scanf("%s", entrada);
//	entrada = strtol(entrada,,1);
//
//	while(entrada > 0 && entrada < 1000)
//	{
//
//	}

	return 0;
}