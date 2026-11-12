#include <stdio.h>
int main(void)
{
    int a;
    int total = 0;
    int cnt3 = 0, cnt5 = 0, cnt7 = 0;

    while (scanf("%d", &a) == 1 && a != 0) {
        total++;
        // 同时是两个及以上的倍数，直接跳过，不计数
        if (a % 15 == 0 || a % 21 == 0 || a % 35 == 0) {
            continue;
        }
        if (a % 3 == 0) cnt3++;
        if (a % 5 == 0) cnt5++;
        if (a % 7 == 0) cnt7++;
    }

    printf("%.2lf%%\n%.2lf%%\n%.2lf%%\n",
           (double)cnt3 / total * 100.0,
           (double)cnt5 / total * 100.0,
           (double)cnt7 / total * 100.0);
    return 0;
}
