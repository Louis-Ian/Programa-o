#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv){
	int diaNasc,mesNasc,anoNasc;
	int diaHoje,mesHoje,anoHoje;
	int idadeDia, idadeMes, idadeAno,iDADE;
	
	printf("Insira, respectivamente, dia, mês e ano do nascimento:\n");
	scanf("%d  %d  %d", &diaNasc, &mesNasc, &anoNasc);

	printf("Insira, respectivamente, dia, mês e ano de hoje:\n");
	scanf("%d  %d %d", &diaHoje, &mesHoje, &anoHoje);

	idadeAno = anoHoje - anoNasc;
	idadeMes = mesHoje - mesNasc;
	idadeDia = diaHoje - diaNasc;

	while(anoNasc < anoHoje){
		if (((anoHoje%4)==0) && ((anoHoje%400)==0) && ((anoHoje%100)!=0)){
			idadeDia++;
		}
		anoHoje--;
	}

	if (idadeMes < 0){
		idadeMes = 12 + idadeMes;
		idadeAno--;
	}

	iDADE = 365*idadeAno;

	for (int i = 0; i < idadeAno; ++i)
	{
		iDADE++;
	}



	//printf("Sua idade é: %d dias, %d meses e %d anos \n", idadeDia, idadeMes, idadeAno);
	printf("Sua idade é: %d \n", iDADE);

	return 0;
}
