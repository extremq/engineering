#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Terminal colors
 */
#define RED "\x1B[31m"
#define NRM  "\x1B[0m" // Default

/*
 * ██╗██╗██╗
 * ██║██║██║
 * ██║██║██║
 * ╚═╝╚═╝╚═╝
 * ██╗██╗██╗
 * ╚═╝╚═╝╚═╝
 * Choose which data type you want to use. (Numerical)
 * Replace int with double, float or long.
 */
#define DATA_TYPE int
#define DATA_LITERAL "int"

typedef DATA_TYPE T;

/*
 * General memory check for generic pointer.
 */
void checkMemory(void* ptr)
{
    if(ptr == NULL)
    {
        fprintf(stderr, RED "Not enough memory available.\n" NRM);
        exit(EXIT_FAILURE);
    }
}

/*
 * Dynamic input based on DATA_TYPE macro.
 */
void getInput(T* ptr)
{
    char fmt[4];
    memset(fmt, '\0', sizeof(fmt));

    if (!strcmp(DATA_LITERAL, "int"))
    {
        strcpy(fmt, "%d");
    }
    else if(!strcmp(DATA_LITERAL, "float"))
    {
        strcpy(fmt, "%f");
    }
    else if(!strcmp(DATA_LITERAL, "long"))
    {
        strcpy(fmt, "%ld");
    }
    else if(!strcmp(DATA_LITERAL, "double"))
    {
        strcpy(fmt, "%lf");
    }

    scanf(fmt, ptr);
}

/*
 * Dynamic output based on DATA_TYPE macro.
 */
void output(T* ptr)
{
    char fmt[4];
    memset(fmt, '\0', sizeof(fmt));

    if (!strcmp(DATA_LITERAL, "int"))
    {
        strcpy(fmt, "%d");
    }
    else if(!strcmp(DATA_LITERAL, "float"))
    {
        strcpy(fmt, "%f");
    }
    else if(!strcmp(DATA_LITERAL, "long"))
    {
        strcpy(fmt, "%ld");
    }
    else if(!strcmp(DATA_LITERAL, "double"))
    {
        strcpy(fmt, "%lf");
    }

    printf(fmt, *ptr);
}

void readMatrix(T** ptr, int l, int c)
{
    int i, j;
    for(i = 0; i < l; ++i)
    {
        for(j = 0; j < c; ++j)
        {
            getInput(&ptr[i][j]);
        }
    }
}

void printMatrix(T** ptr, int l, int c)
{
    int i, j;
    for(i = 0; i < l; ++i)
    {
        for(j = 0; j < c; ++j)
        {
            output(&ptr[i][j]);
            printf(" ");
        }
        printf("\n");
    }
}

/*
 * When shifting by k positions, every i-th element
 * must be assigned the i - k-th element. Consider:
 * [ 1 2 3 4 ] shifted by 2
 * [ 3 4 1 2 ]
 *   0 1 2 3
 * The element at index 2 becomes the element at 
 * index 2 - 2 = 0.
 * If the difference is negative, we instead
 * substract from the end of the line.
 */
void shift(T* line, int size, int offset, T* temp)
{
    int j, index;

    // Copying the line
    for(j = 0; j < size; ++j)
    {
        temp[j] = line[j];
    }

    for(j = size - 1; j >= 0; --j)
    {
        index = j - offset < 0 ?
           size - (offset - j) :
                     j - offset;
        line[j] = temp[index];
    }
}

int main(void)
{
    T** A = 0;
    int l, c; // Lines, Columns

    scanf("%d", &l);
    scanf("%d", &c);

    A = (T**) malloc(sizeof(T*) * l);
    checkMemory(A);

    int i;
    for(i = 0; i < l; ++i)
    {
        A[i] = (T*) malloc(sizeof(T) * c);
        checkMemory(A[i]);
    }

    readMatrix(A, l, c);

    T* temp = (T*) malloc(sizeof(T) * c);
    checkMemory(temp);

    for(i = 0; i < l; ++i)
    {
        shift(A[i], c, i, temp);
    }

    printMatrix(A, l, c);

    for(i = 0; i < l; ++i)
    {
        free(A[i]);
    }
    free(A);

    return 0;
}
