#include <stdio.h>

int main()
{
    char c;
    while (1)
    {
        scanf("%c", &c);
        printf("%d\n", 'A' - 'a');
        printf("c='%c'\n", c);
        c = c + 'a' - 'A';
        printf("c='%c'\n", c);
        rewind(stdin);
    }
}