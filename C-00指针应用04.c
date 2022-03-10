#include <stdio.h>

static int a = 10;
int *getA()
{
    return &a;
}

int main(int argc, char const *argv[])
{
    *(getA(a)) = 111;
    printf("%d\n", a);

    return 0;
}