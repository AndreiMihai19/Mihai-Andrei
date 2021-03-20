#include <stdlib.h>
#include <stdio.h>
#define MAX 100
#define Citire(x) scanf("%d",&x) 
#define new_line printf("\n")
#define DEFAULT -1

int StC[MAX],StB[16], St[MAX]; 
int top = -1, top1 = -1, top2 = -1;
int n, nr = 0;
int binar[16];

//StC - stiva ce contine cifrele numarului
//StB - stiva ce contine bitii numarului
//St - stiva auxiliara 

//Pentru StC
void Push(int x) {

	if (top == MAX - 1)
	{
		printf("Eroare\n");
		return;
	}
	StC[++top] = x;
}

void Pop() {

	if (top == -1)
	{
		printf("Nu exista elemente in stiva\n");
		return;
	}
	top--;
}

//Pentru StB
void Push1(int x) {

	if (top1 == 15)
	{
		printf("Eroare\n");
		return;
	}
	StB[++top1] = x;
}

void Pop1() {

	if (top1 == -1)
	{
		printf("Nu exista elemente in stiva\n");
		return;
	}
	top1--;
}

//Pentru St
void Push2(int x) {

	if (top2 == MAX - 1){
		printf("Eroare");
		return;
	}
	St[++top2] = x; 
}

void Pop2() {

	if (top2 == -1)
	{
		printf("Nu exista elemente in stiva\n");
		return;
	}
	top2--;
}

int IsEmpty() {
	if (top == -1)
	{
		return 1;
	}
	return 0;
}

//Afisarea stivei ce contine bitii
void Afisare_StB() {
	int i;
	
	for (i = top1; i >= 0; i--)
	{
		printf("%d ", StB[i]);
	}	
	printf(" (binary) ---> ");
}

//Adaugarea cifrelor in StC si a bitilor in StB
void Adaugare_stive(int n) {

	int k = 0, n1;
    n1 = n;

	while (n1) 
	{
		nr++;
		Push(n1 % 10);
		n1 /= 10;
	}

	while (n) 
	{
		binar[k++] = n % 2;
		Push1(n % 2);
		n /= 2;
	}

}

//Functia de comparare a 2 stive
int Compar(int stiva1[], int stiva2[],int vf) {
	int i, ok = 1;
	for (i = 0; i <= vf; i++)
		if (stiva1[i] != stiva2[i])
			ok = 0;

	return ok;
}

//Se imparte stiva binara, o jumatate se transfera in St, urmand compararea stivelor StB si St
void Impartire_stiva(int StB[]) {
      int i, j = 0, aux, ok = 1;
	  
	  aux = top1;
	
	  while (j <= aux/2) {

		  Push2(StB[top1]);
		  Pop1();
		  j++; 
	  }

//Caz particular: daca numarul de biti este impar, se elimina bitul din mijloc (este neimportant)
	  if (top1 % 2 == 1)
		  Pop2();

	  if (!Compar(StB, St, top2))
		  ok = 0;

	  j = 0;
	  while (n) 
	  {
		  if (n % 10 != StC[top])
			  ok = 0;
		 
		  Pop();
		  n/=10;
	  }

	  if (ok)
		  printf("PALINDROM\n\n");
	  else
		  printf("NU ESTE PALINDROM\n\n");

}

int main() {

	int ok = 1;

	//Citirea conditionata a numarului
	do {
		printf("Numarul=");
		Citire(n);
		if (n <= 65535)
			ok = 0;

	} while (ok);
  
	new_line;
	printf("%d = ", n);

	IsEmpty();
	Adaugare_stive(n);
	Afisare_StB();
	Impartire_stiva(StB);
	
	system("Pause");
	return 0;
}