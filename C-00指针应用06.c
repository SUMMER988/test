#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *my_strchr(char *str, char ch)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] == ch)
        {
            return &str[i];
            // break;
        }
        i++;
    }
    return NULL;
}
int main()
{
    char str[] = "hello,world";
    char c;
    scanf("%c", &c);
    // getchar();
    char *p = my_strchr(str, c);
    if (p)
    {
        printf("%s\n", p);
    }
    else
    {
        printf("NO\n");
    }
    return EXIT_SUCCESS;
}