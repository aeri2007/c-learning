#include <stdio.h>

int main(void)
{
    int n;
    char ch;
    float f;

    /* 1) 大整数装进 char：高位被切掉 */
    n = 300;
    ch = n;
    printf("300  -> char : %d\n", (int)ch);

    /* 2) 浮点装进 int：小数点后面直接扔掉（不是四舍五入） */
    f = 3.99f;
    n = f;
    printf("3.99 -> int  : %d\n", n);

    /* 3) 负数也是往 0 的方向扔，所以 -3.99 得 -3 而不是 -4 */
    f = -3.99f;
    n = f;
    printf("-3.99 -> int : %d\n", n);
    return 0;
}
