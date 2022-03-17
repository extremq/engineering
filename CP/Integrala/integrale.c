#include <stdio.h>
#include <math.h>
#include "integrale.h"

double f(double x)
{
	return x;
}

double integralaTrapez(double a, double b, unsigned int n, PF pf)
{
	double sum;
	double dx = (b-a)/n;
	double x;

//	double eps = 1e-4;

	sum = ((*pf)(a) + (*pf)(b))/2;

	for(x = a+dx; x < b; x = x + dx)
	{
		sum = sum + (*pf)(x);
	}

	sum = sum * dx;

	return sum;
}
