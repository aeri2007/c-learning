#include <stdio.h>

/*
 * 7-15 数列求和 —— 版本 3：do-while（先干活，再问要不要继续）
 *
 * do-while 和 while 的唯一差别：条件写在后面，
 * 所以循环体至少执行一次。
 *
 * 本题 n >= 1，至少有一项要算，所以这个特性不会出问题。
 * 但如果 n 可能是 0，do-while 会多算一项，那就必须换成 while。
 *
 * 另外别漏了 while 后面那个分号。
 */
int main(void)
{
    int n;
    int k = 1;
    long long sum = 0;

    scanf("%d", &n);

    do {
        sum += (long long)(k - 2) * (k - 1) * k;
        k++;
    } while (k <= n);

    printf("%lld\n", sum);
    return 0;
}
