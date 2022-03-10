#include <stdio.h>
#include <string.h>

char *mycpy(char *dst, const char *src)
{
    // char idx = 0;
    // while (src[idx])
    // {
    //     dst[idx] = src[idx];
    //     idx++;
    // }
    // dst[idx] = '\0';
    char *ret = dst;
    while (*src)
    {
        *dst++ = *src++;
    }
    *dst = '\0';

    return ret;
}

// int main(int argc, char const *argv[])
int main(int argc, char const *argv[])
{
    char s1[100] = "12345";
    char s2[2];
    char *p = s2;
    mycpy(s2, s1);
    int i = 0;
    for (p = s2; *p != '\0'; p++)
    {
        printf("%c\t", *p);
    }

    return 0;
}