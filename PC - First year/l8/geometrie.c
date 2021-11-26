#include "geometrie.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void citestePunct(punct* p)
{
	scanf("%lf", &(p -> x));
	scanf("%lf", &(p -> y));
}

void afiseazaPunct(punct* p)
{
	printf("{ x: %.4lf, y: %.4lf }\n", p -> x, p -> y);
}

punct* nPuncte(int n)
{
	punct* p = 0;

	p = (punct*) malloc(sizeof(punct) * n);
	if(p == 0)
	{
		fprintf(stderr, "Memorie insuficienta pentru alocarea punctelor.\n");
		exit(EXIT_FAILURE);
	}
	
	return p;	
}

double distantaPuncte(punct* a, punct* b)
{
	return sqrt(pow(a -> x - b -> x, 2) + pow(a -> y - b -> y, 2));
}
