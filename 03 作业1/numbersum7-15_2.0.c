#include<stdio.h>
int main(void)
{
    int n, i;
    long long j;
    long long a = 0;
    long long S = 0;

    scanf("%d", &n);
    if (n <= 2) {
        printf("0\n");
    } else {
        // i直接从3开始，跳过无效的1、2项
        for (i = 3; i <= n; i++) {
            a = 0;
            for (j = 1; j <= i - 2; j++) {
                a += j * (j + 1) * (j + 2);
            }
            S += a;
        }
        printf("%lld\n", S);
    }

    return 0;
}