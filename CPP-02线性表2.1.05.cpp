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
        if ((i + 1) % 10 == 0)
        {
            cout << endl;
        }
    }
    cout << endl;
}

bool initList00(sqList &L)
{
    srand((unsigned int)time(0));
    int Num;
    cin >> Num;
    // Num = 10;
    if (Num > MaxSize)
    {
        return false;
    }

    L.length = Num;
    for (int i = 0; i < Num; i++)
    {
        L.data[i] = 10 + rand() % 90;
    }
    return true;
}

void initList(sqList &L)
{
    // srand((unsigned int)time(0));
    int Num;
    cin >> Num;
    L.length = Num;
    for (int i = 0; i < Num; i++)
    {
        cin >> L.data[i];
    }
}

bool Del_sqList(sqList &L, sqList &L_DEL, int s, int t)
{
    if (L.length == 0 || s >= t)
    {
        return false;
    }
    int k = 0;
    int j = 0;
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] >= s && L.data[i] <= t)
        {
            k++;
            L_DEL.data[j++] = L.data[i];
            continue;
        }
        L.data[i - k] = L.data[i];
    }
    if (k == 0)
    {
        return false;
    }
    L_DEL.length = j;
    L.length -= k;
    cout << "被删除元素为" << endl;
    print(L_DEL);
    cout << "修改后的线性表元素为" << endl;
    print(L);
    return true;
}

int main()
{
    sqList L;
    sqList L_DEL;
    if (!initList00(L))
    {
        cout << "错误" << endl;
        return 0;
    }
    print(L);
    if (!Del_sqList(L, L_DEL, 20, 50))
    {
        cout << "错误" << endl;
    }
    return 0;
}
