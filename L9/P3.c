#include <stdio.h>
#include <stdlib.h>
#define Citire(x) scanf("%d", &x)
#define new_line printf("\n")

int V[100], N;


void Interschimbare(int li, int ls) {
	int i, aux;
	
	
   for (i=li;i<=ls;i++)
	
   {
		if (V[i] * 2 == V[i-1] + V[i+1])
		{
			aux = V[i];
			V[i] = V[i+1];
			V[i+1] = aux;

	   }
	}

}

void Afisare()
{
	int i;
	printf("Vector frumos pentru N=%d: ", N);
	for (i = 1; i <= N; i++)
		printf("%d ", V[i]);

	new_line;
}

void DI(int li, int ls)
{
	int Mij;

	if (li < ls)
	{
		Mij = (li + ls) / 2;
		 DI(li, Mij);
		 DI(Mij + 1, ls);
		 Interschimbare(li, ls);
		
	}

}

int main()
{
	int i;
	printf("N=");
	Citire(N);

	for (i = 1; i <= N; i++)
		V[i] = i;


	DI(1, N);
	Afisare();

	system("pause");
	return 0;
}
