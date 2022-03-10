#include <iostream>
#include <ctime>
#include <bits/stdc++.h>
#define MaxSize 50

using namespace std;

typedef struct sqList
{
    int data[MaxSize];
    int length;
} sqList;

void print(sqList L)
{
    for (int i = 0; i < L.length; i++)
    {
        cout << L.data[i] << "\t";
    }
    cout << endl;
}

bool initList(sqList &L)
{
    int num;
    cout << "输入数组长度" << endl;
    cin >> num;
    L.length = num;
    cout << "初始化开始" << endl;
    for (int i = 0; i < L.length; i++)
    {
        cin >> L.data[i];
    }
    cout << "初始化完成" << endl;
    return true;
}

bool Merge(sqList A, sqList B, sqList &C)
{
    if (A.length + B.length > MaxSize)
    {
        return false;
    }
    int i = 0, j = 0, k = 0;
    while (i < A.length && j < B.length)
    {
        if (A.data[i] <= B.data[j])
        {
            C.data[k++] = A.data[i++];
        }
        else
        {
            C.data[k++] = B.data[j++];
        }
    }
    while (i < A.length)
    {
        C.data[k++] = A.data[i++];
    }

    while (j < B.length)
    {
        C.data[k++] = B.data[j++];
    }
    C.length = k;

    return true;
}

int main()
{
    sqList A;
    initList(A);
    sqList B;
    initList(B);
    sqList C;
    Merge(A, B, C);
    print(A);
    print(B);
    print(C);
    return 0;
}