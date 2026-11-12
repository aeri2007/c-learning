#include <stdio.h>

int main(void)
{
    int day;

    printf("input day (0-6): ");
    scanf("%d", &day);

    /* 和 1-1 唯一的区别：7 个 break 全被删掉了 */
    switch (day) {
    case 0: printf("Sunday\n");
    case 1: printf("Monday\n");
    case 2: printf("Tuesday\n");
    case 3: printf("Wednesday\n");
    case 4: printf("Thursday\n");
    case 5: printf("Friday\n");
    case 6: printf("Saturday\n");
    default: printf("Invalid day!\n");
    }

    return 0;
}
