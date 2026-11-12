#include <stdio.h>

int main(void)
{
    int x;

    for (x = 1; x <= 10; x++) {
        if (x == 5) continue;   /* 只跳过本次，x++ 照样会执行，所以不会死循环 */
        printf("%d ", x);
    }
    printf("\n");
    return 0;
}
