#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("%*d\n", 6, 123);
    printf("%hhd\n", (char)12345);
    printf("%9.2f\n", 123.0); //整个输出占9个位置
    return 0;
}