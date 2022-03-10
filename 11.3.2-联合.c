#include <stdio.h>

typedef union
{
    int i;
    char ch[sizeof(int)];
} CHI;

int main(int argc, char const *argv[])
{
    CHI chi;
    int i;
    chi.i = 1234;
    for (i = 0; i < sizeof(int); i++)
    {
        printf("%02hhx", chi.ch[i]); // 04D2,小端，低位在前，低位数据存放在低位地址
    }
    printf("\n");

    return 0;
}