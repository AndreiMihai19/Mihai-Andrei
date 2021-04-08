#include <stdio.h>
#include <stdlib.h>
#define MAXSt 9
#define Citire(x) scanf("%d", &x)
#define new_line printf("\n")
#define DEFAULT -1

int St[MAXSt], St1[MAXSt];
int top = -1, top1 = -1;
int Binar[8];


void Push_St(int x)
{

	if (top == MAXSt - 1)
	{
		printf("Eroare");
		return;
	}

	St[++top] = x;
}

void Push_St1(int x)
{

	if (top == MAXSt - 1)
	{
		printf("Eroare");
		return;
	}

	St1[++top1] = x;
}

void Pop()
{
	if (top == -1) {
		printf("Nu exista elemente in stiva!\n");
		return;
	}
	else
		top--;
}

void Zecimal_Binar(int n) {
	int i;
	for (i = 7; i >= 0; i--) {
		if (n & 1)
			Push_St(1);
		else
			Push_St(0);
		n = n >> 1;
	}
}

void Afisare_St(int Top, int stiva[])
{
	int i;

	for (i = Top; i >= 0; i--)
	{
		printf("%d ", stiva[i]);
	}

	if (Top == DEFAULT)
		printf("Stiva este goala!");

}

//Generarea valorii maxime in St1
void Maxim()
{
	int  k = 0;;
	while (top > -1)
	{
		if (!St[top])
			Push_St1(0);
		else
			k++;
		Pop();
   }

	while (k)
	{
		Push_St1(1);
		k--;
	}

}


int main() {
	int N, k = 0, ok = 1;

	do {
		printf("N=");
		Citire(N);
		if (N < 256)
			ok = 0;
		else
			printf("Atentie! Numarul introdus nu este corect (N<256)\n");
	} while (ok);

	new_line;
	printf("%d -> ", N);
	Zecimal_Binar(N);

	Afisare_St(top,St);
	printf(" - Stack initial");

	new_line; 

	Maxim();

	Afisare_St(top1, St1);
	printf(" - Valoarea maxima");

	new_line;

	system("pause");
	return 0;
}
