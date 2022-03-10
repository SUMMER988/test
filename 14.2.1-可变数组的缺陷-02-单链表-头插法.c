#include <stdio.h>
#include <stdlib.h>
// #include "14.2.1.h"
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode;

// int main(int argc, char const *argv[])
void createLinklistH(LNode L)
{
    LNode *head = (LNode *)malloc(sizeof(LNode));
    head->next = NULL;
    LNode *p = NULL;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        p = (LNode *)malloc(sizeof(LNode));
        p->next = NULL;
        scanf("%d", &(p->data));
        p->next = head->next;
        head->next = p;
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
    createLinklistH(L);
}