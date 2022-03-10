#include <stdio.h>
#include <stdlib.h>
// #include "14.2.1.h"
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode;

// int main(int argc, char const *argv[])
void createLinklistR(LNode L)
{
    LNode *head = (LNode *)malloc(sizeof(LNode));
    head->next = NULL;
    LNode *p = NULL, *r = head;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        p = (LNode *)malloc(sizeof(LNode));
        p->next = NULL;
        scanf("%d", &(p->data));
        p->next = r->next;
        r->next = p;
        r = p;
    }
    LNode *q = head->next;
    while (q)
    {
        printf("%d\t", q->data);
        q = q->next;
    }
    // Node *q = head;
    // while (q->data)
    // {
    //     printf("%d\n", q->data);
    //     q = q->next;
    // }
    // return 0;
}

int main(int argc, char const *argv[])
{
    LNode L;
    createLinklistR(L);
}