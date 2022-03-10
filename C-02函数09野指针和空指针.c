#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main0901(int argc, char const *argv[])
{
    //野指针-》指针变量指向一个未知空间
    //任意数值赋值给指针变量没有意义
    int *p = 100;
    //操作系统将0-255作为系统占用不允许访问
    //操作野指针对应的内存空间可能报错
    // int *q=&p;

    // printf("%d\n", *p);

    return 0;
}

int main(int argc, char const *argv[])
{
    //空指针是指内存地址编号为0的空间
    int *p = NULL;
    //操作空指针对应的空间一定会报错
    *p = 100;
    printf("%d\n", *p);
    //空指针可用作田间判断
    //日常操作更倾向于使用空指针
    return 0;
}