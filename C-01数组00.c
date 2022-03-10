#include <stdio.h>
#define SIZE 10
void reverseList(int a[], int len)
{
    int *p = a;
    int *q = &a[SIZE - 1];
    while (p != q && (p + 1) != q)
    {
        int i = *p;
        *p = *q;
        *q = i;
        p++;
        q--;
    }
    int i = *p;
    *p = *q;
    *q = i;
    for (int j = 0; j < SIZE; j++)
    {
        printf("%d\t", a[j]);
    }
    printf("\n");
}

int *find(int a[], int len, int num)
{
    int *p = a;
    for (int i = 0; i < len; i++)
    {
        if (*p == num)
        {
            printf("%d位置找到了", i);
            break;
        }
        p++;
    }
    return p;
}

int main(int argc, char const *argv[])
{
    int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    reverseList(arr, SIZE);
    reverseList(arr, SIZE);
    int *p = find(arr, SIZE, 8);
    printf("%d\n", *p);
    return 0;
}