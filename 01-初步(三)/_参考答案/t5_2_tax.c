#include <stdio.h>

int main(void)
{
    int income, residency;
    double taxRate;

    scanf("%d %d", &income, &residency);

    /* 关系运算 > 逻辑运算 > 条件运算 > 赋值，所以三组比较自动分好组 */
    taxRate = income > 4000 && residency < 5 ? 3.5 : 2.0;

    printf("taxRate = %.1f\n", taxRate);
    return 0;
}
