#include<stdio.h>

void printArr(const int a[], int n)
{
    for(int i = 0; i < n;i++)
        printf("%d%c", a[i] , i == n-1 ? '\n' : ' ');       //循环打出数组a里的数字并且空格或者换行
}

#define N 6

int bubbleSort(int a[] ,int n)
{
    int swaps = 0;

    for(int i = 0;i < n - 1 ;i++){
        int swapped = 0;
        for(int j = 0;j < n - 1 - i ;j++){          //先排最大的，当i=0，最大的到最后，如此递推
            if(a[j] > a[j+1]){      
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;         //如果前项大于后项，交换两项位置
                swapped = 1;
                swaps++;
            }
        }
        printf("第 %d 轮:",i + 1);
        printArr(a,n);
        if(!swapped){
            printf("一轮没换,退出\n");
            break;
        }
    }
    return swaps;
}

int main(void)
{
    int a[N] = {5, 2, 9, 1, 5, 6,};

    printf("原始:");
    printArr(a,N);
    int s = bubbleSort(a,N);
    printf("最终:");
    printArr(a,N);
    printf("一共交换 %d次\n",s);
    return 0;
}
