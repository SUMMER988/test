#include <stdio.h>
#define number 10
int main()
{

    int x;
    int count[number] = {0};
    int i;

    // for (i = 0; i < number; i++)
    // {
    //     count[i] = 0;
    // }
    scanf("%d", &x);
    while (x != -1)
    {
        if (x >= 0 && x <= 9)
        {
            count[x]++;
        }
        // rewind(stdin);
        scanf("%d", &x);
    }
    for (i = 0; i < number; i++)
    {
        printf("%d:%d\n", i, count[i]);
    }
}