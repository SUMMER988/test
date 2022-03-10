#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;
//带头结点的单链表，反向输出每个节点的值
typedef struct LNode
{
    int data;
    LNode *next;
} LNode, *LinkList;
//打印链表
void PrintList(LinkList L)
{
    L = L->next;
    while (L)
    {
        cout << L->data << " ";
        L = L->next;
    }
    cout << endl;
}
//初始化链表
bool InitList(LinkList &L)
{
    L = new LNode;
    if (!L)
    {
        return false;
    }

    L->next = NULL;
    return true;
}
//判断链表是否为空
bool IsEmpty(LinkList L)
{
    return (L->next == NULL);
}
//尾插法建表
LinkList CreateList(vector<int> data)
{
    if (data.size() < 1)
    {
        return NULL;
    }
    LinkList L = new LNode;
    LNode *r = L;
    for (int i = 0; i < data.size(); i++)
    {
        LNode *p = new LNode;
        p->data = data[i];
        r->next = p;
        r = p;
    }
    r->next = NULL;
    return L;
}
//反向输出链表
void ReversePrint(LinkList L)
{
    if (L->next != NULL)
    {
        ReversePrint(L->next);
    }
    if (L != NULL)
    {
        cout << L->data << " ";
    }
}
void ReversePrint_Ignore_Head(LinkList L)
{
    if (L != NULL)
    {
        ReversePrint(L->next);
    }
}
//主函数
int main()
{
    vector<int> data{5, 4, 3, 2, 1, 2, 4, 6, 8};
    LinkList L;
    InitList(L);
    L = CreateList(data);
    PrintList(L);
    ReversePrint_Ignore_Head(L);
    return 0;
}