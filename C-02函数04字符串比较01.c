#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include <time.h>
// #include <math.h>

int my_strcmp(char ch1[], char ch2[])
{
    char *p = ch1;
    char *q = ch2;
    while (*p && *p == *q)
    {
        printf("%c\t", *p);
        printf("%c\t", *q);
        p++;
        q++;
        puts("");
    }
    printf("%c\t", *p);
    printf("%c\t", *q);
    if (*p > *q)
    {
        // puts("数组A大于数组B");
        return 1;
    }
    else if (*p < *q)
    {
        // puts("数组A小于数组B");
        return -1;
    }
    else
    {
        // puts("数组A等于数组B");
        return 0;
    }
}

void cmp(int flag)
{
    if (flag == 0)
    {
        puts("两个数组字符串相等");
    }
    else if (flag == 1)
    {
        puts("A>B");
    }
    else if (flag == -1)
    {
        puts("A<B");
    }
}
int main(int argc, char const *argv[])
{
    char A[100];
    char B[100];
    gets(A);
    gets(B);
    printf("%d\n", 'A' - 'a');
    int res = my_strcmp(A, B);
    cmp(res);

    return 0;
}