#include <stdio.h>
#include <stdlib.h>

void print(int *x, int len)
{
    int i = 0;
    for (int i = 0; i < len; i++)
    {
        printf("%d\t", x[i]);
    }
    printf("\n");
}
int main(int argc, char const *argv[])
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i = 0;
    int An = sizeof(a) / sizeof(a[0]);
    printf("The address is %p\n", a);
    printf("The address is %p\n", &a[0]);
    print(a, An);
    int b[9];
    for (int i = 0; i < An; i++)
    {
        b[i] = a[i];
        // printf("%d\n", b[i]);
        printf("%d\n", *(b + i));
    }
    print(b, An);

    return 0;
}