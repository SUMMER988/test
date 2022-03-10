#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char *my_strchr00(char *str, char L)
{
    while (*str)
    {
        if (*str == L)
        {
            return str;
        }
        str++;
    }
    return NULL;
}

int main(int argc, char const *argv[])
{
    char str[] = "Hello World!";
    char *p = my_strchr00(str, '!');
    if (p == NULL)
    {
        puts("未找到");
    }
    else
    {
        puts(p);
        printf("%d\n", strlen(p));
    }

    return 0;
}