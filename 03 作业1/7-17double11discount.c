#include<stdio.h>
int main(void)
{
    int n=0;
    int S=0;
    int i=0;
    int j=0;
    int a=0;

    scanf("%d",&n);
    for(j=1;j<=n;j++){
        for(scanf("%d",&i);i!=0;i--){
            scanf("%d",&a);
                S=S+a;}
            switch(S/100)
        {
        case 0: S=S;
        break;
        case 1: S=S-30;
        break; 
        case 2: S=S-70;
        break;
        case 3: S=S-110;
        break;
        default:S=S-160;
        }
        printf("%d\n",S);
        S=0;
}
    return 0;
}