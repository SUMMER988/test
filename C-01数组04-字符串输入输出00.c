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
        // scanf("%[^\n]", ch);     正则表达式，获取带空格字符串
        puts(ch);

        // return 0;
    }
}