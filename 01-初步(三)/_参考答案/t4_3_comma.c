#include <stdio.h>

int main(void)
{
    int x, y;

    /* 有括号：整个逗号表达式的值 = 最右边那一项 30/y = 6 */
    y = 10;
    x = (y = y - 5, 30 / y);
    printf("with parens    : x = %d, y = %d\n", x, y);

    /* 没括号：逗号优先级比 = 还低，所以先做 x = y = y-5，x 得到 5 */
    y = 10;
    (void)(x = y = y - 5, 30 / y);
    printf("without parens : x = %d, y = %d\n", x, y);

    return 0;
}
