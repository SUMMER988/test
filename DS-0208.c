#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxSize 100

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode;

LNode *initList()
{
    LNode *L = (LNode *)malloc(sizeof(LNode));
    // L->data = 0;
    L->next = NULL;
    return L;
}

void headInsert(LNode *L, int data)
{
    LNode *p = (LNode *)malloc(sizeof(LNode));
    p->data = data;
    p->next = L->next;
    L->next = p;
    // L->data++;
}

void tailInsert(LNode *L, int data)
{
    LNode *p = (LNode *)malloc(sizeof(LNode));
    LNode *r = L;
    p->data = data;
    while (r->next)
    {
        r = r->next;
    }
    r->next = p;
    p->next = NULL;

    // L->data++;
}
int length(LNode *L)
{
    if (L == NULL)
    {
        return 0;
    }
    else
    {
        int length = 0;
        LNode *p = L;
        while (p->next)
        {
            p = p->next;
            length++;
        }
        return length;
    }
}

int DEL(LNode *L, int data)
{
    LNode *p = L;
    LNode *q = p->next;
    while (q)
    {
        if (q->data == data)
        {
            p->next = q->next;
            free(q);
            return 1;
        }
        p = q;
        q = q->next;
    }
    return 0;
}
void print(LNode *L)
{
    LNode *node = L->next;
    while (node)
    {
        printf("%d\t", node->data);
        node = node->next;
    }
    puts("");
}
int main(int argc, char const *argv[])
{
    LNode *head = initList();
    tailInsert(head, 1);
    tailInsert(head, 2);
    tailInsert(head, 3);
    tailInsert(head, 4);
    tailInsert(head, 5);
    // print(L);

    // if (delete (L, 3))
    // {
    //     puts("success!");
    //     print(L);
    // }
    // else
    // {
    //     puts("fail!");
    // }
    int len = length(head);
    print(head);
    return 0;
}
