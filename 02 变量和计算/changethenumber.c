#include<stdio.h>

int main()
{
    int a=5;
    int b=6;
    int c=0;
    c=a;
    a=b;
    b=c;
    printf("a=%d,b=%d",a,b);
    return 0;
}