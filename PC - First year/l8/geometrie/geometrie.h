#ifndef __GEOMETRIE_H_
#define __GEOMETRIE_H_

struct _PUNCT {
	double x;
	double y;
};

typedef struct _PUNCT punct;

void citestePunct(punct* p);
void citestePuncte(punct* p, int n);
void afiseazaPunct(punct* p);
void afiseazaPuncte(punct* p, int n);

punct* nPuncte(int n);
double distantaPuncte(punct* a, punct* b);

double arieTriunghi(punct*a, punct* b, punct* c);
double semiperimetruTriunghi(punct* a, punct* b, punct* c);

double ariePoligon(punct* p, int laturi);
double perimetruPoligon(punct* p, int laturi);

#endif
