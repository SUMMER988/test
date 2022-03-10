//循环左移
#include <iostream>
#include <ctime>
//#include <bits/stdc++.h>
#define MaxSize 50

using namespace std;

void print(int R[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << R[i] << " ";
    }
    cout << endl;
}
void Reverse(int R[], int from, int to)
{
    int i = 0, temp = 0;
    for (i = 0; i < (to - from + 1) / 2; i++)
    {
        temp = R[from + i];
        R[from + i] = R[to - i];
        R[to - i] = temp;
    }
}

void Converse(int R[], int n, int p)
{
    cout << "前部分元素逆置" << endl;
    Reverse(R, 0, p - 1);
    print(R, n);
    cout << "后部分元素逆置" << endl;
    Reverse(R, p, n - 1);
    print(R, n);
    cout << "整体逆置" << endl;
    Reverse(R, 0, n - 1);
    print(R, n);
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length = sizeof(a) / sizeof(*a);
    cout << "逆置前的数组为" << endl;
    print(a, length);
    Converse(a, length, 3);
    // print(a, length);
    return 0;
}