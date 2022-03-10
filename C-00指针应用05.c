#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void remove_space(char *ch) //删除空格函数
{
    char *ftemp = ch;
    char *rtemp = ch;
    while (*ftemp != '\0')
    {
        if (*ftemp != ' ')
        {
            *rtemp = *ftemp;
            rtemp++;
        }
        ftemp++;
    }
    *rtemp = '\0';
    printf("ch in %s is %s\n", __func__, ch);
}

int main(void)
{
    char ch[] = "H E          L L O  W OR  LD   ";
    remove_space(ch);
    printf("ch in %s is %s\n", __func__, ch);

    return 0;
}