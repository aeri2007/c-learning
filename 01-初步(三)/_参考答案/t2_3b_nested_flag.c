#include <stdio.h>

int main(void)
{
    int x, y;
    int stop = 0;      /* 标志位：内层想告诉外层“别跑了” */

    for (x = 1; x <= 2 && stop == 0; x++) {
        for (y = 1; y <= 10; y++) {
            if (y == 5) {
                stop = 1;   /* 先挂牌子 */
                break;      /* 再退出内层 */
            }
            printf("x:%2d ,y:%2d\n", x, y);
        }
    }
    printf("stopped, x = %d\n", x);
    return 0;
}
