#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;
//带头结点的单链表，删除介于给定的两个值之间的结点
typedef struct LNode
{
    int data;
    LNode *next;
} LNode, *LinkList;
bool cmp(int x, int y)
{
    return x > y;
}
//打印单链表
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
//初始化单链表
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
//判断是否为空
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
    L->next = NULL;
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
    if (L)
    {
        cout << L->data << " ";
    }
}
//删除最小值结点
LinkList DeleteMin(LinkList &L)
{
    LNode *pre = L, *p = pre->next;
    LNode *minpre = pre, *minp = p;
    while (p)
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
LinkList ReverseList01(LinkList L)
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
//重排结点，使其递增有序
void SortList(LinkList &L)
{
    LNode *p = L->next, *pre;
    LNode *r = p->next;
    p->next = NULL;
    p = r;
    while (p)
    {
        r = p->next;
        pre = L;
        while (pre->next && pre->next->data < p->data)
        {
            pre = pre->next;
        }
        p->next = pre->next;
        pre->next = p;
        p = r;
    }
}
//删除介于给定的两个值之间的结点
void RangeDelete(LinkList &L, int min, int max)
{
    LNode *pre = L;
    LNode *p = L->next;
    while (p)
    {
        if (p->data > min && p->data < max)
        {
            pre->next = p->next;
            free(p);
            p = pre->next;
        }
        else
        {
            pre = p;
            p = p->next;
        }
    }
}
//主函数
int main()
{
    vector<int> data{3, 4, 6, 8, 1, 3, 9, 5};
    // sort(data.begin(), data.end(), cmp);
    LinkList L;
    InitList(L);
    L = CreateList(data);
    PrintList(L);
    SortList(L);
    PrintList(L);
    RangeDelete(L, 2, 5);
    PrintList(L);

    return 0;
}