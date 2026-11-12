#include <stdio.h>

int main(void)
{
    int total = 12, counter = 5;
    float a1, a2, a3;

    a1 = total / counter;            /* 先整除，得到 2，再转成 2.0 */
    a2 = (float)total / counter;     /* 先把 total 变成 12.0，再做 12.0/5 */
    a3 = (float)(total / counter);   /* 先整除得 2，再把 2 转成 2.0 */

    printf("%-24s = %f\n", "total/counter", a1);
    printf("%-24s = %f\n", "(float)total/counter", a2);
    printf("%-24s = %f\n", "(float)(total/counter)", a3);
    return 0;
}
