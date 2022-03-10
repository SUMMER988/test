#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define SIZE 100
extern int add(int, int);
extern void swap(int *a, int *b);
void print(int a, int b);
int main(int argc, char const *argv[])
{
    // char c[SIZE];
    // gets(c);
    // scanf("%[^\n]", c);
    // puts(c);
    int a = 0;
    int b = 0;
    scanf("%d", &a);
    scanf("%d", &b);
    puts("before swap:");
    print(a, b);
    swap(&a, &b);
    int c = add(a, b);
    puts("after swap:");
    print(a, b);
    printf("c=%d\n", c);

    return 0;
}

int add(int a, int b)
{
    return (a + b);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print(int a, int b)
{
    printf("a=%d\n", a);
    printf("b=%d\n", b);
}
