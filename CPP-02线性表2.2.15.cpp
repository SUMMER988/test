#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;
//已知两个链表A和B分别表示两个集合, 其元素递增排列
//编制函数, 求A与B的交集, 并存放于A链表中
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
//获取链表长度
int GetLength(LinkList L)
{
    int len = 0;
    L = L->next; //带头结点
    while (L)
    {
        ++len;
        L = L->next;
    }
    return len;
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
//主函数
int main()
{
    // int size;
    // cin >> size;
    // size = 5;
    vector<int> data0{1, 3, 5, 8, 11, 12};
    vector<int> data1{2, 3, 5, 8, 10, 12};

    LinkList A;
    LinkList B;
    InitList(A);
    InitList(B);
    A = CreateList(data0);
    B = CreateList(data1);
    PrintList(A);
    PrintList(B);
    GetComonListToA(A, B);
    PrintList(A);
    cout << "The length of A is " << GetLength(A) << endl;
    // cin.get();

    return 0;
}