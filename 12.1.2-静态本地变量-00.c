#include <stdio.h>

int f(void);

// int all = 12;

int main(int argc, char const *argv[])
{
    f();
    f();
    f();
    return 0;
}

int f(void)
{
    int all = 1;
    printf("in %s all=%d\n", __func__, all);
    all += 2;
    printf("agn in %s all=%d\n", __func__, all);
    return all;
}