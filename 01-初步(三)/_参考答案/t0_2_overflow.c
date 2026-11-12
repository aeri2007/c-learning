#include <stdio.h>

int main(void)
{
    signed char c = 127;
    unsigned char u = 255;

    printf("before : c = %d, u = %d\n", c, u);

    c = c + 1;      /* 127 再加 1：超出 8 位能表示的正数上限 */
    u = u + 1;      /* 255 再加 1：超出 8 位无符号的上限 */

    printf("after  : c = %d, u = %d\n", c, u);
    printf("as char: c = [%c]  <- not printable\n", c);
    return 0;
}
