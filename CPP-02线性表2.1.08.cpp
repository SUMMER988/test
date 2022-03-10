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

void InitList(sqList &L)
{
    srand((unsigned int)time(0));
    int num;
    // cin >> num;
    num = 12;
    L.length = num;
    for (int i = 0; i < L.length; i++)
    {
        L.data[i] = rand() % 50 + 50;
    }
}

void Reverse(sqList &L, int left, int right)
{
    if (left >= right || right >= MaxSize)
    {
        return;
    }
    int mid = (left + right) / 2;
    for (int i = 0; i < mid - left; i++)
    {
        int temp = L.data[left + i];
        L.data[left + i] = L.data[right - i];
        L.data[right - i] = temp;
    }
}

void Exchange(sqList &L, int m, int n)
{
    Reverse(L, 0, m + n - 1);
    Reverse(L, 0, n - 1);
    Reverse(L, n, m + n - 1);
}

int main()
{
    sqList L;
    InitList(L);
    print(L);
    Exchange(L, 3, 9);
    print(L);

    return 0;
}