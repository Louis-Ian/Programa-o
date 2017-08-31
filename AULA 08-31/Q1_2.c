#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv){
	int diaNasc,mesNasc,anoNasc;
	int diaHoje,mesHoje,anoHoje;
	int idadeDia, idadeMes, idadeAno,iDADE=0;

	printf("Insira, respectivamente, dia, mês e ano do nascimento:\n");
	scanf("%d  %d  %d", &diaNasc, &mesNasc, &anoNasc);

	printf("Insira, respectivamente, dia, mês e ano de hoje:\n");
	scanf("%d  %d %d", &diaHoje, &mesHoje, &anoHoje);

	idadeAno = anoHoje - anoNasc;
	idadeMes = mesHoje - mesNasc;

	if (idadeMes < 0){
		idadeMes = 12 + idadeMes;
		idadeAno--;
	}

	for (int i = 1; i < 12; ++i)
	{
		

		for (int i = 0; i < idadeAno; ++i)
		{
			if (((anoHoje%4)==0) && ((anoHoje%400)==0) && ((anoHoje%100)!=0))
			{
				iDADE++;
				anoHoje--;
			}
			
		}
		
	}

	printf("Sua idade é: %d \n", iDADE);

	return 0;
}
