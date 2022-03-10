#include <stdio.h>

int main()
{
    unsigned int a = 1, b = 0;
    while (a > 0)
        a++;
    a -= 1;
    printf("int数据类型最大数是:%u\n", a);
    b++;
    while ((a = a / 10) != 0)
    {
        b++;
    }
    printf("int数据类型最大的数的数位是:%d\n", b);
    return 0;
}