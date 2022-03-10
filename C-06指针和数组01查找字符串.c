#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char *my_strchr00(char *src, char *des)
{
    char *fsrc = src;
    char *rsrc = src;
    char *tdes = des;
    while (*fsrc)
    {
        rsrc = fsrc;
        while (*fsrc == *tdes && *fsrc != '\0')
        {
            fsrc++;
            tdes++;
        }
        if (*tdes == '\0')
        {
            return rsrc;
        }
        tdes = des;
        fsrc = rsrc;
        fsrc++;
    }

    return NULL;
}

int main(int argc, char const *argv[])
{
    char str1[] = "Hellollollo World";
    char str2[] = "Hello";
    char *p = my_strchr00(str1, str2);
    if (p == NULL)
    {
        puts("未找到");
    }
    else
    {
        puts(p);
        // printf("%d\n", strlen(p));
    }

    return 0;
}