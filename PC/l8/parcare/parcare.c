#include "parcare.h"
#include <stdio.h>

void readArray(unsigned int* v, int n)
{
	int i;
	for(i = 0; i < n; ++i)
	{
		scanf("%d", v + i);
	}
	return;
}
void printArray(unsigned int* v, int n)
{
	int i;
	for(i = 0; i < n; ++i)
	{
		printf("%d", *(v + i));
		
		if(i != n - 1)
		{
			printf(", ");
		}
	}
	return;
}

void sumeIncasate(unsigned int* l, unsigned int* p, unsigned int* r, int n)
{
	int i;
	for(i = 0; i < n; ++i)
	{
		*(r + i) = *(l + i) * *(p + i);
	}
	return;
}

int locuriMax(unsigned int* l, int n)
{
	// Toate numerele sunt unsigned;
	unsigned int maxim = 0;
	int indice = 0;

	int i;
	for(i = 0; i < n; ++i)
	{
		if(*(l + i) > maxim)
		{
			maxim = *(l + i);
			indice = i;
		}	
	}
	return indice;	
}
