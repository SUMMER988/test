#include <stdio.h>

int main()
{
    int a = 2;
    int b = 3;
    int c = a + b;
    int *p = &c;
    *p = 20;
    puts("结果为:");
    printf("%d\n", c);
    // // getchar();
    return 0;
}