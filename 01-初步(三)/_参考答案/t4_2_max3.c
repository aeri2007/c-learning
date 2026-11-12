#include <stdio.h>

int main(void)
{
    int a, b, c, m;

    scanf("%d %d %d", &a, &b, &c);

    /* 分两步：先比出前两个的较大者，再拿它和第三个比 */
    m = a > b ? a : b;
    m = m > c ? m : c;

    printf("max = %d\n", m);
    return 0;
}
