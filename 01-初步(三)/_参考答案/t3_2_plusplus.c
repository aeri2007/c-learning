#include <stdio.h>

int main(void)
{
    int y = 2, n = 3;
    int nextnum, num;

    /* ++y 先变 3 再参与运算；n++ 先拿 3 参与运算，之后 n 变 4 */
    nextnum = (++y + n++) * 6;
    num = y + n;

    printf("nextnum = %d\n", nextnum);
    printf("num     = %d\n", num);
    printf("y = %d, n = %d\n", y, n);
    return 0;
}
