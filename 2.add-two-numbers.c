#include <stdio.h>
#include <stdlib.h>

void fun(int a[])
{
    a[0]++;
}
int main()
{
    int a[10];
    a[0] = 1;
    fun(a);
    printf("%d\n", a[0]);
    system("pause");
}