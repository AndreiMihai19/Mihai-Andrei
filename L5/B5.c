#include <stdio.h>
#include <stdlib.h>
#define new_line printf("\n")
#define MAXST 52
#define space printf(" ");

int St1[MAXST], St2[MAXST];
int top1 = -1, top2 = -1;

//Pentru St1
void Push1(int x) 
{
	if (x == MAXST - 1)
	{
		printf("Eroare");
		return;
	}

	St1[++top1] = x;
}


void Pop()
{
	if (top1 == -1)
	{
		printf("Nu exista elemente in stiva");
		return;
	}
	top1--;
}

//Pentru St2
void Push2(int x)
{
	if (x == MAXST - 1)
	{
		printf("Eroare");
		return;
	}


	St2[++top2] = x;
}

//Afisarea stivelor (intr un mod aranjat)
void Afisare_St()
{
	int i, aux, j = 0;
	aux = top2;

	printf("\t  Stiva 1      Stiva 2\n");

	for (i = 0; i <= top1; i++)
	{   
		printf("\t  | %d\t| ", St1[i]);

		if (aux != -1)
		{   
			    printf("  |   %d\t| ", St2[j]);
			j++;
			aux--;
		}
		else
		{
		if (baza)
			printf("  ============= ");
		    baza = 0;
		}
		new_line;
	}
	printf("\t  =======\n");
}

//Functia de verificare (daca un numar este prim-1 sau nu-0)
//Se numara divizorii numarului iar, daca acesta are 2 divizori(pe 1 si pe el insusi) atunci este numar prim (altfel nu este prim)
int Verif_Nrprim(int x)
{
	int i, d = 0;
         
	for (i = 1; i <= x; i++)
		if (x % i == 0)
			d++;

	if (d == 2)
		return 1;
	else
		return 0;
}

//Transformarea in forma binara a numarului prin impartiri repetate la 2
//Pentru ca 2 este numar par (singurul numar par prim), are bitul 0 pe pozitia 0
//Astfel, bitul 0 este neglijat, numarul 2 avand reprezentarea binara: 1 (fals)
//Din aceasta cauza, i am dat direct val 10 daca reprezentarea binara este 1
int Zecimal_Binar(int x)
{
	int oglindit = 0, binar = 0;

	while (x)
	{
		oglindit = oglindit * 10 + x % 2;
		x /= 2;
	}

	//Am realizat procedeul de oglindire pentru a afisa numarul in forma binara corecta
	while (oglindit) 
	{
		binar = binar * 10 + oglindit % 10;
		oglindit /= 10;
	}


	if (binar==1)
		binar = 10;

	return binar;
}


void Scoatere_Populare() 
{
	int aux, v[35], i = 0, k=0;

	aux = top1; //salvez val varfului 


	while (aux > -1)
	{
		if (Verif_Nrprim(St1[top1]))
			Push2(Zecimal_Binar(St1[top1])); // se adauga in stiva numerele prime in forma binara
		else 
		{   
			v[i++] = St1[top1]; //se salveaza intr-un vector numerele care nu sunt prime
			k++;
		}
			Pop(); //se elibereaza stiva principala - St1
		aux--;
	}

	
	i = 0;
    //adaug in stiva valorile salvate in vector
	while (k) 
	{
		Push1(v[i++]);  
		k--;
	}


}

int main() {

	int i;

	for (i = 50; i >= 1; i--)
		Push1(i);

	Scoatere_Populare();
	Afisare_St();
	
	system("pause");
	return 0;

}