#include <stdio.h>

int main(void)
{
    printf("3 + 4 * 5 %% 2   = %d\n", 3 + 4 * 5 % 2);
    printf("1 < 2 == 1       = %d\n", 1 < 2 == 1);
    printf("5 > 3 ? 10 : 20  = %d\n", 5 > 3 ? 10 : 20);
    printf("!0 + 2 > 1 && 3  = %d\n", !0 + 2 > 1 && 3);
    printf("7 / 2 * 2.0      = %f\n", 7 / 2 * 2.0);
    printf("10 - 4 - 3       = %d\n", 10 - 4 - 3);
    return 0;
}
