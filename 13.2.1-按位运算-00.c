#include <stdio.h>

int main(int argc, char const *argv[])
{
    unsigned char c = 0xAA; // 10101010
    printf("%d\n", 0x55);
    printf("~c=%d\n", ~c);
    printf("~c=%hhx\n", (char)~c); // 55
    printf("-c=%hhx\n", (char)-c);

    return 0;
}