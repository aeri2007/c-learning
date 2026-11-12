#include <stdio.h>

int main()
{
    int amount;
    int price;

    printf("请输入金额(元):");
    scanf("%d",&price);

    printf("请输入票面");
    scanf("%d",&amount);

    int change=amount-price;

    printf("找你%d元。\n",change);

    return 0;
}