// 假设下面的数组含有一周 24 小时的温度读书，数组的每一行是每一天的读数：
// int temperature[7][24];
// 编写一条语句，使用 search 函数（见练习题 7）在整个 temperature 数组中寻找值 32。


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#define DAY_W 7
#define HOUR_D 24
#define KEY 32

void temperature_detector(int[][HOUR_D], int);
_Bool search(const int[][HOUR_D], int, int);

int main(void)
{
    int temperatures[DAY_W][HOUR_D];

    temperature_detector(temperatures, HOUR_D);

    if (search(temperatures, HOUR_D, KEY)) {
        printf("\n\n\t Key temperature %d exists in this week.", KEY);
    }
    else {
        printf("\n\n\t No found. ");
    }

    getchar();
    return 0;
}

void temperature_detector(int store_temperature[][HOUR_D], int len)
{
    int(*ptr_e), (*ptr_r)[HOUR_D];

    srand((unsigned)time(NULL));

    /* ptr_r = &store_temperature[0] == &*(store_temperature + 0) == stroe_temperature */
    for (ptr_r = store_temperature; ptr_r < (store_temperature + DAY_W); ptr_r++) {
        printf("\n\n DAY %d", (int)(ptr_r - store_temperature + 1));
        /* ptr_e = (*ptr_r) == (*(ptr_r + 0)) == (ptr_r[0]) */
        /* 因为 ptr_r 是指向二维数组中某个一维数组的指针，此时将 ptr_e 指向这个一维数组，相当于指向了一个复合常量，即类似于 (int[]){1,2,3} 的复合常量 */
        /* 详见 12.1.5 指向复合常量的指针 */
        for (ptr_e = (*ptr_r); ptr_e < ((*ptr_r) + len); ptr_e++) {
            (*ptr_r)[ptr_e - ((*ptr_r) + 0)] = ((rand() % 35) - (rand() % 10));
            if ((ptr_e - ((*ptr_r) + 0)) % 8 == 0) {
                printf("\n");
            }
            printf("\t %2d", (*ptr_r)[ptr_e - ((*ptr_r) + 0)]);
        }
    }
}

// 来自练习题7
_Bool search(const int arr[][HOUR_D], int len, int key)
{
    int(*ptr_e), (*ptr_r)[HOUR_D];

    for (ptr_r = (int (*)[HOUR_D])arr; ptr_r < (int (*)[HOUR_D])(arr + DAY_W); ptr_r++) {
        for (ptr_e = (*ptr_r); ptr_e < ((*ptr_r) + len); ptr_e++) {
            if ((*ptr_r)[ptr_e - ((*ptr_r) + 0)] == key) {
                return true;
            }
            else {
                continue;
            }
        }
    }

    return false;
}

// 题目的原意应该是用语句使得 search 原本只能用在一维数组的情况下，在temperatures （非一维数组）上面使用。这里我没有审清楚题，所以就直接改编了 search 函数使它适应于二维数组了。更切合题意的做法应该如下：

// _Bool search(const int* arr, int len, int key)
// {
//     int(*ptr);
//     for (ptr = arr; ptr < arr + len; ptr++) {
//         if ((*ptr) == key) {
//             return true;
//         }
//         else {
//             continue;
//         }
//     }
//     return false;
// }