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
    head = NULL;
    LNode *p = NULL, *r = head;
    int n;
    scanf("%d", &n);
    int i;
    // for (i = 0; i < n; i++)//
    while (1)
    {
        p = (LNode *)malloc(sizeof(LNode));
        p->next = NULL;
        scanf("%d", &(p->data));
        if (head = NULL)
        {
            head->data = p->data;
            printf("%d\n", head->data);
        }
        else
        {
            p->next = r->next;
            r->next = p;
            r = p;
        }
    }
    // LNode *q = head;
    // while (q)
    // {
    //     q = q->next;
    //     printf("%d\t", q->data);
    // }
}