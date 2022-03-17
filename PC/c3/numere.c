#include "numere.h"

_Bool prim(unsigned int n)
{
	_Bool r = 1;
	int div = 2;

	if(n != 2 && n % div == 0)
	{
		r = 0;
	}
	else
	{
		for(div = 3; div * div <= n; div = div + 2)
		{
			if(n % div == 0)
			{
				r = 0;
				break;
			}
		}
	}

	return r;
}

unsigned int cmmdc(unsigned int a, unsigned int b)
{
	unsigned int r;
	r = a % b;
	
	while(r != 0)
	{
		a = b;
		b = r;
		r = a % b;
	}

	return b;
}
