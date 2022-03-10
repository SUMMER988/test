#include <iostream>
#include <ctime>
#include <bits/stdc++.h>
#define MaxSize 50

using namespace std;

void print(int A[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << A[i] << "\t";
    }
    cout << endl;
}
void SearchExchangeInsert(int *A, int *len, int x)
{
    int low, high, mid;
    low = 0, high = *len - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (A[mid] == x)
        {
            break;
        }
        else if (A[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (A[mid] == x && mid != *len - 1)
    {
        int temp = A[mid];
        A[mid] = A[mid + 1];
        A[mid + 1] = temp;
    }
    if (low > high)
    {
        int i = 0;
        for (i = *len - 1; i > high; i--)
        {
            A[i + 1] = A[i];
        }
        A[i + 1] = x;
        *len += 1;
    }
}

int main()
{
    int A[10] = {1, 2, 3, 4, 5, 6, 11, 13, 19};
    int num = 9;
    SearchExchangeInsert(A, &num, 11);
    print(A, num);

    return 0;
}