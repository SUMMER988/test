#include <stdio.h>
#include <stdlib.h>
//  
void swap(int *x, int *y)
{
    int i = *x;
    *x = *y;
    *y = i;
}

int main(int argc, char const *argv[])
{
    int a = 5;
    int b = 6;
    swap(&a, &b);
    printf("%d,%d\n", a, b);
}