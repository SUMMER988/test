#include <stdio.h>
#include <stdlib.h>
// #include "14.2.1.h"
typedef struct _node
{
    int data;
    struct _node *next;
} Node;

int main(int argc, char const *argv[])
{
    Node *head = NULL;
    Node *last = head;
    int number;
    scanf("%d", &number);
    while (number != -1)
    {
        Node *p = (Node *)malloc(sizeof(Node));
        p->data = number;
        p->next = NULL;
        if (last)
        {
            while (last->next)
            {
                last = last->next;
            }
            last->next = p;
        }
        else
        {
            head = p;
        }
        scanf("%d", &number);
    }
    // Node *q = head;
    // while (q->data)
    // {
    //     printf("%d\n", q->data);
    //     q = q->next;
    // }
    // return 0;
}