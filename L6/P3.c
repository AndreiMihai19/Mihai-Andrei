#include <stdio.h>
#include <stdlib.h>

int v[100], n, isS, isV = 0, k, m = 0;

void Init(int k) { 
	v[k] = 1; 
	
}

int Succesor(int k) {
	if (v[k] < n/2+1) { 
		v[k]++; 
		return 1; 
	}
	else 
	{
		return 0;
	}
}

int Valid(int k)
{
	int i;
	for (i = 1; i < k; i++) 
	{
		if (v[i] > v[k]) 
			return 0;
	}
	return 1;
}

int Solution(int k) {
	int p = 1, i;
	for (i = 1; i <= k; i++)
		p = p * v[i];
	if (p == n)
		return 1;
	else
		return 0;
}

void Print() {
	int i;
	printf("%d : ", ++m);
	for (i = 1; i <= k; i++)
		printf("%d ", v[i]);
	printf("\n");
}

void Back(int n) {
	k = 1; Init(k);
	while (k > 0) {
		isS = 0; isV = 0;
		if (k <= n) 
			do { 
				isS = Succesor(k);
				if (isS) isV = Valid(k);
			} while (isS && !isV);
			if (isS) 
				if (Solution(k)) 
					Print(); 
				else { 
					k++; Init(k); 
				}
			else 
				k--;
	}
}

int main ()
{
		printf("Input:");
        scanf("%d", &n);
		
		printf("Output:\n");
		Back(n);

}