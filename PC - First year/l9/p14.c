#include <stdio.h>
#include <stdlib.h>

struct _VECTOR {
    int len;
    int* vec;
};

typedef struct _VECTOR VECTOR;

VECTOR initVector();
void afisVector(VECTOR* T);
long produsScalar(VECTOR* A, VECTOR* B);
void sortVector(VECTOR* A, int crescator);

VECTOR initVector()
{
    VECTOR T;
    scanf("%d", &T.len);

    int i;
    T.vec = (int*) malloc(T.len * sizeof(int));
    if(T.vec == 0)
    {
        fprintf(stderr, "Memorie insuficienta.\n");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < T.len; ++i)
    {
        scanf("%d", T.vec + i);
    }

    return T;
}

void afisVector(VECTOR* T)
{
    int i;
    printf("[ ");
    for(i = 0; i < T -> len; ++i)
    {
        printf("%d ", (T -> vec)[i]); 
    }

    printf("]\n");
}

long produsScalar(VECTOR* A, VECTOR* B)
{
    int i;
    long produs = 0;
    for(i = 0; i < A -> len; ++i)
    {
        produs += (A -> vec)[i] * (B -> vec)[i];
    }

    return produs;
}

void sortVector(VECTOR* A, int crescator)
{
    int i, j, aux, valid;
    for(i = 0; i < A -> len - 1; ++i)
    {
        for(j = i + 1; j < A -> len; ++j)
        {
            valid = 
            (crescator == -1 && (A -> vec)[i] < (A -> vec)[j]) || 
            (crescator == 1 && (A -> vec)[i] > (A -> vec)[j]);
            
            if (valid)
            {
                aux = (A -> vec)[i];
                (A -> vec)[i] = (A -> vec)[j];
                (A -> vec)[j] = aux;
            }
        }
    }
}

int main()
{
    VECTOR A, B;

    A = initVector();
    B = initVector();
    afisVector(&A);
    afisVector(&B);
    
    printf("Produsul scalar este %ld.\n", produsScalar(&A, &B));
    
    sortVector(&A, 1);
    afisVector(&A);
    sortVector(&B, -1);
    afisVector(&B);
    
    // Nu uita!
    free(A.vec);
    free(B.vec);
     
    return 0;
}
