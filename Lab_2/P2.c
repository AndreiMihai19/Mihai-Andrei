#include <stdio.h>
#include<stdlib.h>
#define citire(x) scanf("%d",&x)
#define SIZE 100
int main() {

	int C, N, Binare[SIZE], i, B, ok = 0;

	do {
		printf("C=");
		citire(C);
		if (C >= 0 && C <= 7)
			ok = 1;
	} while (!ok);

	printf("N=");
	citire(N);

	printf("Cele %d numere:", N);
	for (i = 0; i < N; i++)
		citire(Binare[i]);

	for (i = 0; i < N; i++)
	{
		B = Binare[i] >> C;
		if (B & 1)
			printf("%d ", Binare[i]);
	}

	printf("\n");

	system("pause");
	return 0;
}