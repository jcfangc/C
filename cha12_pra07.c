// 编写下列函数：
// bool search(const int a[], int n, int key);
// a  是待搜索的数组，n 是数组中元素中的数量，key 是搜索键。如果 key 与数组 a 的某个元素匹配了，那么 search 函数返回 true；否则返回 false。要求使用指针算数运算而不是去下表来访问数组元素。

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#define N 20

// 一个生成随机数组长度的函数 array_length, 长度限制和 N 相关
int array_length(void);
// 一个往固定数组长度的数组填入数字的函数 fill_array
void fill_array(int *, int);
// bool search(const int a[], int n, int key); 关键词寻找函数
_Bool search(const int *, int, int);

int main(void)
{
    // 创造一个整型数组，长度上限是 N
    int arr[N];
    int key;

    for (;;) {
        // 将数组填满
        int array_len = array_length();
        fill_array(arr, array_len);

        printf("\n\t Enter a key number: (enter negtive number to end) \n\t ");
        scanf(" %d", &key);
        getchar();
        
        if (key < 0) {
            return 0;
        }
        else if (search(arr, array_len, key)) {
            printf("\t Exist key number in array.\n\t ");
        }
        else {
            printf("\t Not founded.\n\t ");
        }
    }

    getchar();
    return 0;
}

int array_length(void)
{
    srand((unsigned)time(NULL));
    int length = rand() % N;

    return length;
}

void fill_array(int *arr, int len)
{
    int(*p);
    srand((unsigned)time(NULL));

    int ran_num;
    printf("\n\t ARRAY:");
    for (p = arr; p < arr + len; p++) {
        ran_num = rand() % 100;
        *p = ran_num;
        printf(" %d", *p);
    }

    return;
}

_Bool search(const int *arr, int len, int key)
{
    int *ptr;

    for (ptr = (int *)arr; ptr < arr + len; ptr++) {
        if ((*ptr) == key) {
            return true;
        }
        else {
            continue;
        }
    }

    // 遍历数组都没能返回 ture 时
    return false;
}