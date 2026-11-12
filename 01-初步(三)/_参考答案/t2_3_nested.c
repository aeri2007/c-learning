#include <stdio.h>

int main(void)
{
    int x, y;

    for (x = 1; x <= 2; x++) {
        for (y = 1; y <= 10; y++) {
            if (y == 5) break;      /* 只跳出内层，外层照样跑第二轮 */
            printf("x:%2d ,y:%2d\n", x, y);
        }
    }
    return 0;
}
