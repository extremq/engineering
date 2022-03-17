#ifndef __VECTORREAL_H_
#define __VECTORREAL_H_

#define LIMITA_MARIME_VECTOR 100

void citireVector(int *n, double *v);
void afisareVector(int n, double *v);
double valoareMedie(int n, double *v);
double abatereMediePatratica(int n, double *v);
int elementeSubMedie(int n, double *v);
int vectorElementeSubMedie(int n, double *v, double *y);
void afisareRezultate(int *n, double *v, double *y);

#endif
