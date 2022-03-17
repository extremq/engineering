#ifndef __VECTOR_H_
#define __VECTOR_H_

#define MAX_NAME_LENGTH 256
#define ASCENDING_VALUE 1
#define ASCENDING_DIGIT_SUM 2

struct _VECTORR {
    char* name;
    int len;
    double* arr;
};

typedef struct _VECTORR vReal;

void setName(vReal* T);
void setArray(vReal* T, int len);
void printArray(vReal* T);

int getSortChoice();
void sortArray(vReal* T, int option);

_Bool assertSwap(double a, double b, int option);
int getDigitSum(long a);
void swapDouble(double* a, double* b);

void dealloc(vReal* T);

#endif
