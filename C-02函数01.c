#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    //添加随机数种子
    srand((size_t)time(NULL));
    for (int m = 0; m < 10; m++)
    {
        int arr[6] = {0};
        int value = 0;
        for (int i = 0; i < 6; i++)
        {
            value = rand() % 6 + 1;
            for (int j = 0; j < i; j++)
            {
                if (value == arr[j])
                {
                    value = rand() % 6 + 1;
                    j = -1;
                }
            }
            arr[i] = value;
        }
        for (int k = 0; k < 6; k++)
        {
            printf("%d\t", arr[k]);
        }
        puts("");
    }
    return 0;
}