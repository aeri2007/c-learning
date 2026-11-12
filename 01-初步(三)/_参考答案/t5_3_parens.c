#include <stdio.h>

int main(void)
{
    int a = 1, b = 2, c = 3, d = 4, e = 5;
    int x, y;

    /* 1) 乘除同级、自左向右：先 b*c，再 /d */
    printf("a + b * c / d - e         = %d\n", a + b * c / d - e);
    printf("a + ((b * c) / d) - e     = %d\n", a + ((b * c) / d) - e);

    /* 2) && 比 || 先算 */
    printf("a < b || c > d && e       = %d\n", a < b || c > d && e);
    printf("(a < b) || ((c > d) && e) = %d\n", (a < b) || ((c > d) && e));

    /* 3) 赋值右结合：x = y = 3 等价于 x = (y = 3) */
    x = y = 3;
    printf("x = y = 3                 -> x = %d, y = %d\n", x, y);

    /* 4) 单目右结合：-a++ 等价于 -(a++)，不是 (-a)++ */
    a = 1;
    printf("-a++                      = %d\n", -a++);
    printf("  然后 a                  = %d\n", a);
    a = 1;
    printf("-(a++)                    = %d\n", -(a++));
    printf("  然后 a                  = %d\n", a);

    /* 5) 嵌套 ?: 右结合：a ? b : (c ? d : e)，不是 (a ? b : c) ? d : e */
    printf("a ? b : c ? d : e         = %d\n", a ? b : c ? d : e);
    printf("(a ? b : c) ? d : e       = %d\n", (a ? b : c) ? d : e);

    return 0;
}
