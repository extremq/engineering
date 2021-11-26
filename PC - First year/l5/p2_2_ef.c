#include <stdio.h>
#include <stdlib.h>
#include "divizori.h"

int main(void)
{
	int x, y;
	
	printf("x = ");
	scanf("%d", &x);

	printf("y = ");
	scanf("%d", &y);
	
	// Initializam un vector pentru fiecare element
	// intre x si y.
	int *sume = 0;
	sume = (int *)malloc((y - x + 1) * sizeof(int));
	if (0 == sume)
	{
		fprintf(stderr, "Alocare esuata.\n");
		exit(EXIT_FAILURE);
	}
	
	// Calculam pentru fiecare numar suma.
	// Astfel, nu vom apela functia de fiecare data.
	for(int i = 0; i <= y - x; ++i)
	{
		sume[i] = suma_divizori(i + x);
	}

	for(int i = x; i <= y - 1; ++i)
	{
		for(int j = i + 1; j <= y; ++j)
		{
			if (sume[j - x] == i && sume[i - x] == j)
		       	{
				printf("%d si %d sunt prietene.\n", i, j);
			}
		}	
	}

	return 0;
}
