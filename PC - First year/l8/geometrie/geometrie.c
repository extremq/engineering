#include "geometrie.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void citestePunct(punct* p)
{
	scanf("%lf", &(p -> x));
	scanf("%lf", &(p -> y));
}

void citestePuncte(punct* p, int n)
{
	int i;
	for(i = 0; i < n; ++i)
	{
		citestePunct(p + i);
	}
}

void afiseazaPunct(punct* p)
{
	printf("(%.2lf, %.2lf)\n", p -> x, p -> y);
}

void afiseazaPuncte(punct* p, int n)
{
	int i;
	for(i = 0; i < n; ++i)
	{
		printf("%c(%.2lf, %.2lf)", 'A' + i, (p + i) -> x, (p + i) -> y);

		if(i < n - 1)
		{
			printf("\t");
		}
		else
		{
			printf("\n");
		}
	}
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

double arieTriunghi(punct*a, punct* b, punct* c)
{
	double la, lb, lc;
	la = distantaPuncte(b, c);
	lb = distantaPuncte(c, a);
	lc = distantaPuncte(a, b);

	// Da, puteam folosi semiperimetruTriunghi(), dar tot 
	// aveam nevoie de lungimile laturilor. Nu vad rostul
	// in a executa acelasi lucru de doua ori.
	double s = (la + lb + lc) / 2.0L;

	return sqrt(s * (s - la) * (s - lb) * (s - lc));
}

double semiperimetruTriunghi(punct* a, punct* b, punct* c)
{
	double la, lb, lc;
	la = distantaPuncte(b, c);
	lb = distantaPuncte(c, a);
	lc = distantaPuncte(a, b);

	return (la + lb + lc) / 2.0L;	
}

double ariePoligon(punct* p, int laturi)
{
	// Alegem primul punct drept pivot si formam triunghiuri
	// cu fiecare pereche de puncte consecutive.
	// Desigur, corect ar fi sa folosim algoritmul convex hull
	// pentru orice poligon.
	punct* pivot = p;
	double arie = 0;

	int i;
	for(i = 1; i < laturi - 1; ++i)
	{
		arie += arieTriunghi(pivot, p + i, p + i + 1);
	}

	return arie;
}

double perimetruPoligon(punct* p, int laturi)
{
	double perimetru;
	
	int i;
	for(i = 0; i < laturi - 1; ++i)
	{
		perimetru += distantaPuncte(p, p + 1);
	}	

	return perimetru;
}
