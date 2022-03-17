#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "integrale.h"

#define N 1000

int main(void)
{
    double (*fnc[5])(double) = {
        gauss,
        linear,
        quad,
        sq,
        frac
    };

    double ranges[5][2] = {
        {0, 1},
        {1, 3},
        {0, 3},
        {1, 4},
        {1, 5}
    };

    printf("+--------------+--------------+--------------+--------------+\n");	
    printf("| %12s | %12s | %12s | %12s |\n", "Integrala", "Trapez", "Dreptunghi", "Simpson"); 
    printf("+--------------+--------------+--------------+--------------+\n");	
    
    unsigned int i = 0;
    char nume[3] = "I.";
    double trapez, dreptunghi, simpson;
    
    for (; i < 5; ++i)
    {
        nume[1] = '0' + i + 1;
        trapez = integralaTrapez(ranges[i][0], ranges[i][1], N, fnc[i]);
        dreptunghi = integralaDreptunghi(ranges[i][0], ranges[i][1], N, fnc[i]);
        simpson = integralaSimpson(ranges[i][0], ranges[i][1], N, fnc[i]); 
        printf("| %12s | %12.6lf | %12.6lf | %12.6lf |\n", nume, trapez, dreptunghi, simpson);

    }

    printf("+--------------+--------------+--------------+--------------+\n");

    return 0;
}
