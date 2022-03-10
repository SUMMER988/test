#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i = 0;
    int n = sizeof(a) / sizeof(a[0]);
    printf("n=%d\n", n);

    int *p = a + n - 1;
    for (i = 0; i < n; i++)
    {
        printf("%d\t", *p);
        p--;
    }
    printf("\n");

    return 0;
}