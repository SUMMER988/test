#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number, n;
    int inp;
    while (1)
    {
        int finished = 0;
        int cnt = 0;
        scanf("%d %d", &number, &n);
        do
        {
            scanf("%d", &inp);
            cnt++;
            if (inp < 0)
            {
                printf("Game over\n");
                finished = 1;
            }
            else if (inp > number)
            {
                printf("Too big\n");
            }
            else if (inp < number)
            {
                printf("Too small\n");
            }
            else
            {
                if (cnt == 1)
                {
                    printf("Bingo!\n");
                }
                else if (cnt <= 3)
                {
                    printf("Lucky you!\n");
                }
                else
                {
                    printf("Good guess!\n");
                }
                finished = 1;
            }
            if (cnt == n)
            {
                if (!finished)
                {
                    printf("Game over!\n");
                    finished = 1;
                }
            }
        } while (!finished);
        rewind(stdin);
    }
}