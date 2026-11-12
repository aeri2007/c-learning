#include<stdio.h>
int main(void){
    int a=1;
    char b=1;
    double c=1.0;

    while (a > 0)
    {
        a++;
    }
        while (b > 0)
    {
        b++;
    }
        while (c > 0)
    {
        c++;
    }

    printf("%d %d %lf",a-1,b-1,c-1);
}