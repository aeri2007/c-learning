#include <stdio.h>

#define N 6

void printArr(const int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');  // 打数字, 最后一个换行
}

/* 返回一共交换了几次 */
int bubbleSort(int a[], int n)          // 注意返回类型是 int, 不是 void
{
    int swaps = 0;

    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;                // 每轮开头清零
        for (int j = 0; j < n - 1 - i; j++) {   // 是 < 不是 <=
            if (a[j] > a[j + 1]) {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;           // 前项大就交换
                swapped = 1;
                swaps++;
            }
        }
        /* ↓↓↓ 这三行必须在 for (i) 的大括号里面 ↓↓↓ */
        printf("第 %d 轮:", i + 1);
        printArr(a, n);
        if (!swapped) {
            printf("一轮没换,退出\n");
            break;
        }
        /* ↑↑↑ 到这里为止都在循环里 ↑↑↑ */
    }                                   // 这个大括号关掉 for (i)

    return swaps;
}

int main(void)
{
    int a[N] = {5, 2, 9, 1, 5, 6};

    printf("原始: ");
    printArr(a, N);

    int s = bubbleSort(a, N);

    printf("最终: ");
    printArr(a, N);
    printf("一共交换 %d 次\n", s);

    return 0;
}
