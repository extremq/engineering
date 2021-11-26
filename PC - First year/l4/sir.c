#include <math.h>

#include "sir.h"

double termen(int n, int p, double a)
{
	if (!n)
	{
		return (double) a / p;
	}

	// calculam termenul anterior o singura data
	double inferior = termen(n - 1, p, a); 

	return (double) (1.0 / p) * ((p - 1) * inferior + a / pow(inferior, p - 1)); 
}

// nu e nevoie de recurenta cand iteram
double urmatorul_termen(double x, int p, double a)
{
	return (double) (1.0 / p) * ((p - 1) * x + a / pow(x, p - 1));
}
