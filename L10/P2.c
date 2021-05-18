#include <stdio.h>
#include <stdlib.h>

int main()
{
	int f1, f2, k, nr = 0, Nr_min = 0, f0;

	printf("Input: k=");
	scanf("%d", &k);

	f1 = 1;
	f2 = 1;

	//Cautam cel mai mare numar din sirul Fibonacci mai mic sau egal decat k
	while (nr < k)
	{
		nr = f1 + f2;
		if (nr > k)
		{
			nr = f2;
			break;
		}
		else
		{
		f1 = f2;
		f2 = nr;
		}
	}

	//Se gaseste minimul de numere din seria Fibonacci care au suma egala cu k (pornind de la nr)
	//Am pus conditia de imposibilitate la inceput
	//Alegerea numerelor din sirul Fibonacci s-a facut o singura data in codul de mai jos

	printf("Output:");

	if (k <= 1)
		printf("Nu se poate! \n");
	else
	{

		if (nr == k)
		{
			Nr_min = 2;
			k = 0;
		}

		else
		{

			while (k != 0)
			{
				f0 = nr - f1;

				if (k - nr >= 0)
				{
					k = k - nr;
					Nr_min++;
				}

				nr = f1;
				f1 = f0;

			}
		}

		printf("%d \n", Nr_min);
	}
	
	return 0;
}