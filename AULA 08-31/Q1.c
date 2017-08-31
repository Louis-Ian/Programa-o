#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv){
	int diaNasc,mesNasc,anoNasc,diaHoje,mesHoje,anoHoje;
	int idadeAno,idade;
	int teste = 666;
	
	printf("Insira, respectivamente, dia, mês e ano do nascimento:\n");
	scanf("%d  %d  %d", &diaNasc, &mesNasc, &anoNasc);

	printf("Insira, respectivamente, dia, mês e ano de hoje:\n");
	scanf("%d  %d %d", &diaHoje, &mesHoje, &anoHoje);

	idadeAno = anoHoje - anoNasc + 1;

	idade = idadeAno*365;

	for(int i = anoNasc ; i < anoHoje ; ++i)
	{
		if ((i%4)==0 && (i%400)==0 && (i%100)!=0)
		{
			idade++ ;
		}
	}

	for (int i = 1; i < mesNasc; ++i)
	{
		if (i <= 7)
		{
			if (i % 2 == 0 && i != 2)
			{
				idade -= 30;
			}
			else if(i % 2 == 1)
			{
				idade -= 31;
			}
			else
			{
				idade -= 29;
			}
		}
		else
		{
			if (i % 2 == 0)
			{
				idade -= 31;
			}
			else if(i % 2 == 1)
			{
				idade -= 30;
			}
		}
	}

	for (int i = mesHoje; i <= 12; ++i)
	{
		if (i <= 7)
		{
			if (i % 2 == 0 && i != 2)
			{
				idade -= 30;
			}
			else if(i % 2 == 1)
			{
				idade -= 31;
			}
			else
			{
				idade -= 29;
			}
		}
		else
		{
			if (i % 2 == 0)
			{
				idade -= 31;
			}
			else if(i % 2 == 1)
			{
				idade -= 30;
			}
		}
	}

	idade += diaHoje;

	printf("Sua idade é: %d \n", idade);

	return 0;
}
