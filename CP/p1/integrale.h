#ifndef INTEGRALE_H_
#define INTEGRALE_H_

typedef double (*PF)(double);

double integralaTrapez(double a, double b, unsigned int n, PF pf);
double f(double x);

#endif
