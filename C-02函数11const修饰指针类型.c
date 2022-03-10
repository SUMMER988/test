#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define SIZE 99

int main1101(int argc, char const *argv[])
{
    // SIZE = 50;//error
    const int a = 10;
    // a=1000;//error
    //指针间接修改常量的值
    int *p = (int *)&a;
    *p = 100;
    printf("%d\n", *p);

    return 0;
}

int main1102(void)
{
    int a = 10;
    int b = 20;
    const int *p = &a;
    // *p = 100;//error
    p = &b;
    printf("%d\n", *p);
    return 0;
}
int main1103(void)
{
    int a = 10;
    int b = 20;
    int *const p = &a;
    // p = &b;//error
    *p = 100;
    printf("%d\n", *p);
    return 0;
}
int main(void)
{
    int a = 10;
    int b = 20;
    const int *const p = &a;
    // const 修饰指针类型，修饰指针变量
    //  p = &b; // error
    //*p = 100;//error
    //二级指针操作

    int **pp = &p;
    *pp = &b;
    // **pp = 100;
    printf("%d\n", *p);
    return 0;
}