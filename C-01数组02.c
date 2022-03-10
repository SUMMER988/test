#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int arr[2][3][4] = {
        {{0}, {0}, {0}},
        {{0}, {0}, {0}}};
    int *p = &arr[0][0][0];
    printf("%d\n", sizeof(arr[0][0][0]));
    printf("%p\n", &arr[0][2][3]);
    printf("%p\n", &arr[1][0][0]);
    // int i = 0;
    // while (i < sizeof(arr) / sizeof(arr[0][0][0]))
    // {
    //     printf("%d\t", *p);
    //     p++;
    //     if ((i + 1) % 4 == 0)
    //     {
    //         printf("\n");
    //     }
    //     i++;
    // }
    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            for (size_t k = 0; k < 4; k++)
            {
                scanf("%d", &arr[i][j][k]);
            }
        }
    }
    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            for (size_t k = 0; k < 4; k++)
            {
                printf("%d\t", arr[i][j][k]);
            }
            printf("\n");
        }
    }

    return 0;
}