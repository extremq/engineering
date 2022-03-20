#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

struct MENU_ITEM {
    char *nume;
    double (*f) (unsigned int n, unsigned int m, double (*mat)[]);
};

int main(void)
{
    struct MENU_ITEM menu[3] = {
        { "Norma 1", norma_1 },
        { "Norma 2", norma_2 },
        { "Norma infinit", norma_inf }
    };

    unsigned n, m;

    puts("Ce marime are matricea?");
    puts("Linii: ");
    scanf("%u", &n);
    puts("Coloane: ");
    scanf("%u", &m);

    printf("%u %u\n", n, m);

    double (*mat)[n];
    mat = (double (*)[n]) malloc(n * sizeof(*mat));
    if (mat == 0)
    {
        fprintf(stderr, "Alocare de memorie esuata.\n");
        exit(EXIT_FAILURE);
    }
    
    /*
    int i, j;
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < m; ++j)
        {
            printf("%lf ", mat[i][j]);
        }
        printf("\n");
    }
    */
    return 0;
}
