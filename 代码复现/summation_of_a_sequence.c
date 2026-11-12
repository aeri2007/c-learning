#include<stdio.h>
int main(void)
{
    int i,n;
    long long sum = 0;
    long long Ai = 0;

    scanf("%d",&n);
    if(n<=2){
        printf("0\n");
        return 0;
    }

    for(i=3;i<=n;i++){
        Ai += (long long)(i-2)*(i-1)*i;
        sum +=Ai;
    }

    printf("%lld\n",sum);
    return 0;
}