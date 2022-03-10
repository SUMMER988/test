#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("%d\n", ~-8);
    printf("%d\n", 5 & 4);
    printf("%d\n", 5 && 4);    //逻辑运算，只看到0或1
    printf("%d\n", 0 || 4);    //逻辑运算，只看到0或1
    printf("%d %d\n", !4, !5); //逻辑运算，只看到0或1
    printf("%d\n", 5 ^ 4);     // 00001001 , 00001000 , 00000001
    return 0;
}
// 00001001 & 00001000 , 00001000 , 4

/* 10001000,11111000,-8
    00000111,7  */