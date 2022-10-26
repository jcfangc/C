// 用指针算数运算代替数组取下标来重新编写下面的函数。（换句话说，消除变量 i、j 和所有用到 [] 运算符的地方。）要求使用单层循环而不是嵌套循环。
// 原函数：
// int sum_two_dimensional_array(const int a[][LEN], int n)
// {
//     int i, j, sum = 0;
    
//     for (i = 0;i < n;i++)
//         for (j = 0;j < LEN;j++)
//             sum + a[i][j];
    
//     return sum;
// }

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define LEN 5

int sum_two_dimensional_array(const int[][LEN], int);
void fill_array_2(int[][LEN], int);

int main(void)
{
    int arr[4][LEN];

    fill_array_2(arr, 4);
    printf("\n\n\t Sum: %d ", sum_two_dimensional_array(arr, 4));

    getchar();
    return 0;
}

void fill_array_2(int arr[][LEN], int clen)
{
    srand((unsigned)time(NULL));

    int(*row)[LEN] = arr;
    int(*element) = (*row);

    printf("\n\t");
    for (; (*row) + (element - (*row)) < ((*arr) + (clen /*行数*/ * LEN /*列数*/)); element++) {
        /* 以 LEN 为周期，打印换行符和制表符，使得打印效果更好 */
        if ((element - (*row)) != 0 && (element - (*row)) % LEN == 0) {
            /* 使得 element 指向下一行行首的元素 */
            element = (*++row);
            printf("\n\t");
        }
        *((*row) + (element - (*row))) = (int)(rand() % 10);
        printf(" %d", (int)(*((*row) + (element - (*row)))));
    }
}

/* 答案部分 */
int sum_two_dimensional_array(const int arr[][LEN], int n)
{
    int(*row)[LEN] = (int (*)[LEN])arr;
    int(*element) = (*row);
    int sum = 0;

    for (; (*row) + (element - (*row)) < ((*arr) + (n * LEN)); element++) {
        if ((element - (*row)) != 0 && (element - (*row)) % LEN == 0) {
            /* 使得 element 指向下一行行首的元素 */
            element = (*++row);
        }
        sum += (int)(*((*row) + (element - (*row))));
    }

    return sum;
}