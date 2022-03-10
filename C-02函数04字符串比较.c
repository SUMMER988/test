#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include <time.h>
// #include <math.h>

int my_strcmp(char ch1[], char ch2[])
{
    int i = 0;
    while (ch1[i] == ch2[i])
    {
        if (ch1[i] == '\0')
        {
            return 0;
        }
        printf("%c\t", ch1[i]);
        i++;
    }

    return ch1[i] > ch2[i] ? 1 : -1;
}
void cmp(int flag)
{
    puts("");
    if (flag == 0)
    {
        puts("相等");
    }
    else
    {
        puts("不相等");
    }
}
int main(int argc, char const *argv[])
{
    char a[] = "OKK";
    char b[] = "OKK";
    cmp(my_strcmp(a, b));

    return 0;
}