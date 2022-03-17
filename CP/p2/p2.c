#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "integrale.h"

struct MENU_ITEM {
    char *nume;
    double (*f) (double a, double b, unsigned int n, double (*) (double));
};

int meniu(struct MENU_ITEM meniu[], unsigned int nf, char *msg)
{
    int optiune;
    unsigned int i; // Nu cred ca e necesar register? Hmm.
    puts(msg);
    
    for (i = 0; i < nf; ++i)
    {
        printf("\t%d - %s\n", i + 1, meniu[i].nume);
    }

    printf("\t0 - exit\n");
    printf("\t>>> ");
    scanf("%d", &optiune);

    return optiune;
}

int main(void)
{
    struct MENU_ITEM menu[] = {
        {"Calculul integralei prin metoda trapezelor", integralaTrapez},
        {"Calculul integralei prin metoda dreptunghiurilor", integralaDreptunghi},
        {"Calculul integralei prin metoda Simpson", integralaSimpson}
    };

    int optiune = meniu(menu, 3, "Prin ce metoda vrei sa calculezi integrala?");
    if (optiune == 0) {
        exit(0);
    }

	double a, b;
	double val;
	unsigned int n;

	printf("a = "); scanf("%lf", &a);
	printf("b = "); scanf("%lf", &b);

	printf("Numar de diviziuni: "); scanf("%d", &n);
 
	val = menu[optiune - 1].f(a, b, n, f);

	printf("Valoarea integralei este %.3lf\n", val);

	return 0;
}
