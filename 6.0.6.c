#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    double dividend, divisor;
    double sum = 0.0;
    int i;
    double t;
    while (1)
    {
        sum = 0;
        scanf("%d", &n);
        dividend = 2;
        divisor = 1;
        for (i = 1; i <= n; i++)
        {
            sum += dividend / divisor;
            t = dividend;
            dividend = dividend + divisor;
            divisor = t;
        }
        printf("%.2f %.2f\n", dividend, divisor);
        printf("%.2f\n", sum);
    }
}