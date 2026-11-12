#include <stdio.h>

int main(void)
{
    char grade;

    printf("input grade: ");
    scanf("%c", &grade);

    switch (grade) {
    case 'A':
    case 'a': printf("85-100\n");  break;
    case 'B':
    case 'b': printf("70-84\n");   break;
    case 'C':
    case 'c': printf("60-69\n");   break;
    case 'D':
    case 'd': printf("below 60\n"); break;
    default:  printf("input error!\n");
    }

    return 0;
}
