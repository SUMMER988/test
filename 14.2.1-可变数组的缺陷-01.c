#include <stdio.h>
#include <stdlib.h>
// #include "14.2.1.h"
typedef struct Lnode
{
    int data;
    struct Lnode *next;
} Lnode;

int main(int argc, char const *argv[])
{
    Lnode *head = (Lnode *)malloc(sizeof(Lnode));
    head->next = NULL;
    Lnode *p = NULL, *r = head;
    int n;
    scanf("%d", &n);
    int i;
    for (i = 0; i < n; i++)
    {
        p = (Lnode *)malloc(sizeof(Lnode));
        p->next = NULL;
        scanf("%d", &(p->data));
        p->next = r->next;
        r->next = p;
        r = p;
    }
    Lnode *q = head;
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