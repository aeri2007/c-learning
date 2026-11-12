#include <stdio.h>
int main()
{
    int j=1;
    printf("%d",j); // j没初始化！打印随机垃圾数字，每次运行结果可能不一样
    return 0;
}