#include<stdio.h>

void PrintAn(int a[], int n)
{
    for(int i = 0;i < n;i++){
        printf("%d%c",a[i], i < n-1? ' ': '\n');
    }
}

#define N 6

int BubbleSort(int a[], int n)
{
    int swaps = 0;

    for(int i = 0;i < n-1;i++)
    {
        int swapped = 0;
        
        for(int j = 0;j < n - i - 1; j++){
            if(a[j] > a[j+1]){
                int t;
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
                swapped = 1;
                swaps++;
            }
        }
        printf("第%d轮:",i);
        PrintAn(a,n);
        if(!swapped){
            printf("没有进行替换");
            break;
        }
    }
    return swaps;
}

int main(void)
{
    int a[N] = {5, 2, 9, 1, 5, 6,};

    printf("原始:");
    PrintAn(a , N);
    int s = BubbleSort(a,N);
    PrintAn(a,N);
    printf("一共交换了 %d 次", s);

    return 0;

}
