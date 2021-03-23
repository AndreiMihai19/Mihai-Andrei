#include <stdio.h>
#include <stdlib.h>
#define Citire(x) scanf("%d",&x)
#define new_line printf("\n")
#define MAX 100
#define MAXST 8
#define DEFAULT -1

int St[MAXST];
int top = -1;
int binar[MAXST];


void Push(int x) 
{

	if (top == MAXST - 1)
	{
		printf("Eroare");
		return;
	}
	
	St[++top] = x;

}

void Pop() 
{
	if (top == -1)
	{
		printf("Nu exista elemente in stiva!");
		return;
    }

	top--;
}

//Initializarea stivei (la inceput)
void Init_St()
{
	int i = 0;
	for (i = 0; i < MAXST; i++)
	{
		St[i] = DEFAULT;
	}
}

//Afisarea stivei
void Afisare_St() 
{
	int i;

	for (i = top; i >= 0; i--)
	{
		printf("%d ", St[i]);
	}

}

//Transformarea numarului zecimal in binar (se afiseaza), calcularea inversului si introducerea elementelor sale intr o stiva (se afiseaza)
//Se goleste stiva pentru a introduce urmatorul numar
void Zecimal_Binar(int x)
{
	int i = MAXST - 1, invers[MAXST], k = MAXST - 1, j;

	while (i >= 0)
	{
		binar[i] = x % 2;
		i--;
		x /= 2;
	}

	printf("Forma binara:");
	for (i = 0; i < MAXST; i++)
		printf("%d", binar[i]);

	new_line;

	printf("Forma binara stiva output: ");
	for (j = 0; j < MAXST; j++)
	{
		invers[k] = binar[j];
		Push(invers[k]);
		k--;
	}

	Afisare_St();
	
	while (top != -1)
		Pop();

	new_line;
	new_line;
}

int main() {
	int N, V[MAX], i;

	printf("N=");
	Citire(N);

	printf("Introduceti elementele:");
	for (i = 0; i < N; i++)
		Citire(V[i]);

	Init_St();
	new_line;

	for (i = 0; i < N; i++) 
		Zecimal_Binar(V[i]);
	
	return 0;
	system("pause");
}