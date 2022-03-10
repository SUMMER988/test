#include <stdio.h>

#define cube(x) ((x) * (x) * (x))

int main(int argc, char const *argv[])
{
    int i;
    while (1)
    {
        scanf("%d", &i);
        printf("%d\n", cube(i));
        rewind(stdin);
    }
}