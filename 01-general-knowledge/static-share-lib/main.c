#include<stdio.h>


#include "inc/hello.h"
#include "inc/my_math.h"

int main()
{
    hello();
    printf("\n");
    printf("4+5= %d", sum(4,5));
    return 0;
}