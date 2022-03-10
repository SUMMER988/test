#include <stdio.h>

int main()
{
    int a, n;
    scanf("%d %d", &a, &n);
    while (1)
    {
        int sum = 0;
        int i;
        int t = 0;
        for (i = 0; i < n; i++)
        {
            t = t * 10 + a;
            sum += t;
        }
        printf("%d\n", sum);
        rewind(stdin);
        scanf("%d %d", &a, &n);
    }
}