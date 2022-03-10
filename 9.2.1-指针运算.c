
#include <stdio.h>

int main(void)
{
    char ac[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -1};
    char *p = &ac[0];
    int i;
    while (*p != -1)
    {
        printf("%d\n", *p++);
    }
    // int ai[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // int *q = ai;
    // while (*q)
    // {
    //     printf("%d\t", *q++);
    // }
    // return 0;
}