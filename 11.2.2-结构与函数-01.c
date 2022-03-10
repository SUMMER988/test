#include <stdio.h>

struct point
{
    int x;
    int y;
} point;

struct point *getStruct(struct point *);
void ouput(struct point p);
void print(const struct point *p);
struct point *getStruct(struct point *p)
{
    scanf("%d", &p->x);
    scanf("%d", &p->y);
    printf("%d,%d\n", p->x, p->y);
    return p;
}

void output(struct point p)
{
    printf("%d,%d\n", p.x, p.y);
}

void print(const struct point *p)
{
    printf("%d,%d\n", p->x, p->y);
}

int main(int argc, char const *argv[])
{
    struct point y = {0, 0};
    getStruct(&y);
    output(y);
    output(*getStruct(&y));
    print(getStruct(&y));
    *getStruct(&y) = (struct point){1, 2};

    return 0;
}
