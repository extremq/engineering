#include <stdio.h>

int main(void)
{
	int a, b;
	scanf("%d %d", &a, &b);

	int r;
	while(b)
	{
		r = a % b;
		a = b;
		b = r;
	}

	printf("%d\n", a);
	
	return 0;
}
