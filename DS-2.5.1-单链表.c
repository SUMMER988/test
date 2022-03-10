#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char num[8];
    char name[8];
    int score;
} ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
    struct LNode *prior;
    struct LNode *tail;
} LNode, *LinkList;
