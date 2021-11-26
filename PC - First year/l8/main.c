#include <stdio.h>
#include <stdlib.h>
#include "parcare.h"

// Stergem din uratenia if-urilor.
void checkMemory(unsigned int* p);
void showResults(unsigned int* l, unsigned int* p, unsigned int* r, int n);

void checkMemory(unsigned int* p)
{
	if(p == 0)
	{
		fprintf(stderr, "Not enough memory for array.");
		exit(EXIT_FAILURE);
	}
}

void showResults(unsigned int* locuri, unsigned int* preturi, unsigned int* sume, int n)
{
	readArray(locuri, n);
	readArray(preturi, n);

	printf("Primaria gestioneaza %d parcari.\n\n", n);
	printf("Numarul de locuri de parcare este: ");
	printArray(locuri, n);
	printf(".\n");

	printf("Pretul pentru un loc de parcare este: ");
	printArray(preturi, n);
	printf(" lei.\n\n");
	
	sumeIncasate(locuri, preturi, sume, n);	

	printf("Sumele incasate sunt: ");
	printArray(sume, n);
	printf(" lei.\n\n");

	int indice = locuriMax(locuri, n);	
	printf("Parcarea cu cele mai multe locuri de parcare este parcarea %d.\n", indice);
	printf("Pretul unui loc in parcarea %d este de %d lei.\n", indice, *(preturi + indice));
}

int main(void)
{
	int n;
	unsigned int *locuri = 0, *preturi = 0;
	unsigned int *sume = 0;

	scanf("%d", &n);

	locuri = (unsigned int*) malloc(n * sizeof(unsigned int));
	checkMemory(locuri);
	
	preturi = (unsigned int*) malloc(n * sizeof(unsigned int));
	checkMemory(locuri);
	
	sume = (unsigned int*) malloc(n * sizeof(unsigned int));
	checkMemory(sume);	

	showResults(locuri, preturi, sume, n);

	free(locuri);
	free(preturi);
	return 0;	
}
