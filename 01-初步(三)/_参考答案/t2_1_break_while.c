#include <stdio.h>

int main(void)
{
    int x = 1;

    while (x <= 10) {
        if (x == 5) break;   /* 到 5 就不玩了，直接跳出整个循环 */
        printf("%d", x);
        x++;                 /* 注意：x==5 时这句没被执行到 */
    }

    printf("\nBroke out of loop at x == %d\n", x);
    return 0;
}
