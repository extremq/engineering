#include <stdio.h>
#include "numere.h"

int main(void)
{
	int n;
	int x;
	int i, j;
	int ind;

	printf("n = ");
	scanf("%d", &n);

	for(i = 1; i <= n; ++i)
	{
		printf("Numarul: ");
		scanf("%d", &x);

		ind = 0;
		for(j = 2; j < x; ++j)
		{
			int c;
			c = cmmdc(x, j);

			if(c == 1)
			{
				++ind;
			}
		}

		printf("are indicatorul Euler = %d\n", ind);
	}

	return 0;
}
