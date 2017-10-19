#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int contadorDeDigitos(unsigned long long int a)
{
	int digitos=0;

	while( a != 0)
	{
		a = a/10;
		digitos++;
	}

	digitos--;

	return digitos;
}

int inversor(unsigned long long int a, int digitos)
{
	unsigned long long int invertido=0;

	for(int i = 1; i < 10; ++i)
	{
		invertido += (a%10)*(pow(10,digitos));
		a = a/10;
		digitos--;
	}

	return invertido;
}

int main(int argc, char const **argv[])
{
	if( argc >= 2)
	{
		unsigned long long int INPUT;

		INPUT = inversor(INPUT,contadorDeDigitos(INPUT));

		printf("%llu \n", INPUT);
	}
	else
	{
		unsigned long long int INPUT;

		do
		{
			printf( "Insira um número positivo de até 10 dígitos: " );
			scanf( "%llu", &INPUT );
		} while( INPUT <= 0 || INPUT > 9999999999);

		INPUT = inversor(INPUT,contadorDeDigitos(INPUT));

		printf("%llu \n", INPUT);
	}
		
	return 0;
}