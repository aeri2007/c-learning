#include<stdio.h>
int main(void)
{
    long long int j=0;
    int n=0;
    int i=0;
    long long int a=0;
    long long int S=0;

    scanf("%d",&n);
    if(n<=2) printf("0");
    else
    {
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i-2;j++)
        {
           a=a+j*(j+1)*(j+2);
            //printf("%d\n",a);
        }
        S=S+a;
        a=0;
    }
            printf("%lld\n",S);
    }

    return 0;
}