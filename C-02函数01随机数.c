#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
void Sarr(int *arr, int len)
{
    int value = 0;
    for (int i = 0; i < len; i++)
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
    for (int k = 0; k < len; k++)
    {
        printf("%d\t", arr[k]);
    }
    puts("");
}
int main(int argc, char const *argv[])
{
    //添加随机数种子
    srand((size_t)time(NULL));
    int arr[6] = {0};
    Sarr(arr, sizeof(arr) / sizeof(arr[0]));

    return 0;
}