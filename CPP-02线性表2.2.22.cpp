#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstring>
const int MaxSize = 100;
using namespace std;
// 2.2.22
//假定采用带头结点的单链表保存单词，当两个单词有相同的后缀时,
//可共享相同的后缀存储空间，例如，“loading”和 “being”的存储映像如下图所示。
//设str1和str2分别指向两个单词所在单链表的头结点, 链表结点结构为data,next,
//请设计一个时间上尽可能高效的算法,
//找出由Str1和str2所指向两个链表共同后缀的起始位置(如图中字符i所在结点的位置p)。
// 要求:
// 1)给出算法的基本设计思想
// 2)根据设计思想, 采用C或C++或Java语言描述算法, 关键之处给出注释
// 3)说明你所设计算法的时间复杂度
typedef char ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;
int GetLength(LinkList L);
//判断是否为空
bool IsEmpty(LinkList L)
{
    return (L->next == NULL ? true : false);
}
//打印链表
void PrintList(LinkList L)
{
    if (IsEmpty(L))
    {
        cout << "NULLL" << endl;
        return;
    }
    LNode *p = L->next;
    while (p)
    {
        cout << p->data << "\t";
        p = p->next;
    }
    cout << endl;
    // cout << GetLength(L) << endl;
}
//获取链表长度
int GetLength(LinkList L)
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

//创建单链表
LinkList CreateList0(LinkList &L, string s)
{
    // cin >> s;
    // s = "KING";
    // char data[MaxSize];
    // strncpy(data, s.c_str(), (int)s.length() + 1);

    LNode *r = L;
    int slen = s.length();
    for (size_t i = 0; i < slen; i++)
    {
        LNode *p = new LNode;
        p->data = s[i];
        p->next = r->next;
        r->next = p;
        r = p;
    }
    return L;

    // for (size_t i = 0; i < s.length(); i++)
    // {
    //     cout << data[i] << "\t";
    // }
    // cout << endl;
}

//尾插法建表
// LinkList CreateList(vector<char> data)
//{
//    if (data.size() < 1)
//    {
//        return NULL;
//    }
//
//    LinkList L = new LNode;
//    L->next = NULL;
//    LNode *r = L;
//    for (size_t i = 0; i < data.size(); i++)
//    {
//        LNode *p = new LNode;
//        p->data = data[i];
//        p->next = NULL;
//        r->next = p;
//        r = p;
//    }
//    return L;
//}
//删除最小值结点
LinkList DeleteMin(LinkList &L)
{

    if (IsEmpty(L))
    {
        return NULL;
    }
    LNode *pre = L, *p = L->next;
    LNode *minpre = pre, *minp = p;
    while (p)
    {
        if (p->data < minp->data)
        {
            minpre = pre;
            minp = p;
        }
        pre = p;
        p = p->next;
    }
    if (minp)
    {
        minpre->next = minp->next;
    }
    delete (minp);
    PrintList(L);
    return L;
}

//重排结点，使其递增有序
void SortList(LinkList &L)
{
    LNode *p = L->next;
    LNode *r = p->next;
    LNode *s;
    p->next = NULL;
    p = r;
    while (p)
    {
        r = p->next;
        s = L;
        while (s->next && s->next->data < p->data)
        {
            s = s->next;
        }
        p->next = s->next;
        s->next = p;
        p = r;
    }
}
/*

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

//判断带头结点的单循环双链表是否对称
bool Symmetry(LinkList L)
{
    LNode *p = L->next;
    LNode *q = L->prior;
    while (p != q && q->next != p)
    {
        if (p->data == q->data)
        {
            p = p->next;
            q = q->next;
        }
        else
        {
            cout << "该链表不对称" << endl;
            return false;
        }
    }
    cout << "该链表对称" << endl;
    return true;
}

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

//设有一个带头结点的循环单链表，其结点值均为正整数。
//设计算法，反复找出单链表中结点值最小的结点并输出。
//然后将该结点从中删除, 直到单链表空为止，再删除表头结点。
void DeleteAll(LinkList &L)
{
    LNode *p, *pre, *minp, *minpre;
    while (L->next != L)
    {
        p = L->next;
        pre = L;
        minp = p;
        minpre = pre;
        while (p != L)
        {
            if (p->data < minp->data)
            {
                minp = p;
                minpre = pre;
            }
            pre = p;
            p = p->next;
        }
        cout << minp->data << "\t";
        minpre->next = minp->next;
        free(minp);
    }
    cout << endl;
    free(L);
}

// 2.2.20
//设头指针为L的带有表头结点的非循环双向链表,
//其每个结点中除有pred(前驱指针)、data(数据)和next(后继指针)域外,
//还有一个访问频度域freq。在链表被启用前, 其值均初始化为零。
//每当在链表中进行一次 Locate(L, x)运算时令元素值为ⅹ的结点中freq域的值增1,
//并使此链表中结点保持按访问频度非增(递减)的顺序排列,
//同时最近访问的结点排在频度相同的结点前面, 以便使频繁访问的结点总是靠近表头。
//试编写符合上述要求的 Locate(L, x)运算的算法,
//该运算为函数过程, 返回找到结点的地址, 类型为指针型
LinkList Locate(LinkList &L, ElemType x)
{
    LNode *p = L->next;
    LNode *q = L;
    while (p && p->data != x)
    {
        p = p->next;
    }
    if (!p)
    {
        cout << "not exist" << endl;
        exit(0);
    }
    else
    {
        (p->freq)++;
        if (p->next != NULL)
        {
            p->next->pred = p->pred;
        }
        p->pred->next = p->next;
        q = p->pred;
        while (q != L && q->freq <= p->freq)
        {
            q = q->pred;
        }
        p->next = q->next;
        q->next->pred = p;
        p->pred = q;
        q->next = p;
    }

    PrintList(L);
    return p;
}

//已知一个带有表头结点的单链表，结点结构为
//			data	next
//假设该链表只给出了头指针1ist。在不改变链表的前提下,
//请设计一个尽可能高效的算法, 查找链表中倒数第k个位置上的结点(k为正整数)。
//若查找成功, 算法输出该结点的data域的值, 并返回1; 否则, 只返回0。
// 1)描述算法的基本设计思想
// 2)描述算法的详细实现步骤
// 3)根据设计思想和实现步骤, 采用程序设计语言描述算法,关键之处请给出简要注释
int Search_K(LinkList L, int k)
{
    int len = GetLength(L);
    int pos = len - k;
    int count = 0;
    LNode *p = L->next;
    for (; p && count != pos; p = p->next, count++)
        ;
    if (p)
    {
        cout << p->data << endl;
        return 1;
    }
    else
    {
        cout << "not exist" << endl;
        return 0;
    }
}*/

//找出由Str1和str2所指向两个链表共同后缀的起始位置
LinkList SameList(LinkList A, LinkList B)
{
    int lenA = GetLength(A), lenB = GetLength(B), Diss = abs(lenA - lenB);
    LinkList longlist, shortlist;
    longlist = lenA > lenB ? A->next : B->next;
    shortlist = lenA < lenB ? A->next : B->next;
    while (Diss--)
    {
        longlist = longlist->next;
    }
    while (longlist)
    {
        if (longlist->data == shortlist->data)
        {
            cout << "Success" << endl;
            return longlist;
        }
        longlist = longlist->next;
        shortlist = shortlist->next;
    }
    cout << "Fail" << endl;
    return NULL;
}

//主函数
int main()
{
    LinkList(A);
    InitList(A);
    string Astr("KING");
    A = CreateList0(A, Astr);
    PrintList(A);
    LinkList(B);
    InitList(B);
    string Bstr("123KING");
    B = CreateList0(B, Bstr);
    PrintList(B);
    LinkList(C);
    InitList(C);
    C->next = SameList(A, B);
    PrintList(C);
    DeleteMin(C);
    LinkList(D);
    InitList(D);
    string Dstr("654321789");
    // string Dstr;
    // cin >> Dstr;
    D = CreateList0(D, Dstr);
    PrintList(D);
    SortList(D);
    PrintList(D);
    DeleteMin(D);
    cout << "The length of D is " << GetLength(D) << endl;

    return 0;
}