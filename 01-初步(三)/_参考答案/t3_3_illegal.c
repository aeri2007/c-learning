#include <stdio.h>

int main(void)
{
    int a = 1;

    /* - 和 ++ 优先级相同、都是右结合，所以先算 a++ 再取负 */
    printf("-a++ = %d\n", -a++);
    printf("a    = %d\n", a);

    /* 下面三行取消注释后都编不过，gcc 会报
       error: lvalue required as increment operand
       （++ 要的是一个能装回去的变量，不是 5 这种数值）

       5++;
       ++(a + 1);
       (a + a)++;
    */

    return 0;
}
