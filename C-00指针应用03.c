#include <stdio.h>
#include <stdlib.h>
//  数组名做函数参数，函数的形参会退化为指针，表现为sizeof(a)实际上为sizeof(int *)
void printArray(int *a, int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(a) / sizeof(a[0]);

    printArray(a, n);
    return 0;
}