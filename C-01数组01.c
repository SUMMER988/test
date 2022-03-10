#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void Bubblesort00(int *arr, size_t size);
void Bubblesort01(int *arr, size_t size);

int main(int argc, char const *argv[])
{
    int arr[10] = {0};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    // Bubblesort00(arr, size);
    Bubblesort01(arr, size);

    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    return 0;
}

void Bubblesort00(int *arr, size_t size) //冒泡排序
{
    int i = 0, j = 0;
    for (i = 0; i < size - 1; i++)
    {
        int flag = 0;
        for (j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            return;
        }
    }
}

void Bubblesort01(int *arr, size_t size) //冒泡排序
{
    int i = 0, j = 0;
    int k = size - 1, pos = 0;

    for (i = 0; i < size - 1; i++)
    {
        int flag = 0;
        for (j = 0; j < k; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
                pos = j;
            }
        }
        if (flag == 0)
        {
            return;
        }
    }
}