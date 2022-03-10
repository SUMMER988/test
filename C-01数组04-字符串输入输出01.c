#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define SIZE 10

int main(int argc, char const *argv[])
{
    char ch[SIZE];

    while (1)
    {
        gets(ch);
        // fgets(ch, sizeof(ch), stdin);
        // fgets()可以接收空格
        // fgets()获取字符串少于元素个数会有\n 大于等于 没有\n
        puts(ch);
        // puts()自带换行
        puts("hello\0world");

        return 0;
    }
}