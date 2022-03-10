#include <iostream>
#include <ctime>
// #include <bits/stdc++.h>
#define MaxSize 50
using namespace std;

//顺序表结构体
typedef struct sqList
{
    int data[MaxSize];
    int length;
} sqList;
//打印顺序表
void print(sqList L)
{
    for (int i = 0; i < L.length; i++)
    {
        cout << L.data[i] << " ";
    }
    cout << endl;
}
//逆置顺序表
void reverse(sqList &L)
{
    for (int i = 0; i < L.length / 2; i++)
    {
        int temp = L.data[i];
        L.data[i] = L.data[L.length - 1 - i];
        L.data[L.length - 1 - i] = temp;
    }
    cout << "逆置后的顺序表为" << endl;
    print(L);
}
//重构顺序表
void recreateList(sqList &L)
{
    srand((unsigned int)time(0));
    int length;
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        L.data[i] = rand() % 100;
    }
    L.length = length;
    cout << "重构后的顺序表为" << endl;
    print(L);
}

//冒泡排序
void bubbleSort(sqList &L)
{
    cout << "开始排序" << endl;
    int count = 0;
    int position = 0;
    int len = L.length - 1;
    for (int i = 0; i < L.length; i++)
    {
        bool flag = 0;
        int j;
        for (j = 0; j < len; j++)
        {
            if (L.data[j] > L.data[j + 1])
            {
                int temp = L.data[j];
                L.data[j] = L.data[j + 1];
                L.data[j + 1] = temp;
                position = j;
                flag = 1;
            }
        }
        len = position;
        count++;
        cout << "第" << count << "次排序最终交换位置为" << position << ",";
        cout << "排序结果为:\t";
        print(L);
        if (flag == 0)
        {
            cout << "排序比较次数为:" << count << endl;
            return;
        }
    }
}
//主函数
int main()
{
    sqList L;
    recreateList(L);
    reverse(L);
    bubbleSort(L);

    return 0;
}