#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    //添加随机数种子
    srand((size_t)time(NULL));
    for (int i = 0; i < 100; i++)
    {
        printf("%d\t", rand() % 500 + 1500); // 0-99
        if ((i + 1) % 10 == 0)
        {
            puts("");
        }
    }

    return 0;
}