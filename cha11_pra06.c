// 编写下列函数：
// void find_two_largest(int a[], int n, int *largest, int *second_largest);
// 当传递长度为 n 的数组 a 时，函数将在数组 a 中搜寻最大元素和第二大元素，把它们分别存储在由 largest 和 second_largest 指向的变量中。

#include <stdio.h>

#define N 30

void find_two_largest(int[], int, int *, int *);

int main(void)
{
    int num[N], biggest, sec_biggest, length;
    char ch;

    do {
        length = 0;
        printf("\n\t Enter less than %d numbers but 2 numbers at least: ", N);
        for (int i = 0; i < N; i++) {
            scanf(" %d", &num[i]);
            length++;
            if ((ch = getchar()) == ' ' || ch == ',') {
                ;
            }
            else if (ch == '\n') {
                break;
            }
        }
    } while (length < 2);

    find_two_largest(num, length, &biggest, &sec_biggest);

    printf("\n\t Largest: %d ", biggest);
    printf("\n\t Second Largest: %d ", sec_biggest);

    getchar();
    return 0;
}

void find_two_largest(int num_array[], int length_of_array, int *big_in_array, int *secbig_in_array)
{
    // 将数列按照从小到大顺序排序
    // 可以将 pass 理解为包括当前正在排列的，已经排列好了的元素。
    // 鉴于下面的注释所提及的效果，最外层循环只需要执行两次就可以排列出数组中最大和次最大的元素于数组末端。
    // 如果需要将数组完整排序，我们只需要将循环条件从 < 3 改为 < length_of_array 即可。
    for (int pass = 1; pass < 3; pass++) {
        for (int index = 0; index < length_of_array - pass; index++) {
            // 因为较大的数在遇到较小的数时会被往后移动一位，而下一次循环的下标恰好比上一次的下标多一，则造成了较大的数在遇到比自己更大的数之前会一直往数组末尾移动的效果。
            // 这也同时意味着，最大数在一次遍历下标的循环后就会出现在数组的最末尾的位置。下次遍历下标后，次最大的元素会被排列在数组的倒数第二位（由于 length_of_array - pass 的设定）。
            int temp = num_array[index];
            if (num_array[index] > num_array[index + 1]) {
                num_array[index] = num_array[index + 1];
                num_array[index + 1] = temp;
            }
        }
    }

    // 取排序好的数组最后两个元素，分别作为最大，次最大的值。
    *big_in_array = num_array[length_of_array - 1];
    *secbig_in_array = num_array[length_of_array - 2];

    return;
}

// 本题答案改编自本章 max_min 程序题。而原书作者给出的答案要更加强调了数组元素之间的比较，而非像我这样排序后直接选取数组末端两个元素。想要了解的同学可以复制一下链接查看。
// 链接如下：
// http://knking.com/books/c2/answers/c11.html

