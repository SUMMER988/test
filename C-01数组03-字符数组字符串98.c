#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

void revstr00(int *s, int len_s)
{
    int *p = s;
    int *r = s + len_s - 1;
    int c;
    while (p <= r)
    {
        c = *p;
        *p = *r;
        *r = c;
        p++;
        r--;
    }
}

void revstr01(int *arr, int len)
{
    int i;
    int j = len - 1;
    for (i = 0; i < len; i++)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void print(int *s, int len_s)
{
    int *p = s, *r = s + len_s - 1;
    while (p <= r)
    {
        printf("%d\t", *p);
        p++;
    }
    puts("");
}

int main(int argc, char const *argv[])
{
    int s[100];
    int len;
    int i;
    scanf("%d", &len);
    for (i = 0; i < len; i++)
    {
        scanf("%d", &s[i]);
        rewind(stdin);
    }

    puts("before reverse:");
    print(s, len);
    // revstr00(s, len);
    revstr01(s, len);
    puts("after reverse:");
    print(s, len);

    return 0;
}