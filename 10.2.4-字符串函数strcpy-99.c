#include <stdio.h>
#include <string.h>
// char *mycpy(char *dst, const char *src)
// {
//     char *ret = dst;
//     while (*src != '\0')
//     {
//         *dst++ = *src++;
//     }
//     *dst = '\0';
//     return ret;
// }

int main(int argc, char const *argv[])
{
    char s1[] = "ABCDE";
    char s2[];
    char *p = s2;
    strncpy(s2, s1, 5);
    for (p = s2; *p != '\0'; p++)
    {
        printf("%c\t", *p); //遍历输出数组元素
    }
    return 0;
}