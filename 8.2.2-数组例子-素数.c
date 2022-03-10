#include <stdio.h>
#define Maxnumber 10

int main()
{
    int isPrime[Maxnumber];
    int i;
    int x;
    for (i = 0; i < Maxnumber; i++)
    {
        isPrime[i] = 1;
    }
    // for test
    printf("\t");
    for (i = 2; i < Maxnumber; i++)
    {
        printf("%d\t", i);
    }
    printf("\n");
    // for test
    for (x = 2; x < Maxnumber; x++)
    {
        if (isPrime[x])
        {
            for (i = 2; i * x < Maxnumber; i++)
            {
                isPrime[i * x] = 0;
            }
        }
        // for test
        printf("%d\t", x);
        for (i = 2; i < Maxnumber; i++)
        {
            printf("%d\t", isPrime[i]);
        }
        printf("\n");
        // for test
    }
    for (i = 2; i < Maxnumber; i++)
    {
        if (isPrime[i])
        {
            printf("%d\t", i);
        }
    }
    printf("\n");
    return 0;
}