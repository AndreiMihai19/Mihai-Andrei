#include <stdio.h>
#include <stdlib.h>
#define citire(x) scanf("%d",&x)
#define new_line printf("\n")

void binar(int n) {
	int i,v[9];
	for (i = 7; i >= 0; i--) {
		if (n & 1)
			v[i] = 1;
		else
			v[i] = 0;
		n = n >> 1;
	}

	for (i = 0; i <=7; i++)
		printf("%d", v[i]);
}



int main() {
	int N, i, a[9], k = 0, ok = 1;

	do {
		printf("N=");
		citire(N);
		if (N < 256)
			ok = 0;
		else
			printf("Atentie! Numarul introdus nu este corect (N<256)\n");
	} while (ok);

	for (i = 0; i < 8; i++)
		a[i] = 0;

	//Numarul N in binar
	binar(N);

	new_line;


	for (i = 0; i < 8; i++) {
		if (N & 1) {
			a[k] = 1;
			k++;
		}
		N = N >> 1;
	}

	//Valoarea maxima a lui N
	for (i = 0; i < 8; i++)
		printf("%d", a[i]);

	new_line;

	system("pause");
	return 0;
}
