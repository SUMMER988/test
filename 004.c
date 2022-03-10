#include <stdio.h>
#include <stdlib.h>
void swap(int *p, int *q)
{

    int temp = *p;
    *p = *q;
    *q = temp;
    puts("Test0");
}
int main(int argc, char const *argv[])
{
    int a = 3;
    int b = 4;
    swap(&a, &b);
    // getchar();
    printf("%d\n", a);
    printf("%d\n", b);
    puts("Test1");
    return 0;
}