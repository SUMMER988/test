#include <stdio.h>
//      递归
int func(int i)
{
    if (i == 0)
    {
        return 0;
    }
    return i + func(i - 1);
}
int main(int argc, char const *argv[])
{
    int num;
    puts("请输入一个数字:");
    scanf("%d", &num);
    int i = func(num);
    printf("%d\n", i);

    return 0;
}