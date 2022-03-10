#include <stdio.h>

int main()
{
    int a;
    a = 6;
    printf("sizeof(int)=%ld\n", sizeof(int));
    printf("sizeof(double)=%ld\n", sizeof(double));
    printf("sizeof(long double)=%ld\n", sizeof(long double));
    printf("sizeof(a)=%ld\n", sizeof(a));
    printf("sizeof(a++)=%ld\n", sizeof(a++));
    printf("sizeof(a+1)=%ld\n", sizeof(a + 1));
    printf("sizeof(a+1.0)=%ld\n", sizeof(a + 1.0));
    printf("%d\n", a);
    return 0;
}