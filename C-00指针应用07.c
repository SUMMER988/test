#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *my_strchr(char *src, char *dst)
{
    char *fsrc = src;
    char *rsrc = src;
    char *tdst = dst;
    while (*fsrc)
    {
        rsrc = fsrc;
        while (*fsrc == *tdst && *fsrc != '\0')
        {
            fsrc++;
            tdst++;
        }
        if (*tdst == '\0')
        {
            return rsrc;
        }
        tdst = dst;
        fsrc = rsrc;
        fsrc++;
    }
    return NULL;
}
int main()
{
    char src[] = "hellllllolleworldllo";

    char dst[] = "llo";
    char *p = my_strchr(src, dst);
    printf("%s\n", p);
    return EXIT_SUCCESS;
}