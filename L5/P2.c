#include <stdio.h>
#include <stdlib.h>
#define MAXSt 1025
#define Citire(x) scanf("%d", &x)
#define new_line printf("\n")
#define DEFAULT -1

int St[MAXSt];
int top = -1;
int binar[8];

void Push(int x) {

	if (top == MAXSt - 1)
	{
		printf("Eroare");
		return;
	}
   
	St[++top] = x;
}


void initStack()
{
	int i = 0;
	for (i = 0; i < MAXSt; i++)
	{
		St[i] = DEFAULT;
	}
}

void Zecimal_Binar(int x) 
{

	while (x) 
	{
		Push(x % 2);
		x /= 2;
	}

}

void Afisare_St() {
	int i;

	for (i = top; i >= 0; i--)
	{
		printf("%d ", St[i]);
	}

}


int main() {

	int C, N, i, V[MAXSt], ok = 1;

	do {
		printf("C="); 
		Citire(C);
		if (C >= 0 && C <= 7)
			ok = 0;

	} while (ok);

	printf("N="); 
	Citire(N);

	printf("Acum se introduc %d numere:",N);
	for (i = 0; i < N; i++)
		Citire(V[i]);

	new_line;
	initStack();

	for (i = 0; i < N; i++)
		if (((V[i] >> C) & 1) == 1)
		{
			printf("%d ", V[i]);
			Zecimal_Binar(V[i]);
		}

	new_line;

	Afisare_St();

	new_line;

	return 0;
	system("pause");
}