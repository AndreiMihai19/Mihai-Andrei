#include <stdio.h>
#include <stdlib.h>
#define Citire(x) scanf("%d",&x)
#define new_line printf("\n")

int N;

void Secventa(int N)
{
	if (N == 1)
		printf("%d", N);
	else
	{
		if (N % 2 == 0)
		{
			printf("%d->", N);
			Secventa(N / 2);
			
		}
		if (N % 2 == 1)
		{
			printf("%d->", N);
			Secventa(3 * N + 1);
		}
	}
}

int main()
{
	printf("N=");
	Citire(N);

	Secventa(N);

	new_line;
	
	return 0;
}