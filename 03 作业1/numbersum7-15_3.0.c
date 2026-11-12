#include<stdio.h>
int main(void)
{
    int n, i, j;
    long long Ai, sum = 0;

    scanf("%d", &n);
    if (n <= 2) {
        printf("0\n");
        return 0;
    }

    // 外层：遍历第3项到第n项
    for (i = 3; i <= n; i++) {
        Ai = 0;
        // 内层：计算第i项 Ai = 1*2*3 + ... + (i-2)*(i-1)*i
        for (j = 1; j <= i - 2; j++) {
            Ai += (long long)j * (j + 1) * (j + 2);
        }
        sum += Ai; // 累加到总和
    }

    printf("%lld\n", sum);
    return 0;
}
