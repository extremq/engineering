#include <stdio.h>
#include <stdbool.h>
#include "divizori.h"

#define ABUNDENT   1
#define PERFECT    0
#define DEFICIENT -1

void citire(int *x, int *y, int *optiune);
int tip_numar(int x);
void parcurgere(int x, int y, int optiune);

void citire(int *x, int *y, int *optiune)
{	
	printf("x = ");
	scanf("%d", x);

	printf("y = ");
	scanf("%d", y);

	printf("Afiseaza numerele abundente (%d), perfecte (%d), deficiente (%d).\n",
		ABUNDENT, PERFECT, DEFICIENT);
	printf("Optiunea ta: ");
	scanf("%d", optiune);
	
	return;
}

int tip_numar(int n)
{
	int suma = suma_divizori(n);

	if(n > suma)
	{
		return ABUNDENT;
	}
	else if(n == suma)
	{
		return PERFECT;
	}
	else 
	{
		return DEFICIENT;
	}
}

void parcurgere(int x, int y, int optiune)
{	
	_Bool sunt_elemente = false; /* Pentru parantezare. */

	for(int i = x; i <= y; ++i)
	{
		int tip = tip_numar(i);

		if(tip == optiune)
		{
			if(!sunt_elemente)
			{
				printf("[ ");
				sunt_elemente = true;
			}

			printf("%d ", i);
		}
	}

	if(sunt_elemente)
	{
		printf("]\n");
	}
	else
	{
		printf("Niciu element nu indeplineste conditia.\n");
	}

	return;
}

int main(void)
{
	int x, y, optiune;

	citire(&x, &y, &optiune);
	parcurgere(x, y, optiune);

	return 0;
}
