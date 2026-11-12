#include <stdio.h>

int main(void)
{
    int a = 1, b = 0, c = 0;

    /* 赋值右结合，相当于 c=3; b=c; a=b; */
    a = b = c = 3;
    printf("a = %d, b = %d, c = %d\n", a, b, c);

    /* 同样右结合，相当于 b += 3; 然后 a += b; */
    a += b += 3;
    printf("a = %d, b = %d\n", a, b);

    return 0;
}
