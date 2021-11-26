#include <stdio.h>
#include <math.h>

int main(void)
{
	int x;
	scanf("%d", &x);

	while(x)
	{
		int radacina = sqrt(x);
		
		printf("%d:%d\n", x, radacina * radacina);
		scanf("%d", &x);
	}
	
	return 0;
}
