#include <stdio.h>
#include <stdlib.h>
typedef struct LNODE
{
    char ch;
    struct LNODE *next;
} LNODE;
void createLinkNosameElem(LNODE *head)
{
    head = (LNODE *)malloc(sizeof(LNODE));
    head->next = NULL;
    LNODE *p;
    int n;
    char ch[10];
    // char *q = ch;
    // while (*q != '\0')
    // {
    //     printf("%c\n", *q);
    //     q++;
    // }
    scanf("%d", &n);
    // getchar();
    for (int i = 0; i < n; i++)
    {
        scanf("%c", &ch[i]);
        getchar();
        p = head->next;
        while (p != NULL)
        {
            if (p->ch == ch[i])
            {
                break;
                p = p->next;
            }
        }
        if (p == NULL)
        {
            p = (LNODE *)malloc(sizeof(LNODE));
            p->ch = ch[i];
            p->next = head->next;
            head->next = p;
        }
        printf("for test 01");
        printf("%c\n", p->ch);
    }
}

int main(int argc, char const *argv[])
{
    LNODE *L;
    createLinkNosameElem(L);
    printf("%c\n", L->next->ch);
    LNODE *q = L;
    while (q != NULL)
    {
        printf("%c\t", q->ch);
        q = q->next;
    }

    return 0;
}