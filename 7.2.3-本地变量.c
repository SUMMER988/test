#include <stdio.h>
void swap(int x, int y);

int main(void)
{
    int a = 5;
    int b = 6;

    swap(a, b);

    printf("a=%d b=%d\n", a, b);

    return 2;
}

void swap(int x, int y)
{
    int swap;
    int t = x;
    x = y;
    y = t;
}