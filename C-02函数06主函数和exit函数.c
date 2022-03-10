#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

void func()
{
    // printf("Hello World!\n");
    puts("Hello World!");
}

void print()
{
    int Num;
    scanf("%d", &Num);
    int i = 0;
    while (i < Num)
    {
        func();
        // exit(0);
        i++;
    }

    return;
}

int main(int argc, char const *argv[])
{
    print();
    puts("End!");

    return 0;
}