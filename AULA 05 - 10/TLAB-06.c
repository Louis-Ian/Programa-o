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

void str_E_copia (char *s, char *d)
{
	int i = 0;
	//d = (char*)malloc(str_tamanho(s)*sizeof(char));
	while(*(s+i) != '\0')
	{
		*(d+i) = *(s+i);
		i++;
	}
	*(d+i) = ' ';
	*(d+i+1) = 'e';
	*(d+i+2) = ' ';
	//printf("%s\n", d);
}

void str_concatena (char *s, char *d)
{
	int tam = str_tamanho(s);
	tam += str_tamanho(d);
	char *V = (char*)malloc((tam+1)*sizeof(char));
	
	if(V == NULL)
	{
		printf("ERRO de memória!\n");
		return (void)1;
	}

	int tamS = str_tamanho(s);
	int tamD = str_tamanho(d);
	int i = 0, j = 0;
	
	while(j<tamD)
	{
		*(V+j) = *(d+j);
		j++;
	}
	while(i<=tamS)
	{
 		*(V+j+i) = *(s+i);
 		i++;
	}
	

	str_copia(V,d);
}

void str_E_concatena (char *s, char *d)
{
	int tam = str_tamanho(s) + str_tamanho(d);
	char *V = (char*)malloc((tam+4)*sizeof(char));
	
	if(V == NULL)
	{
		printf("ERRO de memória!\n");
		return (void)1;
	}

	int tamS = str_tamanho(s);
	int tamD = str_tamanho(d);
	int i = 0, j = 0;

	while(j<tamD)
	{
		*(V+j) = *(d+j);
		j++;
	}

	*(V+j) = ' ';
	*(V+j+1) = 'e';
	*(V+j+2) = ' ';

	while(i<=tamS)
	{
 		*(V+j+i+3) = *(s+i);
 		i++;
	}

	str_copia(V,d);
}

char* switches(char *numero)
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

	if ((numero[0] == '1' && numero[1] == '0' && numero[2] == '0') || (numero[0] == '0'))//verdadeiro
	{
		str_copia(centena, numExtenso);
	}
	else
	{
		str_E_copia(centena, numExtenso);

		if (dezes < 20 && dezes > 10)
		{
			str_concatena(dezena, numExtenso);
		}
		else
		{
			str_E_concatena(dezena, numExtenso);
			str_concatena(unidade, numExtenso);
		}
	}

	return numExtenso;
}

/*
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
	
	if (argc == 1)
	{
		char *input = (char*)malloc(3*sizeof(char));

		if(input == NULL)
		{
			printf("ERRO de memória");
			return 1;
		}
		printf("Insira um número de 1 à 999: ");
		scanf("%s",input);

		char *output = switches(input);
		printf("%s\n", output);
			
		return 0;
	}

	FILE *arquivo;
	arquivo = fopen(argv[1], "rt");

	if(arquivo == NULL)
	{
		printf("Falha ao abrir arquivo.");
		return 1;
	}

	char *numExtenso2 = (char*)malloc(4*sizeof(char*));
	if(numExtenso2 == NULL)
	{
		printf("ERRO de memória!\n");
		return 1;
	}

	char **vetorMIL = (char**)malloc(1000*sizeof(char*));
	if(vetorMIL == NULL)
	{
		printf("ERRO de memória!\n");
		return 1;
	}

	int count1 = 0, count2 = 0;
	char c;
	char output2;

	while( (c = fgetc(arquivo)) != EOF ){
		if(c != '\n')
		{
			*(numExtenso2+count1) = c;
			count1++;
		}
		else
		{
			*(numExtenso2+count1) = '\0';
			output2 = switches(numExtenso2);
			*(vetorMIL+count2) = (char*)malloc(str_tamanho(output2)*sizeof(char));
		
			if(*(vetorMIL+count2) == NULL)
			{
				printf("ERRO de memória!\n");
				return 1;
			}

			str_copia(numExtenso2, *(vetorMIL+count2));

			count2++;
			count1=0;
		}
	}

	for(int i = 0; i < count1; i++)
		printf("%s. \n", *(vetorMIL+i));

	fclose(arquivo);

	return 0;
}
