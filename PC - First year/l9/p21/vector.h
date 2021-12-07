#ifndef __VECTOR_H_
#define __VECTOR_H_

struct _VECTORR {
    char* nume;
    int len;
    double* arr;
};

typedef struct _VECTORR vReal;

void setName(vReal* T);
void setArray(vReal* T);
void setVector(vReal* T);
void printArray(vReal* T);

int getSortChoice();
void sortArray(vReal* T, int option);

void swapDouble(double* a, double* b);

void dealloc(vReal* T);

#endif
