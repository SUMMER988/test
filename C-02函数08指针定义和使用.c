#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main0801(int argc, char const *argv[])
{
    int a = 10;
    int *p = &a;
    *p = 100;
    printf("%p\n", &a);
    printf("%p\n", p);
    printf("%d\n", a);
    printf("%d\n", *p);

    return 0;
}

int main(int argc, char const *argv[])
{
    // char ch = 'a';
    // char *p = &ch;

    int a = 10;
    int *p = &a;
    // 32位系统，所有指针都是32位-4字节
    // 64位系统，所有指针都是64位-8字节
    printf("%d\n", sizeof(char *));
    printf("%d\n", sizeof(short *));
    printf("%d\n", sizeof(int *));
    printf("%d\n", sizeof(double *));
    printf("%d\n", sizeof(long *));
    printf("%d\n", sizeof(long long *));

    return 0;
}