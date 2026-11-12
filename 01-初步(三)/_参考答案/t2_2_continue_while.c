#include <stdio.h>

int main(void)
{
    int x = 1;

    while (x <= 10) {
        if (x == 5) {
            x++;        /* ← 这一句是救命的那一句，删掉就死循环 */
            continue;   /* 跳过下面两行，直接回到 while 的条件判断 */
        }
        printf("%d", x);
        x++;
    }
    printf("\n");
    return 0;
}
