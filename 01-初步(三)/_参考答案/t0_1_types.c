#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    /* sizeof 的结果类型是 size_t（本机占 8 字节），配套的格式符是 %zu。
       z 就是 size 的意思，专为 size_t 设计，C99 起可用。
       写成 %d 会出问题：%d 只读 4 字节，size_t 有 8 字节，宽度对不上。 */
    printf("%-10s %-4s %s\n", "type", "size", "range");
    printf("%-10s %-4zu %d ~ %d\n", "char", sizeof(char), CHAR_MIN, CHAR_MAX);
    printf("%-10s %-4zu %d ~ %d\n", "short", sizeof(short), SHRT_MIN, SHRT_MAX);
    printf("%-10s %-4zu %d ~ %d\n", "int", sizeof(int), INT_MIN, INT_MAX);
    printf("%-10s %-4zu %ld ~ %ld\n", "long", sizeof(long), LONG_MIN, LONG_MAX);
    printf("%-10s %-4zu %lld ~ %lld\n", "long long", sizeof(long long), LLONG_MIN, LLONG_MAX);
    printf("%-10s %-4zu max %.3e, %d digits\n", "float", sizeof(float), FLT_MAX, FLT_DIG);
    printf("%-10s %-4zu max %.3e, %d digits\n", "double", sizeof(double), DBL_MAX, DBL_DIG);
    return 0;
}
