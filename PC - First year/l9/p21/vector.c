#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


#include "vector.h"

void setName(vReal* T)
{
    T -> name = (char*) malloc(sizeof(char) * MAX_NAME_LENGTH);
    if(T -> name == 0)
    {
        fprintf(stderr, "Couldn't allocate memory for name buffer.\n");
        exit(EXIT_FAILURE);
    }

    // Daca sirul e mai mare decat MAX_NAME_LENGTH, programul tot va scrie
    // peste adrese. Aici ar trebui verificate lungimile.
    scanf("%s", T -> name);
}

void setArray(vReal* T, int len)
{
    T -> len = len;

    // Presupun ca sunt obligat sa impart citirea si pe main,
    // si pe header.
    //scanf("%d", &(T -> len));

    T -> arr = (double*) malloc(sizeof(double) * T -> len);
    if(T -> arr == 0)
    {
        fprintf(stderr, "Couldn't allocate memory for array buffer.\n");
        exit(EXIT_FAILURE);
    }

    int i;
    for(i = 0; i < T -> len; ++i)
    {
        scanf("%lf", T -> arr + i);
    }
}

void printArray(vReal* T)
{
    int i;
    printf("%s: [ ", T -> name);
    for(i = 0; i < T -> len; ++i)
    {
        printf("%.3lf ", T -> arr[i]);
    }
    printf("]\n");
}

int getSortChoice()
{
    int sortChoice = 0;
    scanf("%d", &sortChoice);

    return sortChoice;
}

void sortArray(vReal* T, int option)
{
    _Bool finished = false;

    int i, len = T -> len;
    double* arr = T -> arr;

    while(!finished)
    {
        finished = true;

        for(i = 0; i < len - 1; ++i)
        {
            if(assertSwap(arr[i], arr[i + 1], option))
            {
                swapDouble(&arr[i], &arr[i + 1]);
                finished = false;
            }
        }

        --len;
    } 
}

_Bool assertSwap(double a, double b, int option)
{
    if(option == ASCENDING_VALUE)
    {
        return a > b;
    }
    else if(option == ASCENDING_DIGIT_SUM)
    {
        // Practic, double poate avea valori imense
        // fata de cat poate stoca int, dar presupun
        // ca suntem cuminti de data aceasta si vom
        // da cast.
        return getDigitSum((long) a) > getDigitSum((long) b);   
    }
    else {
        // Warning daca nu avem default return
        return false;
    }
}

int getDigitSum(long a)
{
    int sum = 0;
    
    // Nu mai importam math.h degeaba.
    a = a < 0 ? -a : a;

    while(a)
    {
        sum += a % 10;
        a /= 10;
    }

    return sum;
}

void swapDouble(double* a, double* b)
{
    double aux = *a;
    *a = *b;
    *b = aux;
}

void dealloc(vReal* T)
{
    free(T -> name);
    free(T -> arr);
}
