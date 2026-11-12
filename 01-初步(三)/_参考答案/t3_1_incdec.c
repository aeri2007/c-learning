#include <stdio.h>

int main(void)
{
    int i;

    /* 第一组：后置 ++ ，先拿 5 去比，比完 i 才变 6 */
    i = 5;
    if (i++ > 5) printf("i=%d, i++>5 is true\n", i);
    printf("i=%d\n", i);

    /* 第二组：前置 ++ ，i 先变 6，再拿 6 去比 */
    i = 5;
    if (++i > 5) printf("i=%d, ++i>5 is true\n", i);
    printf("i=%d\n", i);

    /* 第三、四组：把 5 换成 4 再来一遍，看条件真假会怎么变 */
    i = 5;
    if (i++ > 4) printf("i=%d, i++>4 is true\n", i);
    printf("i=%d\n", i);

    i = 5;
    if (++i > 4) printf("i=%d, ++i>4 is true\n", i);
    printf("i=%d\n", i);

    return 0;
}
