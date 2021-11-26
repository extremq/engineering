#include <stdio.h>
#include "divizori.h"

int main(void)
{
	int x, y;
	
	printf("x = ");
	scanf("%d", &x);

	printf("y = ");
	scanf("%d", &y);

	for(int i = x; i <= y - 1; ++i)
	{
		for(int j = i + 1; j <= y; ++j)
		{
			int sum_i, sum_j;
			sum_i = suma_divizori(i);
			sum_j = suma_divizori(j);

			if (sum_j == i && sum_i == j)
		       	{
				printf("%d si %d sunt prietene.\n", i, j);
			}
		}	
	}

	return 0;
}
