#include <iostream>
#include <ctime>
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
    srand((unsigned int)time(0));
    int num;
    cin >> num;
    L.length = num;
    if (L.length > MaxSize)
    {
        return false;
    }
    for (int i = 0; i < L.length; i++)
    {
        L.data[i] = rand() % 10;
    }

    print(L);
    return true;
}

bool Delete_Same(sqList &L)
{
    if (L.length == 0)
    {
        return false;
    }
    int i, j;
    for (i = 0, j = 1; j < L.length; j++)
    {
        if (L.data[i] != L.data[j])
        {
            L.data[++i] = L.data[j];
        }
    }
    L.length = i + 1;
    return true;
}

int main()
{
    sqList L;
    initList(L);
    if (!Delete_Same(L))
    {
        cout << "不存在重复元素" << endl;
    }
    print(L);
    return 0;
}