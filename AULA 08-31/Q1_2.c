#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv){
	int diaNasc,mesNasc,anoNasc;
	int diaHoje,mesHoje,anoHoje;
	int idade=0, anos, dias;

	printf("Insira, respectivamente, dia, mês e ano do nascimento:\n");
	scanf("%d  %d  %d", &diaNasc, &mesNasc, &anoNasc);

	printf("Insira, respectivamente, dia, mês e ano de hoje:\n");
	scanf("%d  %d %d", &diaHoje, &mesHoje, &anoHoje);

	anos = anoHoje - anoNasc;
	dias = diaHoje;

	if (mesNasc <= 7)
		{
			if (mesNasc % 2 == 0 && mesNasc != 2)
			{
				idade += 30;
			}
			else if(mesNasc % 2 == 1)
			{
				idade += 31;
			}
			else if(mesNasc == 2)
			{
				if (((anoNasc%4)==0) && ((anoNasc%400)==0) && ((anoNasc%100)!=0))
				{
					idade += 29;
				}
				else{
					idade += 28;
				}
			}
		}
		else
		{
			if (diaNasc % 2 == 0)
			{
				idade += 31;
			}
			else if(diaNasc % 2 == 1)
			{
				idade += 30;
			}
		}

	idade += diaNasc;

	for (int i = mesNasc + 1; i <= 12; ++i)
	{
		if (i <= 7)
		{
			if (i % 2 == 0 && i != 2)
			{
				idade += 30;
			}
			else if(i % 2 == 1)
			{
				idade += 31;
			}
			else if(i == 2)
			{
				if (((anoNasc%4)==0) && ((anoNasc%400)==0) && ((anoNasc%100)!=0))
				{
					idade += 29;
				}
				else{
					idade += 28;
				}
			}
		}
		else
		{
			if (i % 2 == 0)
			{
				idade += 31;
			}
			else if(i % 2 == 1)
			{
				idade += 30;
			}
		}
	}

	for (int i = 1; i < mesHoje; ++i)
	{
		if (i <= 7)
		{
			if (i % 2 == 0 && i != 2)
			{
				idade += 30;
			}
			else if(i % 2 == 1)
			{
				idade += 31;
			}
			else if(i == 2)
			{
				if (((anoHoje%4)==0) && ((anoHoje%400)==0) && ((anoHoje%100)!=0))
				{
					idade += 29;
				}
				else
				{
					idade += 28;
				}
			}
		}
		else
		{
			if (i % 2 == 0)
			{
				idade += 31;
			}
			else if(i % 2 == 1)
			{
				idade += 30;
			}
		}
	}

	if (anos >1)
	{
		for (int j = anoNasc + 1; j < anoHoje ; ++j)
		{
			for (int i = 1; i <= 12; ++i)
			{
				if (i <= 7)
				{
					if (i % 2 == 0 && i != 2)
					{
						idade += 30;
					}
					else if(i % 2 == 1)
					{
						idade += 31;
					}
					else if(i == 2)
					{
						if (((anoNasc%4)==0) && ((anoNasc%400)==0) && ((anoNasc%100)!=0))
						{
							idade += 29;
						}
						else
						{
							idade += 28;
						}
					}
				}
				else
				{
					if (i % 2 == 0)
					{
						idade += 31;
					}
					else if(i % 2 == 1)
					{
						idade += 30;
					}
				}
			}
			
		}
	}



	printf("Sua idade é: %d dias! \n", idade);

	return 0;
}
