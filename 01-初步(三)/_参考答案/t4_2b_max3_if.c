#include <stdio.h>

int main(void)
{
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);

    /* 同一件事用 if 写一遍：更长，但一眼能读懂 */
    if (a > b && a > c)
        printf("max = %d\n", a);
    else if (b > c)
        printf("max = %d\n", b);
    else
        printf("max = %d\n", c);

    return 0;
}
