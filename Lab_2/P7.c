#include <stdio.h>
#include <stdlib.h>
#define citire(x) scanf("%d",&x)

int main() {
	int N,i = 1,Sum=0, j ,iprim;
	
	printf("N=");
	citire(N);

	while (N != 0)
	{
		iprim = i;
		for (j = 31; j >= 0; j--) {
			if (iprim & 1)
				Sum++;
			iprim = iprim >> 1;
		}
		
		N--;
		i++;
	}
	       
	printf("Suma bitilor numerelor de la 1 la N: %d \n", Sum);
	system("pause");
	return 0;
}
