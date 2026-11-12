#include <stdio.h>

int main(void)
{
    int a, b;
    char op;

    /* %c 前面那个空格不能省，不然会把数字后面的回车当成运算符 */
    if (scanf("%d %c %d", &a, &op, &b) != 3) {
        printf("error\n");
        return 1;
    }

    switch (op) {
    case '+': printf("%d\n", a + b); break;
    case '-': printf("%d\n", a - b); break;
    case '*': printf("%d\n", a * b); break;
    case '/':
        if (b == 0)                 /* 除零要在做除法之前拦下来 */
            printf("error\n");
        else
            printf("%d\n", a / b);
        break;
    case '%':
        if (b == 0)
            printf("error\n");
        else
            printf("%d\n", a % b);
        break;
    default:
        printf("error\n");
    }

    return 0;
}
