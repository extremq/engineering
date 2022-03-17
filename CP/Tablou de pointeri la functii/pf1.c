#include <stdio.h>
#include <math.h>

int main(void)
{
	double (*fm[])(double) = {
		sin,  asin, cos, acos, tan, atan};
	int i;
	double x;
	double dx = 0.05;

	int nf = sizeof(fm)/sizeof(fm[0]);

	puts("Tabelul");
	printf("%5s %10s %10s %10s %10s %10s %10s\n\n","x","sin","arcsin","cos","arccos", "tg", "arctg");
	for(x=0; x<=1; x+= dx)
	{
		printf("%5.3lf ", x);
		for(i=0; i<nf; i++)
			printf("%10.3lf ", (*fm[i])(x));
		printf("\n");
	}
	return 0;
}
