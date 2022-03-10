#include <stdio.h>
#include <stdlib.h>
// 类型转换
// char->short->int->long->long long
// int->float->double
// 强制类型转换——（类型）值——（int）10.2，（short）32
// 注意安全性，小的变量不总能表达大的变量，比如（short）32768
int main()
{
    int i = 32768;
    // scanf("%d", &n);
    short s = (short)i;
    printf("s=%d,i=%d\n", s, i);

    int a = 7;
    int b = 6;
    double j = (double)a / b;
    printf("j=%f\n", j);
    return 0;
}