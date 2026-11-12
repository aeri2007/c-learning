#include<stdio.h>
int main(void)
{
    int n, i;
    long long Ai = 0; // 保存当前项的值
    long long sum = 0; // 保存前i项的和

    scanf("%d", &n);
    if (n <= 2) {
        printf("0\n");
        return 0;
    }

    for (i = 3; i <= n; i++) {
        Ai += (long long)(i - 2) * (i - 1) * i; // 递推算当前项
        sum += Ai; // 递推算总和
    }

    printf("%lld\n", sum);
    return 0;
}
