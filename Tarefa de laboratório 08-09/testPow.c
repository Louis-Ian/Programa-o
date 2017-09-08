
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char const **argv[])
{
    char a[10], b[10];
    int soma;
	
    a[0] = argv[0];
    b[0] = argv[1];
    soma = atoi(a)+atoi(b);

	printf("%d \n", soma);
	
	return 0;
}