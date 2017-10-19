#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int N,EhPRIMO;
	int CONTADORdePrimos = 0;

	do
	{
		printf( "Insira um número positivo: " );
		scanf( "%d", &N );
	} while( N <= 0 || !N ); //gostaria de receber entrada em casos que o usuario nao insere nada (ex: ENTER)

	int AUX = 3;

	printf("O/Os %d primeiros números primos são:\n1°-> 2 \n", N );

	while( CONTADORdePrimos < N )
	{
		EhPRIMO = 1; //1 = verdadeiro

		for ( int i = 2; i < AUX; ++i )
		{
			if ( AUX%i == 0 )
			{
				EhPRIMO = 0; //0 = falso
			}
		}

		if ( EhPRIMO == 1 )
		{
			CONTADORdePrimos++;
			printf( "%d°-> %d \n", CONTADORdePrimos, AUX );
		}

		AUX++;
	}

	return 0;
}