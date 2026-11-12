#include <stdio.h>

/*
 * 7-15 数列求和 —— 版本 1：for 循环（最常用）
 *
 * 通项：第 k 项 = (k-2)*(k-1)*k
 * 求和：把 k 从 1 到 n 的每一项累加
 *
 * 关键点：乘法在转 long long 之前就会溢出 int，
 *         所以要把参与乘法的第一个数先转成 long long。
 */
int main(void)
{
    int n;
    int k;
    long long sum = 0;

    scanf("%d", &n);

    for (k = 1; k <= n; k++) {
        sum += (long long)(k - 2) * (k - 1) * k;
    }

    printf("%lld\n", sum);
    return 0;
}
