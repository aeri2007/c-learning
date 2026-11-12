#include <stdio.h>

/*
 * 反例：用 int 存结果 —— 大 n 时必然溢出
 *
 * 这不是答案，是用来演示「为什么题目要提示 long long」的实验品。
 *
 * n = 3000 时，正确结果约 2.0e13（20 万亿），
 * 而 int 最大只到 2.1e9（21 亿），差了一万倍。
 * 你会看到一个莫名其妙的小数字甚至负数。
 *
 * 两个地方都会翻车：
 *   1. sum 是 int，装不下
 *   2. (k-2)*(k-1)*k 三个 int 相乘，中间结果就已经炸了
 *
 * 拿 n=3000 跑一下这个文件，再跑 answer1_for.c，对比输出。
 */
int main(void)
{
    int n;
    int k;
    int sum = 0;                          /* 坑 1 */

    scanf("%d", &n);

    for (k = 1; k <= n; k++) {
        sum += (k - 2) * (k - 1) * k;     /* 坑 2：全是 int 在乘 */
    }

    printf("%d\n", sum);
    return 0;
}
