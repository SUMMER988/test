#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;
//带头结点的单链表，删除所有值为x的节点
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
//删除指定结点
LinkList DeleteXNode(LinkList &L, int x)
{
    LNode *p = L->next;
    LNode *pre = L;
    LNode *q;
    while (p != NULL)
    {
        if (p->data == x)
        {
            q = p;
            p = p->next;
            pre->next = p;
            free(q);
        }
        else
        {
            pre = p;
            p = p->next;
        }
    }
    return L;
}
//主函数
int main()
{
    vector<int> data{0, 6, 6, 6, 6, 1, 2, 3, 4, 5};
    LinkList L;
    InitList(L);
    L = CreateList(data);
    PrintList(L);
    L = DeleteXNode(L, 6);
    PrintList(L);
    return 0;
}