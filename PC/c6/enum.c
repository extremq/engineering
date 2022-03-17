#include <stdio.h>

int main(void)
{
	enum CULORI {ALB, ROSU, PORTOCALIU = 5, GALBEN, VERDE = 10,
		ALBASTRU, INDIGO = 13, VIOLET, NEGRU = 20};
	int c = GALBEN;
	printf("%d\n", c);

	enum TESTE {T1 = -3, T2, T3 = 9, T4 = 6};
	int t = T1;
	printf("%d\n", t);

	t = T2;
	printf("%d\n", t);
}
