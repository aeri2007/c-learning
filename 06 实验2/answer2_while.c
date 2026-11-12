#include <stdio.h>

/*
 * 7-15 数列求和 —— 版本 2：while 循环
 *
 * 和 for 版本完全等价，只是把三个格子拆到了三个位置：
 *   初始化 k = 1;      -> 循环之前
 *   条件  k <= n;      -> while 的括号里
 *   步进  k++;         -> 循环体最后一句
 *
 * 注意：k++ 必须在循环体里，忘记写就是死循环。
 */
int main(void)
{
    int n;
    int k = 1;
    long long sum = 0;

    scanf("%d", &n);

    while (k <= n) {
        sum += (long long)(k - 2) * (k - 1) * k;
        k++;
    }

    printf("%lld\n", sum);
    return 0;
}
