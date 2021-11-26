#ifndef __GEOMETRIE_H_
#define __GEOMETRIE_H_

struct _PUNCT {
	double x;
	double y;
};

typedef struct _PUNCT punct;

void citestePunct(punct* p);
void afiseazaPunct(punct* p);

punct* nPuncte(int n);
double distantaPuncte(punct* a, punct* b);

#endif
