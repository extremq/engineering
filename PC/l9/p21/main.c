#include <stdio.h>

#include "vector.h"

int main(void)
{
    vReal v;

    int stopInput = 0;

    while(!stopInput)
    {
        printf("What is the name of the array?\n");
        setName(&v);

        int len;
        printf("How many elements does your array have?\n");
        scanf("%d", &len);

        printf("Type the numbers.\n");
        setArray(&v, len);

        printf("The array is:\n");
        printArray(&v);

        printf("How do you want the array sorted? 1 = ascending by value, 2 = ascending by digit sum\n");
        int option = getSortChoice();
        sortArray(&v, option);

        printf("The sorted array is:\n");
        printArray(&v);

        dealloc(&v);
        
        printf("Continue? 0 = yes\n");
        scanf("%d", &stopInput);
    }
    return 0;
}
