// 编写一个循环来显示（练习 14 中的）temperatures 数组一星期中每一天的最高温度。循环体应该调用 find_largest 函数，且一次传递数组一行。

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#define DAY_W 7
#define HOUR_D 24

void temperature_detector(int[][HOUR_D], int);
int find_largest(int[], int);

int main(void)
{
    int(*day)[HOUR_D];
    int temperatures[DAY_W][HOUR_D];

    temperature_detector(temperatures, HOUR_D);

    // 答案部分
    for (day = temperatures; day < temperatures + DAY_W; day++) {
        printf("\n\t %d is highest temperature in DAY %d. ", find_largest((*day), HOUR_D), (int)(day - temperatures + 1));
    }

    getchar();
    return 0;
}

void temperature_detector(int store_temperature[][HOUR_D], int len)
{
    int(*ptr_e), (*ptr_r)[HOUR_D];

    srand((unsigned)time(NULL));

    for (ptr_r = store_temperature; ptr_r < (store_temperature + DAY_W); ptr_r++) {
        /*printf("\n\n DAY %d", (int)(ptr_r - store_temperature + 1));*/
        for (ptr_e = (*ptr_r); ptr_e < ((*ptr_r) + len); ptr_e++) {
            (*ptr_r)[ptr_e - ((*ptr_r) + 0)] = ((rand() % 35) - (rand() % 10));
            /*if ((ptr_e - ((*ptr_r) + 0)) % 8 == 0) {
                printf("\n");
            }
            printf("\t %2d", (*ptr_r)[ptr_e - ((*ptr_r) + 0)]);*/
        }
    }
}

int find_largest(int arr[], int len)
{
    int i, (*max);

    max = arr;
    for (i = 1; i < len; i++) {
        if (*(arr + i) > *max) {
            max = arr + i;
        }
    }

    return *max;
}

// 本题答案修改自练习题14。