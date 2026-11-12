#include <stdio.h>

int main(void)
{
    char ch;

    printf("input a char: ");
    scanf("%c", &ch);

    /* 是大写就先 +32 变小写，不是就原样留着 */
    ch = (ch >= 'A' && ch <= 'Z') ? ch + 32 : ch;

    printf("%c\n", ch);
    return 0;
}
