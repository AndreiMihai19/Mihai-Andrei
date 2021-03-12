//Nu am rescpectat cerintele...doar am transformat un numar zecimal in binar folosind pointeri (am alocat dinamic)
#include <stdio.h>
#include <stdlib.h>
#define citire(x) scanf("%d",&x)

void Binar(int *n) {
	int *binar;
	int k = 0, i;
	
	binar = (int *)malloc(8*sizeof(int));

	for (i = 0; i < 8; i++) 
		*(binar+i) = 0;

	while (*n) {

		*(binar+k) = *n % 2;
	     
		k++;
	
		*n /= 2;
	}

	for (i = 7; i >= 0; i--) 
		printf("%d", *(binar+i));
		
	
	printf("\n");
	

}


int main()
{
	int zecimal;

	printf("Introduceti numarul:");
	citire(zecimal);

	
	Binar(&zecimal);

	system("pause");
	return 0;
}