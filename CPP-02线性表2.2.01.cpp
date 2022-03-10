#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;
typedef struct LNode
{
    int data;
    LNode *next;
} LNode, *LinkList;
//递归算法，删除不带头结点的单链表中所有值为x的结点
//打印链表
void PrintList(LinkList L)
{
    while (L)
    {
        cout << L->data << " ";
        L = L->next;
    }
    cout << endl;
}
//获取链表长度
int GetLength(LinkList L)
{
    LNode *p = L;
    int length = 0;
    while (p)
    {
        ++length;
        p = p->next;
    }
    return length;
}
//初始化链表
void InitList(LinkList &L)
{
    L = new LNode;
    L->next = NULL;
}
//判断链表是否为空
bool IsEmpty(LinkList L)
{
    return (L == NULL);
}
//尾插法建表
LinkList CreateList(vector<int> data)
{
    if (data.size() < 1)
    {
        return NULL;
    }
    LinkList L = new LNode;
    L->next = NULL;
    L->data = data[0];
    LNode *p = L;
    for (int i = 1; i < data.size(); i++)
    {
        LNode *s = new LNode;
        s->data = data[i];
        s->next = NULL;
        p->next = s;
        p = s;
    }
    return L;
}
//删除指定元素
void DeleteXNode(LinkList &L, int x)
{
    LNode *p;
    if (L == NULL)
    {
        return;
    }
    if (L->data == x)
    {
        p = L;
        L = L->next;
        delete p;
        DeleteXNode(L, x);
    }
    else
    {
        DeleteXNode(L->next, x);
    }
}
//尾插法添加元素
void AddList(LinkList &L, int num)
{
    LNode *p = L;
    LNode *r = NULL;
    while (p)
    {
        r = p;
        p = p->next;
    }
    LNode *s = new LNode;
    s->data = num;
    s->next = NULL;
    r->next = s;
}
//主函数
int main()
{
    // vector<int> data{1, 2, 3, 4, 5, 6, 6, 6, 6, 6, 6};
    vector<int> data;
    int size;
    // cin >> size;
    size = 8;
    srand((unsigned int)time(0));
    for (int i = 0; i < size; i++)
    {
        data.push_back(rand() % 10);
    }
    sort(data.begin(), data.end());

    LinkList L;
    InitList(L);
    L = CreateList(data);
    PrintList(L);
    DeleteXNode(L, 3);
    PrintList(L);
    AddList(L, 14);
    PrintList(L);
    cout << GetLength(L);

    return 0;
}