#include <stdio.h>
#include <stdbool.h>

int main()
{
    int a;
    scanf("%d", &a);
    if (a > 0 && ++a > 1)
    {
        printf("OK\n");
    }
    else
    {
        printf("NO\n");
    }
    printf("a=%d\n", a);

    return 0;
}