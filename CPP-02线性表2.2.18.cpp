#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;
//有两个带头结点的循环单链表, 链表头指针分别为h1和h2
//编写函数将链表h2链接到链表h1之后, 要求链接后的链表仍保持循环链表形式
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

//判断是否为空
bool IsEmpty(LinkList L)
{
    if (L->next == L)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//打印链表
void PrintList(LinkList L)
{
    if (IsEmpty(L))
    {
        cout << "NULL" << endl;
        return;
    }
    else
    {
        LNode *p = L->next;
        while (p != L)
        {
            cout << p->data << "\t";
            p = p->next;
        }
        cout << endl;
    }
}
//获取链表长度
int GetLength(LinkList L)
{
    int len = 0;
    LNode *p = L->next;
    while (p != L)
    {
        ++len;
        p = p->next;
    }
    cout << "该链表长度为" << len << endl;
    return len;
}
//初始化链表
bool InitList(LinkList &L)
{
    L = new LNode;
    if (!L)
    {
        return false;
    }
    L->next = L;
    return true;
}
//尾插法建表
LinkList CreateList(vector<int> data)
{
    LinkList L = new LNode;
    InitList(L);
    LNode *r = L;
    for (size_t i = 0; i < data.size(); i++)
    {
        LNode *p = new LNode;
        p->data = data[i];
        p->next = r->next;
        r->next = p;
        r = p;
    }
    return L;
}
//删除最小值结点
LinkList DeleteMin(LinkList &L)
{
    LNode *pre = L, *p = L->next;
    LNode *minpre = L, *minp = L->next;
    while (p != L)
    {
        if (p->data < minp->data)
        {
            minpre = pre;
            minp = p;
        }
        pre = p;
        p = p->next;
    }
    cout << "最小值为" << minp->data << endl;
    minpre->next = minp->next;
    free(minp);

    cout << "删除最小值结点后,链表为" << endl;
    PrintList(L);
    GetLength(L);
    return L;
}

//重排结点，使其递增有序
void SortList(LinkList &L)
{
    LNode *p = L->next;
    LNode *r = p->next; //暂存*p的后继结点
    LNode *s;
    p->next = L;
    p = r; //恢复*p的位置
    int time = 0;
    while (p != L)
    {
        r = p->next; //暂存*p的后继结点
        s = L;
        // cout << "次数" << ++time << endl;
        // PrintList(L);
        while (s->next != L && s->next->data < p->data)
        {
            s = s->next;
        }
        p->next = s->next;
        s->next = p;
        p = r; //恢复*p的位置
        // PrintList(L);
    }
    cout << "链表重排后为:" << endl;
    PrintList(L);
}
/*

//就地逆置
DLinkList ReverseList(DLinkList L)
{
    DNode *p, *r;
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
DLinkList ReverseList01(DLinkList L)
{
    DNode *pre, *p = L->next, *r = p->next;
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
//删除介于给定的两个值之间的结点
void RangeDelete(DLinkList &L, int min, int max)
{
    DNode *pre = L;
    DNode *p = L->next;
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
//查找两个单链表的公共结点
DLinkList SearchCommon(DLinkList L1, DLinkList L2)
{
    int len1 = GetLength(L1), len2 = GetLength(L2);
    int dis = 0;
    DLinkList longList, shortList;
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
void MinDelete(DLinkList &L)
{
    while (L->next)
    {
        DNode *minp = L;
        DNode *p = L->next;
        while (p->next)
        {
            if (p->next->data < minp->next->data)
            {
                minp = p;
            }
            p = p->next;
        }
        cout << minp->next->data << " ";
        DNode *del = minp->next;
        minp->next = del->next;
        free(del);
    }
    free(L);
}

//带头结点的单链表，将其分解为两个带头结点的单链表A和B
//使得A表中含有原表中序号为奇数的元素
//使得B表中含有原表中序号为偶数的元素
//且保持其相对顺序不变
DLinkList Discreate0(DLinkList &A)
{
    int i = 0;
    DLinkList B = new DNode;
    B->next = NULL;
    DNode *ra = A, *rb = B, *p;

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
DLinkList Discreate1(DLinkList &A)
{
    DLinkList B = new DNode;
    B->next = NULL;
    DNode *p = A->next, *q;
    DNode *ra = A;
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
void Del_Same(DLinkList &L)
{
    DNode *p = L->next, *q;
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
void MergeList(DLinkList &La, DLinkList &Lb)
{
    DNode *r, *pa = La->next, *pb = Lb->next;
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
DLinkList GetCommon(DLinkList A, DLinkList B)
{
    DNode *p = A->next, *q = B->next, *r, *s;
    DLinkList C = new DNode;
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
            s = new DNode;
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
DLinkList GetComonListToA(DLinkList &A, DLinkList &B)
{
    DNode *pa = A->next;
    DNode *pb = B->next;
    DNode *pc = A;
    DNode *u;
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
int Pattern(DLinkList A, DLinkList B)
{
    A = A->next;
    B = B->next;
    DNode *p = A;
    DNode *pre = p;
    DNode *q = B;
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
void IsSubsequence(DLinkList A, DLinkList B)
{
    if (Pattern(A, B))
    {
        cout << "B是A的子序列" << endl;
    }
    else
    {
        cout << "B不是A的子序列" << endl;
    }
}*/

//判断带头结点的单循环双链表是否对称
// bool Symmetry(LinkList L)
// {
//     LNode *p = L->next;
//     LNode *q = L->prior;
//     while (p != q && q->next != p)
//     {
//         if (p->data == q->data)
//         {
//             p = p->next;
//             q = q->next;
//         }
//         else
//         {
//             cout << "该链表不对称" << endl;
//             return false;
//         }
//     }
//     cout << "该链表对称" << endl;
//     return true;
// }

//编写函数将链表h2链接到链表h1之后, 要求链接后的链表仍保持循环链表形式
LinkList MergerList(LinkList &A, LinkList &B)
{
    LNode *pa = A->next;
    LNode *pb = B->next;
    while (pa->next != A)
    {
        pa = pa->next;
    }
    while (pb->next != B)
    {
        pb = pb->next;
    }
    pa->next = B->next;
    pb->next = A;
    return A;
}

//主函数
int main()
{
    vector<int> dataA{9, 7, 5, 3, 1};
    vector<int> dataB{2, 4, 6, 8};
    LinkList(A);
    InitList(A);
    A = CreateList(dataA);
    PrintList(A);
    LinkList(B);
    InitList(B);
    B = CreateList(dataB);
    PrintList(B);
    A = MergerList(A, B);
    cout << "the result is " << endl;
    PrintList(A);

    return 0;
}