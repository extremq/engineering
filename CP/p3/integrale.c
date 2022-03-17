#include <stdio.h>
#include <math.h>
#include "integrale.h"

double quad(double x)
{
    return x * x;
}

double gauss(double x)
{
    return exp(-(x * x));
}

double linear(double x)
{
    return x;
}

double sq(double x)
{
    return sqrt(1 + 1 / x);
}

double frac(double x)
{
    return x / (1 + x);
}

double integralaSimpson(double a, double b, unsigned int n, PF pf)
{
    double sum = 0;
    double dx = (b - a) / n;
    double x;

    sum = (*pf)(a);
    int counter = 0;

    for (x = a + dx; x < b; x = x + dx)
    {
        sum = sum + (counter % 2 ? 2 * (*pf)(x) : 4 * (*pf)(x));
        counter++;
    }
    sum = sum * (dx / 3);
    return sum;
}

double integralaDreptunghi(double a, double b, unsigned int n, PF pf)
{
    double sum = 0;
    double dx = (b - a) / n;
    double x;

    // dx / 2 pentru midpoint
    for (x = a; x < b; x = x + dx)
    {
        sum = sum + (*pf)(x + dx / 2);
    }
    sum = sum * dx;
    return sum;
}

double integralaTrapez(double a, double b, unsigned int n, PF pf)
{
    double sum;
    double dx = (b-a)/n;
    double x, y;
    double prevY = (*pf)(a);

    sum = prevY;

    for(x = a + dx; x < b; x = x + dx)
    {
        y = (*pf)(x);
        // Adaugam triunghiul, apoi dreptunghiul
        // Aria unui triunghi este jumatate din dreptunghiul minim care il contine.
        sum = sum + fabs(prevY - y) / 2; 
        sum = sum + (*pf)(x);
        prevY = y;
    }
    sum = sum * dx;
    return sum;
}
