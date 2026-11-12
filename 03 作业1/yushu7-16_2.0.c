#include <stdio.h>
int main(void)
{
    int a;
    int total = 0;       // 数字总数（不含0）
    int cnt3 = 0, cnt5 = 0, cnt7 = 0; // 对应3、5、7的有效计数

    // 循环读入，读到0就结束
    while (scanf("%d", &a) == 1 && a != 0) {
        total++;

        // 第一步：统计这个数满足几个条件
        int match = 0;
        if (a % 3 == 0) match++;
        if (a % 5 == 0) match++;
        if (a % 7 == 0) match++;

        // 第二步：只满足1个条件时，才计入对应类别
        if (match == 1) {
            if (a % 3 == 0) cnt3++;
            if (a % 5 == 0) cnt5++;
            if (a % 7 == 0) cnt7++;
        }
    }

    // 计算百分比，先把int转成double避免整数除法
    double p3 = (double)cnt3 / total * 100.0;
    double p5 = (double)cnt5 / total * 100.0;
    double p7 = (double)cnt7 / total * 100.0;

    printf("%.2lf%%\n%.2lf%%\n%.2lf%%\n", p3, p5, p7);
    return 0;
}
