#include <stdio.h>

int main(void)
{
    int n, i;
    int count = 0;

    printf("input N: ");
    scanf("%d", &n);

    printf("qualified:");
    for (i = 1; i <= n; i++) {
        /* 反着写：不符合条件的直接 continue 走人 */
        if (i % 3 != 0 || i % 5 == 0) continue;

        printf(" %d", i);
        count++;            /* 只有没被 continue 掉的才会走到这里 */
    }

    printf("\ncount = %d\n", count);
    return 0;
}
