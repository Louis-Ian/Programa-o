#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int N,EhPRIMO,MaiorPrimo=2;

	do
	{
		printf( "Insira um número positivo: " );
		scanf( "%d", &N );
	} while( N < 2);

	int AUX = 2;

	while( AUX < N )
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
			MaiorPrimo = AUX;
		}

		AUX++;
	}

	printf("O maior número primo antes de %d é: %d\n", N, MaiorPrimo);

	return 0;
}