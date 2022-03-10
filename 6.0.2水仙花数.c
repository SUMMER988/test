#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int i, j;
    scanf("%d", &n);
    while (1)
    {
        i = 1;
        while (i <= n)
        {
            j = 1;
            while (j <= i)
            {
                printf("%d*%d=%d", j, i, i * j);
                if (i * j < 10)
                {
                    printf("   ");
                }
                else
                {
                    printf("  ");
                }
                j++;
            }
            printf("\n");
            i++;
        }
        // rewind(stdin);
        i = 1, j = 1;
        scanf("%d", &n);
    }
}