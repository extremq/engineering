#include <stdio.h>

#include "vector.h"

int main(void)
{
    vReal v;
    
    setName(&v);
    setArray(&v);

    printArray(&v);

    return 0;
}
