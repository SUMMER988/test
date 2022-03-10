#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

//冒泡排序
void BubbleSort(int *arr, int len)
{
    int temp;
    int k = 5;
    int pos = 0; //用于记录每次排序后数字交换的最后位置
    for (int i = 0; i < 5; i++)
    {
        int flag = 0; //用于记录此次排序是否有发生数字交换
        for (int j = 0; j < k; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
                pos = j;
            }
        }
        k = pos; //记录数字交换的最后位置
        //打印冒泡排序后的数组
        printf("%d排序结果为:\n", i);
        {
            for (int k = 0; k < 6; k++)
            {
                printf("%d\t", arr[k]);
            }
            puts("");
        }
        // printf("%d\n", k); //打印数字交换的最后位置
        if (flag == 0) //若此次排序没有发生数字交换，数组有序，跳出循环
        {
            return;
        }
    }
}

//打印数组
void print(int *arr)
{
    for (int i = 0; i < 6; i++)
    {
        printf("%d\t", arr[i]);
    }
    puts("");
}

//生成随机数填入数组
void sarr(int *arr, int len)
{
    srand((size_t)time(NULL));
    for (int i = 0; i < len; i++)
    {
        arr[i] = rand() % 6 + 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] == arr[i])
            {
                arr[i] = rand() % 6 + 1;
                j = -1;
            }
        }
    }
}

//主函数
int main(int argc, char const *argv[])
{
    int flag = 0;

    //添加随机数种子
    // srand((size_t)time(NULL));
    // int Num;
    // scanf("%d", &Num);
    while (flag < 10)
    {
        int value = rand() % 16 + 16; //定义红球号数
        int blue[6];                  //定义蓝球数组
        sarr(blue, sizeof(blue) / sizeof(blue[0]));
        print(blue);
        BubbleSort(blue, sizeof(blue) / sizeof(blue[0]));
        print(blue);
        printf("%d\n", value);
        puts("");

        flag++;
    }
    // return 0;
}
