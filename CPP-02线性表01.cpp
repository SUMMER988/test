#include <bits/stdc++.h>
using namespace std;
#define MaxSize 50
//构造顺序表结构体
typedef struct sqList
{
    int data[MaxSize] = {0};
    int length;
} sqList;
//声明打印数组
void print(sqList L);

//重构顺序表
void recreatList(sqList &L)
{
    // int length = 6;
    int length;
    cin >> length;
    srand(time(0));
    for (int i = 0; i < length; i++)
    {
        L.data[i] = rand() % 100;
    }
    L.length = length;
}

//删除最小值元素
bool Del_Min(sqList &L, int &value)
{
    if (L.length == 0)
    {
        return false;
    }
    value = L.data[0];
    int pos = 0;
    for (int i = 1; i < L.length; i++)
    {
        if (L.data[i] < value)
        {
            value = L.data[i];
            pos = i;
        }
    }
    L.data[pos] = L.data[L.length - 1];
    L.length--;
    return true;
}

//冒泡排序
void sortList(sqList &L)
{
    int length = L.length;
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        bool flag = 0;
        for (int j = 0; j < length - 1 - i; j++)
        {
            if (L.data[j] > L.data[j + 1])
            {
                int temp = L.data[j];
                L.data[j] = L.data[j + 1];
                L.data[j + 1] = temp;
                flag = 1;
            }
        }
        //打印数组
        print(L);
        count++;
        if (flag == 0)
        {
            cout << "排序比较次数为:" << count << endl;
            return;
        }
    }
}

//打印数组
void print(sqList L)
{
    for (int i = 0; i < L.length; i++)
    {
        printf("%d\t", L.data[i]);
        if ((i + 1) % 5 == 0)
        {
            // puts("");
        }
    }
    puts("");
}

int main()
{
    sqList L;
    recreatList(L);
    print(L);
    int value = 0;
    Del_Min(L, value);
    print(L);
    sortList(L);
    return 0;
}