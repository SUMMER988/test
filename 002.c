#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 100;
    int *p = &a;
    *p = 200;
    printf("%d\n", *p);

    return 0;
}