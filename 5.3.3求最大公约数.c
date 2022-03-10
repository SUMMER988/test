#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    while (1)
    {
        scanf("%d", &a);
        int i, j, k;
        int cnt = 0;
        i = a;
        while (i <= a + 3)
        {
            j = a;
            while (j <= a + 3)
            {
                k = a;
                while (k <= a + 3)
                {
                    if (i != j && i != k && j != k)
                    {
                        cnt++;
                        printf("%d%d%d", i, j, k);
                        if (cnt % 6 == 0)
                        {
                            printf("\n");
                        }
                        else
                        {
                            printf(" ");
                        }
                    }
                    k++;
                }
                j++;
            }
            i++;
        }
    }
}