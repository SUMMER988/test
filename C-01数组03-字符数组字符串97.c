#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define SIZE 100

int add01(int n, int result)
{
    printf("AAA n is %d\n", n);
    if (n < 1)
    {
        return result;
    }
    printf("BBB n is %d\n", n);
    return add01(n - 1, result + n);
}

int main(void)
{
    int num = 0, result = 0;
    scanf("%d", &num);
    printf("%d\n", add01(num, result));
    return 0;
}
