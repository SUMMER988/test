#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define SIZE 5
char *exchange(char a[], char b[], char c[])
{

    strncpy(c, a, SIZE - 1);
    strncpy(a, b, SIZE - 1);
    strncpy(b, c, SIZE - 1);
}
int main(int argc, char const *argv[])
{
    char arr01[SIZE];
    char arr02[SIZE];
    char arr03[SIZE];
    puts("One:");
    gets(arr01);
    rewind(stdin);
    puts("Another:");
    gets(arr02);

    exchange(arr01, arr02, arr03);
    puts(arr01);
    puts(arr02);

    return 0;

    // while (1)
    // {
    //     char ch[SIZE];
    //     scanf("%3s", ch);
    //     rewind(stdin);
    //     puts(ch);
    // }
}