#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int N,Cont=1, i=0;

	do
	{
		printf("Insira um inteiro positivo: ");
		scanf("%d", &N);
	} while ( N <= 0);

	while (Cont <= N)
	{
		if(i%2==1 && i%3==0 && i%7==0)
		{
			printf("%d°: %d\n", Cont, i);
			Cont++;
		}
		i++;
	}

	return 0;
}