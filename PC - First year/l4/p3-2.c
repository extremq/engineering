#include <stdio.h>
#include <math.h>

#include "sir.h"

int main(void)
{
	int p;
	double a, precizie;

	printf("a = ");
	scanf("%lf", &a);

	printf("precizie = ");
	scanf("%lf", &precizie);

	printf("p = ");
	scanf("%d", &p);

	if (p < 1)
	{
		p = 1;
	}
	
	for(; p >= 1; --p)
	{
		int n = 1;
		double x1, x2;

		x2 = termen(n - 1, p, a);
		x1 = urmatorul_termen(x2, p, a);
		
		while(fabs(x1 - x2) > precizie)
		{
			++n;
			x2 = x1;
			x1 = urmatorul_termen(x2, p, a);
		}

		printf("Pentru p = %d, lim = %lf.\n", p, x1);
	}
}
