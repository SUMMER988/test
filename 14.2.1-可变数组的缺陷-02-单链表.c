#include <stdio.h>
#include <stdlib.h>
// #include "14.2.1.h"
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode;

int main(int argc, char const *argv[])
{
    LNode *head = (LNode *)malloc(sizeof(LNode));
    head->next = NULL;
    LNode *p = NULL, *r = head;
    int n;
    scanf("%d", &n);
    int i;
    for (i = 0; i < n; i++)
    {
        p = (LNode *)malloc(sizeof(LNode));
        p->next = NULL;
        scanf("%d", &(p->data));
        p->next = r->next;
        r->next = p;
        r = p;
    }
    LNode *q = head;
    while (q)
    {
        q = q->next;
        printf("%d\t", q->data);
    }
    // Node *q = head;
    // while (q->data)
    // {
    //     printf("%d\n", q->data);
    //     q = q->next;
    // }
    // return 0;
}