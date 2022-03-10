#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;
//带头结点的单链表，将其分解为两个带头结点的单链表A和B
//使得A表中含有原表中序号为奇数的元素
//使得B表中含有原表中序号为偶数的元素
//且保持其相对顺序不变
typedef struct LNode
{
    int data;
    LNode *next;
} LNode, *LinkList;
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
//获取单链表长度
int Length(LinkList L)
{
    int len = 0;
    LNode *p = L->next;
    while (p)
    {
        ++len;
        p = p->next;
    }
    return len;
}
//查找两个单链表的公共结点
LinkList SearchCommon(LinkList L1, LinkList L2)
{
    int len1 = Length(L1), len2 = Length(L2);
    int dis = 0;
    LinkList longList, shortList;
    if (len1 > len2)
    {
        longList = L1->next;
        shortList = L2->next;
        dis = len1 - len2;
    }
    else
    {
        longList = L2->next;
        shortList = L1->next;
        dis = len2 - len1;
    }
    while (dis--)
    {
        longList = longList->next;
    }
    while (longList != NULL)
    {
        if (longList->data == shortList->data)
        {
            return longList;
        }
        else
        {
            longList = longList->next;
            shortList = shortList->next;
        }
    }
    return NULL;
}
//按递增次序输出单链表中各结点的数据元素
//并释放结点所占的存储空间
void MinDelete(LinkList &L)
{
    while (L->next)
    {
        LNode *minp = L;
        LNode *p = L->next;
        while (p->next)
        {
            if (p->next->data < minp->next->data)
            {
                minp = p;
            }
            p = p->next;
        }
        cout << minp->next->data << " ";
        LNode *del = minp->next;
        minp->next = del->next;
        free(del);
    }
    free(L);
}

//带头结点的单链表，将其分解为两个带头结点的单链表A和B
//使得A表中含有原表中序号为奇数的元素
//使得B表中含有原表中序号为偶数的元素
//且保持其相对顺序不变
LinkList Discreate0(LinkList &A)
{
    int i = 0;
    LinkList B = new LNode;
    B->next = NULL;
    LNode *ra = A, *rb = B, *p;

    p = A->next;
    A->next = NULL;
    while (p)
    {
        ++i;
        if (i % 2 == 0)
        {
            rb->next = p;
            rb = p;
        }
        else
        {
            ra->next = p;
            ra = p;
        }
        p = p->next;
    }
    ra->next = NULL;
    rb->next = NULL;
    cout << "A:" << endl;
    PrintList(A);
    cout << "B:" << endl;
    PrintList(B);
    return B;
}
//主函数
int main()
{
    vector<int> data{3, 4, 6, 8, 1, 3, 9, 5};
    LinkList L;
    InitList(L);
    L = CreateList(data);
    PrintList(L);
    Discreate0(L);
    return 0;
}