#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define citire(x) scanf("%d",&x)
#define MAX 100
void oglindit(int a[], int x[]) {
	int i;

	for (i = 0; i < 8; i++)
		x[i] = a[7 - i];

}

void afisare_binar(int a[]) {
	int i;

	for (i = 0; i < 8; i++)
		printf("%d", a[i]);

	printf("\n");
}

void invers_binar(int a[]) {
	int i;

	for (i = 0; i < 8; i++)
		if (a[i])
			a[i]--;
		else
			a[i]++;

}


int binar_zecimal(int a[]) {
	int nr = 0, i, p = pow(2, 7);

	for (i = 0; i < 8; i++)
	{
		if (a[i])
			nr += p;
		p /= 2;
	}

	return nr;

}

void p1(int n) {

	int  inv_binar[9], k = 0, binar[9], i;

	for (i = 0; i < 8; i++)
		inv_binar[i] = 0;

	while (n) {
		inv_binar[k++] = n % 2;
		n /= 2;
	}

	oglindit(inv_binar, binar);

	//Afisam numarul sub forma binara
	afisare_binar(binar);

	invers_binar(binar);

	//Afisarea inversului
	afisare_binar(binar);

	//Afisarea numarului zecimal al inversului nr initial
	printf("%d \n\n", binar_zecimal(binar));
}

int main() {

	int N, i, a[MAX];
	printf("Introduceti nr de numere:");
	citire(N);
	printf("Numerele:");
	for (i = 0; i < N; i++)
		citire(a[i]);

	for (i = 0; i < N; i++)
		p1(a[i]);


	system("pause");
	return 0;
}