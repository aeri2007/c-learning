#include<stdio.h>

int main()
{
    int number1=0;
    int number2=0;
    int number3=0;
    int max=0;
    int min=0;
    int mid=0;

    printf("请输入三个数字：");
    scanf("%d %d %d", &number1, &number2, &number3);

    /* 打擂台找最大值 */
    max = number1;
    if (number2 > max) {
        max = number2;
    }
    if (number3 > max) {
        max = number3;
    }

    /* 打擂台找最小值 */
    min = number1;
    if (number2 < min) {
        min = number2;
    }
    if (number3 < min) {
        min = number3;
    }

    /* 总和减去两头，剩下的就是中间数 */
    mid = number1 + number2 + number3 - max - min;

    printf("中间数是：%d\n", mid);

    return 0;
}
