#include <stdio.h>

struct date
{
    int month;
    int day;
    int year;
} date;

int main(int argc, char const *argv[])
{
    struct date *p = &date;
    p->month = 12;
    printf("%d\n", p->month);
    // printf("%d\n", (*p).month);

    return 0;
}