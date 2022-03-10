// #define _CRT_SECURE_NO_WARNINGS//忽略安全检测
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define Size 100
typedef struct SLNode
{
    int data;
    int next;
} SLNode;

void initSLNode(SLNode *L)
{
    int i;
    for (i = 0; i < Size - 1; i++)
    {
        L[i].next = i + 1;
    }
    L[Size - 1].next = 0;
}

int initSLNodeData(SLNode *L, int len)
{
    int i;
    puts("请输入静态链表中的数据:");
    for (i = 1; i <= len; i++)
    {
        scanf("%d", &L[i].data);
    }
    int length = len;
    return length;
}

void DataSearch(SLNode *L, int *Num, int len)
{
    puts("请输入将要查找的数据:");
    scanf("%d", Num);
    int i;
    for (i = 1; i <= len; i++)
    {
        if (L[i].data == *Num)
        {
            printf("查找到%d\n", *Num);
            return;
        }
    }
    puts("查找无果");
}

void print(SLNode *L, int n)
{
    int i;
    for (i = 1; i <= n; i++)
    {
        printf("%d->", L[i].data);
    }
    printf("\b\b  ");
    puts("");
}

int main(int argc, char const *argv[])
{
    SLNode L[100];
    initSLNode(L);
    int n;
    int length;
    puts("请输入:");
    scanf("%d", &n);
    length = initSLNodeData(L, n);
    print(L, length);
    int Num = 0;
    DataSearch(L, &Num, length);
    print(L, length);
    return 0;
}