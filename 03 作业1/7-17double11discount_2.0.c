#include <stdio.h>

int main(void)
{
    int caseCount = 0;   /* 一共有几组 */
    int goodsCount = 0;  /* 这一组有几件商品 */
    int price = 0;       /* 单价 */
    int sum = 0;         /* 这一组的总价 */
    int i = 0;
    int j = 0;

    if (scanf("%d", &caseCount) != 1) {
        return 1;
    }

    for (i = 0; i < caseCount; i++) {
        sum = 0;                        /* 每组开始前清零，不靠"上一轮末尾顺手清" */

        if (scanf("%d", &goodsCount) != 1) {
            return 1;
        }
        for (j = 0; j < goodsCount; j++) {
            if (scanf("%d", &price) != 1) {
                return 1;
            }
            sum += price;
        }

        /* 满减从高到低判：只走第一条成立的分支，天然互斥 */
        if (sum >= 400) {
            sum -= 160;
        } else if (sum >= 300) {
            sum -= 110;
        } else if (sum >= 200) {
            sum -= 70;
        } else if (sum >= 100) {
            sum -= 30;
        }

        printf("%d\n", sum);
    }

    return 0;
}
