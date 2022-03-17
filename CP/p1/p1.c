#include <stdio.h>
#include <math.h>
#include "integrale.h"

int main(void)
{
	double a, b;
	double val;
	unsigned int n;
	double (*pf)(double x);

	printf("a = "); scanf("%lf", &a);
	printf("b = "); scanf("%lf", &b);

	printf("Numar de diviziuni: "); scanf("%d", &n);

	pf = &f;

	val = integralaTrapez(a, b, n, f);

	printf("Valoarea integralei este %.3lf\n", val);

	return 0;
}
