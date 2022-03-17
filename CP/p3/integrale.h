#ifndef INTEGRALE_H_
#define INTEGRALE_H_

typedef double (*PF)(double);

double integralaTrapez(double a, double b, unsigned int n, PF pf);
double integralaDreptunghi(double a, double b, unsigned int n, PF pf);
double integralaSimpson(double a, double b, unsigned int n, PF pf);
double quad(double);
double frac(double);
double sq(double);
double gauss(double);
double linear(double);

#endif