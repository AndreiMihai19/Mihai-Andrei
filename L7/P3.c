//Pentru un numar care contine un numar extrem de mare de cifre (>unsigned long long int) se foloseste un sir de string
#include <stdio.h>
#include <stdlib.h>
#define Citire(x) scanf("%llu",&x)


unsigned long long int Suma_Cifre(unsigned long long int  n)
{ 

	if (n == 0) return 0;
	else
		return n % 10 + Suma_Cifre(n / 10);
	
}


int main()
{

	unsigned long long int N;
	int S = 10, ok = 0;

	do{
		printf("Input (N > 1000000):");
		Citire(N);
		if (N > 1000000)
			ok = 1;
	} while (!ok);
	

	while (S > 9)
	{
		S = 0;
		S = S + Suma_Cifre(N);
		N = S;
	}
	

   printf("Radacina digitala este: %d \n", S);


	return 0;
}