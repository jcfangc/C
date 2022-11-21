// 编写下列函数：
    // int *creat_array(int n, int initial_value);
// 函数返回一个指向动态分配的 n 元 int 型数组的指针，数组的每个成员都初始化为 initial_value。如果内存分配失败，返回值为NULL。

#include <stdio.h>
#include <stdlib.h>

#define N 5

int *creat_array(int, int);

int main(int argc, char *argv[])
{
    int *arr;
    arr = creat_array(N, 2);

    // 非空才打印值
    if (arr != NULL) {
        printf("\n\t ");
        for (int i = 0; i < N; i++) {
            printf("%2d", arr[i]);
        }
    }
    else {
        printf("\n\t NULL pointer");
    }
    free(arr);

    getchar();
    return 0;
}

int *creat_array(int n, int initial_value)
{
    int *p;

    p = malloc(n * sizeof(int));
    // 非空指针才分配值
    if (p != NULL) {
        for (int *value = p; value < p + n; value++) {
            *value = initial_value;
        }
    }

    return p;
}