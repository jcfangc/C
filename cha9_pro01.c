// 编写程序，要求用户录入一串整数（把这串整数存储在数组中），然后通过调用 selection_ sort 函数来排序这些整数。在给定 n 个元素的数组后， selection_ sort 函数必须做下列工作:
// (a) 搜索数组找出最大的元素，然后把它移到数组的最后；
// (b) 递归地调用函数本身来对前 n-1 个数组元素进行排序。

#include <stdio.h>

#define N 30

void selection_sort(int[], int);

int main(void)
{
    int number_sequence[N];
    int len = 0;
    char ch;

    printf("\n\t Input numbers: ");

    // 录入数组
    for (int i = 0; i < N; i++) {
        scanf(" %d", &number_sequence[i]);
        len++;
        if ((ch = getchar()) == '\n') {
            break;
        }
        else if (ch == ' ' || ch == ',') {
            ;
        }
    }

    // 排列顺序
    selection_sort(number_sequence, len);

    // 打印
    printf("\n\t");
    for (int i = 0; i < len; i++) {
        printf(" %d", number_sequence[i]);
    }

    getchar();
    printf("\n\n");
    return 0;
}

void selection_sort(int arr[], int length)
{
    // 防止递归忘记返回条件，先列出返回条件
    if (length < 2) {
        return;
    }

    int big = 0;
    int big_index = 0;

    // 抓取最大数，和获取最大数的索引下标
    big = arr[0];
    for (int i = 1; i < length; i++) {
        big = (big > arr[i]) ? big : arr[i];
        big_index = (big == arr[i]) ? (i) : big_index;
    }

    // 最大数和末尾数交换位置
    arr[big_index] = arr[length - 1];
    arr[length - 1] = big;

    // 递归
    selection_sort(arr, length - 1);
}
