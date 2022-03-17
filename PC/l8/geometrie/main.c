#include "geometrie.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	scanf("%d", &n);

	punct* puncte = nPuncte(n);

	citestePuncte(puncte, n);
	
	printf("Pentru poligonul ");
	afiseazaPuncte(puncte, n);

	printf("Aria = %.3lf\n", ariePoligon(puncte, n));
	printf("Perimetrul = %.3lf\n", perimetruPoligon(puncte, n));	

	free(puncte);
	return 0;
}
