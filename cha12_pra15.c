// 编写一个循环来显示（练习题 14 中的）temperatures 数组中第 i 行存储的所有温度读数。利用指针来访问该行中的每个元素。


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#define DAY_W 7
#define HOUR_D 24

void temperature_detector(int[][HOUR_D], int);

int main(void)
{
    int(*day)[HOUR_D], (*hour);
    int pick_num;

    int temperatures[DAY_W][HOUR_D];

    temperature_detector(temperatures, HOUR_D);

    for (;;) {
        printf("\n\t Pick a day's data, enter number (1 - 7): ");
        scanf(" %d", &pick_num);
        getchar();
        if (pick_num < 1 || pick_num > 7) {
            continue;
        }
        else {
            break;
        }
    }
   
    // 题目答案部分
    day = (temperatures + pick_num - 1);
    /* (*day) == (int[]){具体元素} 即复合常量 */
    for (hour = (*day); hour < ((*day) + HOUR_D); hour++) {
        if ((hour - (*day)) % 8 == 0) {
            printf("\n");
        }
        printf("\t %2d", (*day)[hour - (*day)]);
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

// 这里我直接借用了练习 14 的答案进行了改编。
// 书作者答案如下：

    // int *p;

    // for (p = temperatures[i]; p < temperatures[i] + 24; p++)
    // printf("%d ", *p);

// 差别在于我利用指针运算的方式取代了取下标的方式来检索元素，但相信功能都是非常相似的。