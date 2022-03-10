#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
//打印数组
void print(int *arr, int length)
{
    int i = 0;
    int *p = arr;
    while (i < length)
    {
        printf("%d\t", *p);
        p++;
        i++;
    }
    puts("");
}
//冒泡排序优化
int *swap(int *arr, int length)
{

    int *p = arr;
    int *r = arr + length - 1;
    int count = 0;
    int flag = 1;
    for (int i = 0; i < length - 1 && flag == 1; i++)
    {
        p = arr;
        flag = 0;
        int temp;
        while (p < r)
        {
            if (*p > *(p + 1))
            {
                temp = *p;
                *p = *(p + 1);
                *(p + 1) = temp;
                flag = 1;
            }
            p++;
        }
        r--;
        count++;
        // print(arr, length);
    }
    printf("The count in %s is %d\n", __func__, count);
    return arr;
}

int main(int argc, char const *argv[])
{
    srand(time(0));
    int a[10] = {0};
    const int len = sizeof(a) / sizeof(*a);
    for (int k = 0; k < 5; k++)
    {
        for (int i = 0; i < len; i++)
        {
            a[i] = 10 + rand() % 90;
            printf("a[%d]=%d\t", i, a[i]);
        }
        puts("");
        print(a, len);
        // for (int i = 0; i < len; i++)
        // {
        //     a[i] = i;
        // }
        int *p = swap(a, len);
        print(a, len);
        puts("");
    }

    return 0;
}