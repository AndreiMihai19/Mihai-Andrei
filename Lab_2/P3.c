#include <stdio.h>
#include <stdlib.h>
#define citire(x) scanf("%d",&x)

int main() {
	int a;
	printf("a="); citire(a);

	if (a >> 31 < 0)
		printf("Negativ \n");
	else
	{
		if (!a&~a)
			printf("Zero \n");
		else
			printf("Pozitiv \n");
    }
	system("pause");
	return 0;
}




