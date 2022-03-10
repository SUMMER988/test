#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define SIZE 10

//字符串复制函数, 将后面的复制到前面那个字符串
char *exchange(char a[], char b[], char c[])
{

    strncpy(c, a, SIZE);
    strncpy(a, b, SIZE);
    strncpy(b, c, SIZE);
}
int main(int argc, char const *argv[])
{
    char arr01[SIZE] = "QWERTYUIO";
    char arr02[SIZE] = "ASDFGHJKL";
    char arr00[SIZE];
    puts("请输入:");
    scanf("%9s", arr01);
    rewind(stdin);
    // scanf("%9s", arr02);
    // rewind(stdin);
    puts("before exchange:");
    puts(arr01);
    puts(arr02);
    exchange(arr01, arr02, arr00);
    puts("after exchange:");
    puts(arr01);
    puts(arr02);

    char i = '1';
    int j = (int)i;
    printf("%d\n", j);
}
