#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int N;
	unsigned long int Fib1=1, Fib2=1;

	do
	{
		printf("Insira um inteiro positivo: ");
		scanf("%d", &N);
	} while ( N <= 0);

	unsigned long int AUX = 2;

	printf("1° => %lu \n2° => %lu \n", Fib1, Fib2 );

	for( int i = 2; i < N; ++i) //comeca em 2 porque os dois primeiros números da sequência já foram exibidos
	{
		AUX = Fib1 + Fib2;
		printf("%d° => %lu \n", i+1, AUX);
		Fib1 = Fib2;
		Fib2 = AUX;
	}

	return 0;
}