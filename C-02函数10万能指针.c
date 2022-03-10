#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    //万能指针可指向任意变量的内存空间
    //万能指针可以接收任意类型变量的内存地址
    int a = 10;
    void *p = &a;
    *(int *)p = 100;

    printf("%d\n", a);
    printf("%d\n", *(int *)p);
    // printf("万能指针在内存占的字节大小为:%d\n", sizeof(void *));
    // printf("%d\n", (int *)p);

    return 0;
}