// 修改第 5 章编程题 8，使其包含下列函数：
// void find_closest_flight(int desired_time, int* departure_time, int* arrival_time);
// 函数需查出起飞时间与 desire_time（用从午夜开始的分钟数表示）最接近的航班。该航班的起飞时间和抵达时间（也都用午夜开始的分钟数表示）将分别存储在 departure_time 和 arrival_time 所指向的变量中。

// 第 5 章 编程题 8：
// 下面的表格给出了一个城市到另一个城市的每日航班信息。

// --------------------------------------
// 起飞时间          |          抵达时间
// --------------------------------------
// 8:00a.m.         |           10:16a.m.
// 9:43a.m.         |           11:52a.m.
// 11:19a.m.        |           1:31p.m.
// 12:47a.m.        |           3:00p.m.
// 2:00p.m.         |           4:08p.m.
// 3:45p.m.         |           5:55p.m
// 7:00p.m.         |           9:20p.m.
// 9:45p.m.         |           11:58p.m.


// 编写一个程序，要求用户输入一个时间（用 24 小时制的时分表示）。程序选择起飞时间与用户输入最接近的航班，显示出相应的起飞时间和抵达时间。

// Enter a 24-hour time: 13:15
// Closest departure time is 12:47 p.m. , arriving at 3:00 p.m.

// 提示：把输入用从午夜开始的分钟数表示。将这个时间与表格里也用从午夜开始的分钟数表示的起飞时间相比。例如，13:15 从午夜开始是 13 * 60 + 15 = 795 分钟，与下午 12:47（从午夜开始是 767 分钟）最接近。

#include <stdio.h>

#define HOUR_ROW 0
#define MIN_ROW 1
#define ARRIVAL_INDEX 2

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time);

int main(void)
{
    int input_hour_24, input_min_24, input_time_24;
    int departure_time_12, arrival_time_12;

    printf("\n\t Enter a 24-hour time: ");
    scanf(" %d: %d", &input_hour_24, &input_min_24);
    getchar();

    // 用午夜起的分钟数表示输入的时间
    input_time_24 = (input_hour_24 * 60) + input_min_24;

    find_closest_flight(input_time_24, &departure_time_12, &arrival_time_12);

    // 转为 12 小时制并输出结果
    // 中午 12点 为 a.m.
    if (departure_time_12 < (13 * 60)) {
        printf("\n\t Closest departure time is %d:%.2d a.m., ", (departure_time_12 / 60), (departure_time_12 - ((departure_time_12 / 60) * 60)));
    }
    else {
        printf("\n\t Closest departure time is %d:%.2d p.m., ", ((departure_time_12 / 60) - 12), (departure_time_12 - ((departure_time_12 / 60) * 60)));
    }
    if (arrival_time_12 < (13 * 60)) {
        printf("arriving at %d:%.2d a.m. ", (arrival_time_12 / 60), (arrival_time_12 - ((arrival_time_12 / 60) * 60)));
    }
    else {
        printf("arriving at %d:%.2d p.m. ", ((arrival_time_12 / 60) - 12), (arrival_time_12 - ((arrival_time_12 / 60) * 60)));
    }

    getchar();
    return 0;
}

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time)
{
    // 两个变量用于比较时间表上位于 desired_time 最邻近的前后两个时间与 desire_time 的距离
    int after_DesireTime, before_DesireTime;

    int time_table[2][16] = {
        // 将起飞和降落时间间隔放入数组中,时间的小时数和分钟数分别放在行,其中偶数下标均为起飞时间
        {8,10,9,11,11,13,12,15,14,16,15,17,19,21,21,23},
        {0,16,43,52,19,31,47,0,0,8,45,55,0,20,45,58},
    };

    // 将输入时间和起飞时间进行比较,找到最临近的航班
    // 遍历列数
    for (int i = 0; i < 16; i += ARRIVAL_INDEX) {
        // 遍历数组,起飞时间 - 输入时间,直到出现第一个正值
        if (((((time_table[HOUR_ROW][i] * 60) + time_table[MIN_ROW][i]) - desired_time) >= 0) && i < 14) {
            after_DesireTime = ((time_table[HOUR_ROW][i] * 60) + time_table[MIN_ROW][i]) - desired_time;
            // 找到前一起飞时间,比较两者与输入时间之差的绝对值
            if ((i - 2) > 0) {
                before_DesireTime = desired_time - ((time_table[HOUR_ROW][i - ARRIVAL_INDEX] * 60) + time_table[MIN_ROW][i - ARRIVAL_INDEX]);
                // 取最邻近的时间作为返回结果
                *departure_time = (after_DesireTime < before_DesireTime ? ((time_table[HOUR_ROW][i] * 60) + time_table[MIN_ROW][i]) : ((time_table[HOUR_ROW][i - ARRIVAL_INDEX] * 60) + time_table[MIN_ROW][i - ARRIVAL_INDEX]));
                *arrival_time = (after_DesireTime < before_DesireTime ? ((time_table[HOUR_ROW][i + 1] * 60) + time_table[MIN_ROW][i + 1]) : ((time_table[HOUR_ROW][i - ARRIVAL_INDEX + 1] * 60) + time_table[MIN_ROW][i - ARRIVAL_INDEX + 1]));
                return;
            }
            else {
                // 进入这一分支说明:今日第一班航班已经是最邻近的航班了
                *departure_time = ((time_table[HOUR_ROW][i] * 60) + time_table[MIN_ROW][i]);
                *arrival_time = ((time_table[HOUR_ROW][i + 1] * 60) + time_table[MIN_ROW][i + 1]);
                return;
            }
        }
        else if (i == 14) {
            // 进入这一分支意味着,已经遍历到了出发时间的最后一个,此前都未出现正值,则意味着,今日最后一班航班即为最近邻的航班
            *departure_time = ((time_table[HOUR_ROW][i] * 60) + time_table[MIN_ROW][i]);
            *arrival_time = ((time_table[HOUR_ROW][i + 1] * 60) + time_table[MIN_ROW][i + 1]);
            return;
        }
    }
}
