#include <stdio.h>
#include <stdlib.h>
// free(p) 空间有借有还，一个malloc对应一个free
int main(void)
{
    int i;
    void *p = 0;
    int cnt = 0;

    free(p);

    return 0;
}