//数组变量是特殊的指针
#include <stdio.h>

void minmax(int a[], int len, int *min, int *max);

int main(void)
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 12, 13, 14, 16, 17, 21, 23, 55};
    int min, max;
    printf("main sizeof(a)=%lu\n", sizeof(a));
    printf("main a=%p\n", a);
    minmax(a, sizeof(a) / sizeof(a[0]), &min, &max);
    printf("%d\n", a[0]);
    printf("min=%d,max=%d\n", min, max);
    int *p = &min;
    printf("*p=%d\n", *p);
    printf("p[0]=%d\n", p[0]);
    printf("*a=%d\n", *a);
    // int b[]-- > int *const b;
    // int *q = a;
    return 0;
}

void minmax(int a[], int len, int *min, int *max) // a[]实际上是指针，等价于*a
{
    int i;
    printf("minmax sizeof(a)=%lu\n", sizeof(int *)); // sizeof(a)==sizeof(int*)
    printf("minmax a=%p\n", a);
    a[0] = 1000;
    *min = *max = a[0];
    for (i = 1; i < len; i++)
    {
        if (a[i] < *min)
        {
            *min = a[i];
        }
        if (a[i] > *max)
        {
            *max = a[i];
        }
    }
}