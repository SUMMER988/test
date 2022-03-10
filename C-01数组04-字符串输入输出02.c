#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define SIZE 10

int main(int argc, char const *argv[])
{
    char ch[SIZE];

    while (1)
    {
        gets(ch);
        fputs(ch, stdout);
        // fputs()不会输出\n
        //  printf("%s",ch);

        return 0;
    }
}