#include<stdio.h>
int main(void)
{
    int cnt;
    int a;
    double A=0.0;
    double B=0.0;
    double C=0.0;
    cnt=0;
    double x;
    double y;
    double z;
    for(scanf("%d",&a);a!=0;scanf("%d",&a))
        {
            cnt++;
            if(a%15==0||a%21==0||a%35==0)
                continue;
            else if(a%3==0) A++;
                if(a%5==0) B++;
                if(a%7==0) C++;
        }
    //printf("%d\n",cnt);
    x=(A/cnt)*100.0;
    y=(B/cnt)*100.0;
    z=(C/cnt)*100.0;
    printf("%.2lf%%\n%.2lf%%\n%.2lf%%\n",x,y,z);

    return 0;
}