#include <stdio.h>

int main(void)
{
    int year, n;
    int month = 1, rest, mdays, leap;

    scanf("%d %d", &year, &n);

    /* 先判断闰年，2 月的天数要用到它 */
    leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    /* 先挡掉不合法的输入，避免下面死循环 */
    if (n < 1 || n > (leap ? 366 : 365)) {
        printf("invalid day\n");
        return 0;
    }

    rest = n;
    while (1) {
        /* 这个月有多少天 */
        switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            mdays = 31; break;
        case 4: case 6: case 9: case 11:
            mdays = 30; break;
        case 2:
            mdays = leap ? 29 : 28; break;
        default:
            mdays = 0;
        }

        /* 剩下的天数还够一整个月吗？不够就停 */
        if (rest <= mdays) break;

        rest -= mdays;   /* 够，就整整扣掉一个月 */
        month++;
    }

    printf("%d-%d-%d\n", year, month, rest);
    return 0;
}
