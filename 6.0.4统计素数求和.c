#include <stdio.h>
#include <stdlib.h>
int isPrime(int i)
{
    int ret = 1;
    int k;
    for (k = 2; k < i - 1; k++)
    {
        if (i % k == 0)
        {
            ret = 0;
            break;
        }
    }
    return ret;
}

int main()
{
    int m, n;
    int i;
    int cnt = 0;
    int sum = 0;

    scanf("%d %d", &m, &n);
    while (1)
    {
        if (m == 1)
        {
            m = 2;
        }
        for (i = m; i <= n; i++)
        {
            if (isPrime(i))
            {
                cnt++;
                sum += i;
                // printf("%d\t", i);
                if (cnt % 5 == 0)
                {
                    printf("\n");
                }
            }
        }
        printf("\n");
        printf("%d %d\n", cnt, sum);
        cnt = 0, sum = 0;
        scanf("%d %d", &m, &n);
    }
}