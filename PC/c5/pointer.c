#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int k = 3, i;
	int * pt = 0;
	
	pt = &k;

	i = *pt;

	printf("Adresa variabilei k este %p\n", pt);
	printf("Valorea indicata de pt este %d\n", i);
	printf("Marimea in bytes alocata pentru pt este %ld\n", sizeof(pt));	
	char *p = 0;
	p = (char *)malloc(15);
	
	if(p == 0)
	{
		fprintf(stderr, "Alocare esuata\n");
		exit(EXIT_FAILURE);
	}
	
	*p = 'x';
	*(p + 1) = 'a';
	*(p + 2) = 'b';
	*(p + 3) = '\0';

	printf("%s\n", p);

	return 0;
}
