#include <stdio.h>

void swap(int *pa, int *pb); //  交换变量

int main(void)
{
    int a = 5;
    int b = 6;
    swap(&a, &b);
    printf("a=%d,b=%d\n", a, b);

    return 0;
}

void swap(int *pa, int *pb)
{
    int i = *pa;
    *pa = *pb;
    *pb = i;
}