// 修改 9.6 节的 qsort.c 程序，使得 low、high 和 middle 是指向数组元素的指针而不是整数。split 函数应返回指针而不再是整数。
// 这里直接在书本原本的程序上进行修改，修改如下：

#include <stdio.h>

#define N 10

/* 使用递归的快速排序，期望得到的形式参数依次是，需要排序的数组，high 和 low 两个整型指针*/
void quicksort(int[], int *, int *);
/* 用于分割数组进行下一轮的递归，形参期望和 quicksort 函数类似 */
int *split(int[], int *, int *);

int main(void)
{
    int a[N], i;

    // 录入数组
    printf("\n\t Enter %d numbers to be sorted: ", N);
    for (i = 0; i < N; i++) {
        scanf(" %d", &a[i]);
    }
    getchar();

    // 排序
    quicksort(a, a, (a + N - 1));

    // 打印结果
    printf("\n\t In sorted order: ");
    for (i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }

    // 返回
    getchar();
    return 0;
}

void quicksort(int arr[], int *low, int *high)
{
    int(*middle);

    /* 递归的根本返回条件 */
    if (low >= high) {
        return;
    }

    /* 找到数组中已经在正确位置的元素，作为当前数组分段的分界 */
    middle = split(arr, low, high);

    /* 数组分成前后两段，递归的调用 quicksort */
    quicksort(arr, low, (middle - 1));
    quicksort(arr, (middle + 1), high);
}

int *split(int arr[], int *low, int *high)
{
    /* 指定分割元素 */
    int part_element = (*low);

    for (;;) {
        // 右侧大于分割元素的元素快速掠过
        while ((low < high) && part_element <= (*high)) {
            high--;
        }
        // 此时 high low 的相对位置调换，退出循环
        if (low >= high) {
            break;
        }
        /* 到达这一步说明，出现了在右侧的小于分割元素的元素，和 low 指向的位置进行调换 */
        (*low++) = (*high);

        // 左侧小于分割元素的元素快速掠过
        while ((low < high) && (*low) <= part_element) {
            low++;
        }
        // 此时 high low 的相对位置调换，退出循环
        if (low >= high) {
            break;
        }
        /* 到达这一步说明，出现了在左侧的大于分割元素的元素，和 high 指向的位置进行调换 */
        (*high--) = (*low);
    }

    (*high) = part_element; /* high 和 low 此时指向的数组中的位置英国是一样的 （*low）应该也可以 */
    return high; /* low */
}