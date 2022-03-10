#include <stdio.h>

int f(void);

int gall = 12;

int main(int argc, char const *argv[])
{
    f();
    return 0;
}

int f(void)
{
    int s = 0;
    static int a = 40;
    static int i = 30;
    static int j = 20;
    printf("&gall=%p\n", &gall);
    printf("&a   =%p\n", &a);
    printf("&i   =%p\n", &i);
    printf("&j   =%p\n", &j);
    printf("&s   =%p\n", &s);
    printf("in %s all=%d\n", __func__, i);
    i += 2;
    printf("agn in %s all=%d\n", __func__, i);
    return i;
}