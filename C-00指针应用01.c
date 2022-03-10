#include <stdio.h>

int main(int argc, char const *argv[])
{
    int *p[3]; //    指针数组
    int a = 1;
    int b = 2;
    int c = 3;
    int i = 0;

    p[0] = &a;
    p[1] = &b;
    p[2] = &c;
    printf("&a is %p\n", &a);
    printf("&b is %p\n", &b);
    printf("&c is %p\n", &c);

    for (i = 0; i < sizeof(p) / sizeof(p[0]); i++)
    {
        printf("%d\t", *p[i]);
        printf("p[%d] is %p\n", i, p[i]);
    }
    printf("\n");
    *p[1] = 99;
    printf("%d\n", *p[1]);

    return 0;
}