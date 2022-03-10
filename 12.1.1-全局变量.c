#include <stdio.h>

int f(void);

int aAll = 12;

int main(int argc, char const *argv[])
{
    printf("in %s aAll=%d\n", __func__, aAll);
    f();
    printf("agn in %s aAll=%d\n", __func__, aAll);
    return 0;
}

int f(void)
{
    printf("in %s gAll=%d\n", __func__, aAll);
    aAll += 2;
    printf("agn in %s gAll=%d\n", __func__, aAll);
    return aAll;
}