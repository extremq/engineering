#include <stdlib.h>
#include <stdio.h>
#include "geometrie.h"

int main(void)
{
	int n;

	scanf("%d", &n);
	
	punct* p = nPuncte(n);

	int i;
	for(i = 0; i < n; ++i)
	{
		citestePunct(p + i);
		afiseazaPunct(p + i);
	}

	printf("%.4lf\n", distantaPuncte(p, p + 1));

	return 0;	
}
