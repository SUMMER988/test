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
    char s1[6] = "ABCD";
    char s2[6] = "XO";
    char *p = s1;
    // strncpy(s2, s1, 6);
    printf("strlen(s1)=%d,sizeof(s1)=%d\n", strlen(s1), sizeof(s1));
    for (p = s1; *p != '\0'; p++)
    {
        printf("%c\t", *p); //遍历输出数组元素
    }
    return 0;
}