#include <stdio.h>

/* 函数原型：提前告诉编译器"有这么个函数，吃一个 int，吐一个 int" */
int countMatch(int a);

int main(void)
{
    /* 这个 main 只干一件事：喂数据，看返回值对不对 */
    printf("countMatch(15)  = %d   期望 2\n", countMatch(15));
    printf("countMatch(21)  = %d   期望 2\n", countMatch(21));
    printf("countMatch(35)  = %d   期望 2\n", countMatch(35));
    printf("countMatch(105) = %d   期望 3\n", countMatch(105));
    printf("countMatch(3)   = %d   期望 1\n", countMatch(3));
    printf("countMatch(1)   = %d   期望 0\n", countMatch(1));
    printf("countMatch(2)   = %d   期望 0\n", countMatch(2));
    printf("countMatch(0)   = %d   自己想想应该是几\n", countMatch(0));
    return 0;
}

/* 函数定义：故意写在 main 后面，靠上面的原型顶着 */
int countMatch(int a)
{
    int match = 0;              /* 局部变量：只在 countMatch 里面活着 */

    if (a % 3 == 0) match++;    /* 能被 3 整除，记一分 */
    if (a % 5 == 0) match++;    /* 能被 5 整除，记一分 */
    if (a % 7 == 0) match++;    /* 能被 7 整除，记一分 */

    return match;               /* 只能吐一个值出去 */
}
