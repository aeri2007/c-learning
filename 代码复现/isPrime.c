#include<stdio.h>

int isPrime(int x)
{
    if(x < 2) return 0;
    else for(int i = 2;i*i <=x;i++){
        if(x % i == 0) return 0;
    }
    return 1;
}

int main(void){
    printf("%d\n",isPrime(1));
    printf("%d\n",isPrime(97));

    return 0;
}