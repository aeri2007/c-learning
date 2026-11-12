#include <stdio.h>

int main(void)
{
    int year, month, day;
    int yearDays = 0, i;

    printf("input year-month-day: ");
    scanf("%d-%d-%d", &year, &month, &day);

    /* 把 1 月到上个月的天数一个月一个月加进来 */
    for (i = 1; i <= month - 1; i++) {
        switch (i) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            yearDays += 31;
            break;
        case 4: case 6: case 9: case 11:
            yearDays += 30;
            break;
        case 2:
            /* 这一年是闰年吗？是闰年 2 月 29 天，否则 28 天 */
            if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
                yearDays += 29;
            else
                yearDays += 28;
            break;
        default:
            printf("invalid month!\n");
        }
    }

    /* 最后别忘了把当月的 day 加上 */
    printf("the days are %d\n", yearDays + day);
    return 0;
}
