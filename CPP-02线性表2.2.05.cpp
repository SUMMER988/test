#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;
//带头结点的单链表，就地逆置
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
        cout << L->data << "->";
        L = L->next;
    }
    cout << "NULL" << endl;
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
//删除最小值结点
LinkList Delete_Min(LinkList &L)
{
    LNode *pre = L, *p = pre->next;
    LNode *minpre = pre, *minp = p;
    while (p != NULL)
    {
        if (p->data < minp->data)
        {
            minp = p;
            minpre = pre;
        }
        pre = p;
        p = p->next;
    }
    minpre->next = minp->next;
    free(minp);
    return L;
}
//就地逆置
LinkList ReverseList(LinkList L)
{
    LNode *p, *r;
    p = L->next;
    L->next = NULL;
    while (p)
    {
        r = p->next;
        p->next = L->next;
        L->next = p;
        p = r;
    }

    return L;
}
//就地逆置解法二
LinkList ReverseList1(LinkList L)
{
    LNode *pre, *p = L->next, *r = p->next;
    p->next = NULL;
    while (r)
    {
        pre = p;
        p = r;
        r = r->next;
        p->next = pre;
    }
    L->next = p;
    return L;
}
//主函数
int main()
{
    vector<int> data{5, 4, 3, 2, 1, 3, 5, 7, 9};
    // sort(data.begin(), data.end());
    LinkList L;
    InitList(L);
    L = CreateList(data);
    PrintList(L);
    ReverseList(L);
    PrintList(L);
    ReverseList1(L);
    PrintList(L);
    return 0;
}