#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int add(int a, int b)
{
    // int sum = a + b;
    // return sum;
    return a + b;
}
void swap(int *a, int *b)
{
    puts("交换前:");
    printf("a=%d\n", *a);
    printf("b=%d\n", *b);
    int p = *a;
    *a = *b;
    *b = p;
}
void print()
{
    printf("hello world!\n");
}
int main(int argc, char const *argv[])
{
    int a = 3;
    int b = 4;
    int c = add(a, b);
    printf("%d\n", c);
    print();
    swap(&a, &b);
    puts("交换后:");
    printf("a=%d\n", a);
    printf("b=%d\n", b);
    return 0;
}