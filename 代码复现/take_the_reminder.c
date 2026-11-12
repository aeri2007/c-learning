#include<stdio.h>
int main(void)
{
    int a;
    int total = 0;
    int cnt3 = 0, cnt5 = 0, cnt7 = 0;

    while(scanf("%d",&a) == 1 && a != 0){

        total++;

        int match = 0;
        if(a % 3 == 0) match++;
        if(a % 5 == 0) match++;
        if(a % 7 == 0) match++;

        if(match == 1){
            if(a % 3 == 0) cnt3++;
            if(a % 5 == 0) cnt5++;
            if(a % 7 == 0) cnt7++;
        }
    }

    printf("%.2lf%%\n%.2lf%%\n%.2lf%%\n",
        (double)cnt3/total*100.0,
        (double)cnt5/total*100.0,
        (double)cnt7/total*100.0);

        return 0;
}