#include <stdio.h>

int main(void)
{
    int n, i;
    int count = 0;

    printf("input N: ");
    scanf("%d", &n);

    printf("qualified:");
    for (i = 1; i <= n; i++) {
        /* 同一个条件，这次正着写成 if：没有 break，也没有 continue */
        if (i % 3 == 0 && i % 5 != 0) {
            printf(" %d", i);
            count++;
        }
    }

    printf("\ncount = %d\n", count);
    return 0;
}
