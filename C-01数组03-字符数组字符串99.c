#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define SIZE 100
void revstr(char *s)
{
    char *p = s;
    char c;
    while (*p)
    {
        p++;
    }
    p--;
    if (s < p)
    {
        c = *s;
        *s = *p;
        *p = '\0';
        revstr(s + 1); // E B C D 0    (c='A',s='E')    E D C B 0   E D C B A
        *p = c;        // E D C 0 0    (c='B',s='D')    E D C 0 0   E D C B 0
                       // E D C 0 0    (s=p)
    }
}

int main(int argc, char const *argv[])
{
    char str[SIZE];
    while (1)
    {
        gets(str);
        revstr(str);
        puts(str);
    }
}