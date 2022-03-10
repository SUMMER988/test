#include <stdio.h>
#include <string.h>

int main()
{
    char word[] = "Hello";
    char line[10] = "Hello";
    int i;
    printf("sizeof(word)=%d\n", sizeof(word));
    printf("sizeof(line)=%d\n", sizeof(line));
    for (i = 0; i < sizeof(word); i++)
    {
        printf("%c\t", word[i]);
    }

    return 0;
}