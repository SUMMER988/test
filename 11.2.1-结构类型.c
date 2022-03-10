#include <stdio.h>

struct date
{
    int month;
    int day;
    int year;
} date;

int main(int argc, char const *argv[])
{
    struct date today = {01, 01, 2022};
    struct date nextmonth = {.month = 01, .year = 2022};
    printf("Today's date is %i-%i-%i.\n",
           today.year, today.month, today.day);
    printf("Nextmonth is %i-%i-%i.\n",
           nextmonth.year, nextmonth.month, nextmonth.day);
    return 0;
}