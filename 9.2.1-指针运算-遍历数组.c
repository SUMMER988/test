
#include <stdio.h>

int main(void)
{
    char ac[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    char *p = &ac[0];
    int i = 0;
    // for (i = 0; i < sizeof(ac) / sizeof(ac[0]); i++)
    // {
    //     printf("%d\t", ac[i]);
    // }
    for (p = ac, i = 0; i < sizeof(ac) / sizeof(ac[0]); i++, p++)
    {
        printf("%d\t", *p);
    }
    // int ai[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // int *q = ai;
    // while (*q)
    // {
    //     printf("%d\t", *q++);
    // }
    // return 0;
}