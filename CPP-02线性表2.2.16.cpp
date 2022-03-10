#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;
//两个整数序列A = a1，a2，a3，…，an和B = b1, b2, b3, …, bn已经存入两个单链表中
//设计算法, 判断序列B是否是序列A的连续子序列
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
//获取单链表长度
int GetLength(LinkList L)
{
    int len = 0;
    L = L->next;
    while (L)
    {
        ++len;
        L = L->next;
    }
    return len;
}
//查找两个单链表的公共结点
LinkList SearchCommon(LinkList L1, LinkList L2)
{
    int len1 = GetLength(L1), len2 = GetLength(L2);
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

//设C={a1,b1,a2,b2,...,an,bn}为线性表，采用带头结点的hc单链表存放
//设计一个就地算法，将其拆分为两个线性表
//使得A={a1,a2,...,an},B={bn,...,b2,b1}
LinkList Discreate1(LinkList &A)
{
    LinkList B = new LNode;
    B->next = NULL;
    LNode *p = A->next, *q;
    LNode *ra = A;
    while (p)
    {
        ra->next = p;
        ra = p;
        p = p->next;
        if (p)
        {
            q = p->next;
            p->next = B->next;
            B->next = p;
            p = q;
        }
    }
    ra->next = NULL;
    cout << "A:" << endl;
    PrintList(A);
    cout << "B:" << endl;
    PrintList(B);
    return B;
}
//在一个递增有序的线性表中，有数值相同的元素存在。
//若存储方式为单链表,设计算法去掉数值相同的元素, 使表中不再有重复的元素。
//例如(7, 10, 10, 21, 30, 42, 42, 42, 51, 70)
//将变为(7, 10, 21, 30, 42, 51, 70)
void Del_Same(LinkList &L)
{
    LNode *p = L->next, *q;
    if (!p)
    {
        return;
    }
    while (p->next)
    {
        q = p->next;
        if (p->data == q->data)
        {
            p->next = q->next;
            free(q);
        }
        else
        {
            p = p->next;
        }
    }
    PrintList(L);
}

//假设有两个按元素值递增次序排列的线性表，均以单链表形式存储
//请编写算法将这两个单链表归并为一个按元素值递减次序排列的单链表
//并要求利用原来两个单链表的节点存放归并后的单链表
void MergeList(LinkList &La, LinkList &Lb)
{
    LNode *r, *pa = La->next, *pb = Lb->next;
    La->next = NULL;
    while (pa && pb)
    {
        if (pa->data < pb->data)
        {
            r = pa->next;
            pa->next = La->next;
            La->next = pa;
            pa = r;
        }
        else
        {
            r = pb->next;
            pb->next = La->next;
            La->next = pb;
            pb = r;
        }
    }
    if (pa)
    {
        pb = pa;
    }
    while (pb)
    {
        r = pb->next;
        pb->next = La->next;
        La->next = pb;
        pb = r;
    }
    free(Lb);
}

//设A和B是两个单链表(带头结点), 其中元素递增有序
//设计一个算法从A和B中的公共元素产生单链表C, 要求不破坏A、B的结点
LinkList GetCommon(LinkList A, LinkList B)
{
    LNode *p = A->next, *q = B->next, *r, *s;
    LinkList C = new LNode;
    r = C;
    while (p && q)
    {
        if (p->data < q->data)
        {
            p = p->next;
        }
        else if (p->data > q->data)
        {
            q = q->next;
        }
        else
        {
            s = new LNode;
            s->data = p->data;
            r->next = s;
            r = s;
            p = p->next;
            q = q->next;
        }
    }
    r->next = NULL;
    return C;
}

//已知两个链表A和B分别表示两个集合, 其元素递增排列
//编制函数, 求A与B的交集, 并存放于A链表中
LinkList GetComonListToA(LinkList &A, LinkList &B)
{
    LNode *pa = A->next;
    LNode *pb = B->next;
    LNode *pc = A;
    LNode *u;
    while (pa && pb)
    {
        if (pa->data == pb->data)
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
            u = pb;
            pb = pb->next;
            free(u);
        }
        else if (pa->data < pb->data)
        {
            u = pa;
            pa = pa->next;
            free(u);
        }
        else
        {
            u = pb;
            pb = pb->next;
            free(u);
        }
    }
    if (pa)
    {
        pb = pa;
    }
    while (pb)
    {
        u = pb;
        pb = pb->next;
        free(u);
    }
    pc->next = NULL;
    free(B);
    return A;
}

//两个整数序列A = a1，a2，a3，…，an和B = b1, b2, b3, …, bn已经存入两个单链表中
//设计算法, 判断序列B是否是序列A的连续子序列
int Pattern(LinkList A, LinkList B)
{
    A = A->next;
    B = B->next;
    LNode *p = A;
    LNode *pre = p;
    LNode *q = B;
    while (p && q)
    {
        if (p->data == q->data)
        {
            p = p->next;
            q = q->next;
        }
        else
        {
            pre = pre->next;
            p = pre;
            q = B;
        }
    }
    if (!q)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//判断序列B是否是序列A的连续子序列
void IsSubsequence(LinkList A, LinkList B)
{
    if (Pattern(A, B))
    {
        cout << "B是A的子序列" << endl;
    }
    else
    {
        cout << "B不是A的子序列" << endl;
    }
}
//主函数
int main()
{
    // int size;
    // cin >> size;
    // size = 5;
    vector<int> data0{1, 3, 5, 8, 11, 12};
    vector<int> data1{8, 11, 12, 13};

    LinkList A;
    LinkList B;
    InitList(A);
    InitList(B);
    A = CreateList(data0);
    B = CreateList(data1);
    PrintList(A);
    PrintList(B);
    IsSubsequence(A, B);

    return 0;
}