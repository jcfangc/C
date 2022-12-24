// 修改第 5 章的编程题 8，以便用一个单独的数组存储时间，数组的元素都是结构，每个结构包括起飞时间和对应的抵达时间。（时间都是整数，表示从午夜开始的分钟数。）程序用一个循环从数组中搜索与用户输入时间最接近的起飞时间。

// 第 5 章编程题 8：
// 编写一个程序，要求用户输入一个时间（用 24 小时制的时分表示）。程序选择起飞时间与用户输入时间最接近的航班，显示出相应的起飞时间和抵达时间。

#include <stdio.h>

#define MIN_HOUR 60
#define FLIGHT_MAX 8

typedef struct depart_arrive {
    int depart_time;
    int arrive_time;
} depart_arive;

const depart_arive schadule[] = {
    {8 * MIN_HOUR + 0,      10 * MIN_HOUR + 16},
    {9 * MIN_HOUR + 43,     11 * MIN_HOUR + 52},
    {11 * MIN_HOUR + 19,    13 * MIN_HOUR + 31},
    {12 * MIN_HOUR + 47,    15 * MIN_HOUR + 0},
    {14 * MIN_HOUR + 0,     16 * MIN_HOUR + 8},
    {15 * MIN_HOUR + 45,    17 * MIN_HOUR + 55},
    {19 * MIN_HOUR + 0,     21 * MIN_HOUR + 20},
    {21 * MIN_HOUR + 45,    23 * MIN_HOUR + 58}
};
int result_depart_hour, result_depart_min, result_arrive_hour, result_arrive_min;

void give_result(depart_arive the_flight);

int main(void)
{
    // 获取时间
    int hour, min;
    printf("\n\t Enter you planning departure time (24-hour form hh:mm): \n\t ");
    scanf(" %d:%d", &hour, &min);
    getchar();
    const int time_planned = hour * MIN_HOUR + min;

    // 找到临近航班
    int before_gap, after_gap;
    // 特殊请况
    // 早于最早航班
    if (time_planned < schadule[0].depart_time) {
        give_result(schadule[0]);
    }
    // 晚于最晚航班
    else if (time_planned > schadule[7].depart_time) {
        give_result(schadule[7]);
    }
    // 其他航班
    else {
        for (int i = 1; i < FLIGHT_MAX - 1; i++) {
            // 找到第一个比计划时间晚的时间
            if (schadule[i].depart_time >= time_planned) {
                // 计划时间之后的航班相差的时间
                after_gap = schadule[i].depart_time - time_planned;
                // 计划时间之前的航班相差的时间
                before_gap = time_planned - schadule[i - 1].depart_time;
                // 选取距离计划时间更近的航班
                after_gap <= before_gap ? give_result(schadule[i]) : give_result(schadule[i - 1]);
                break;
            }
        }
    }

    printf("\n\t Adjacent flight: from %d:%.2d to %d:%.2d.", result_depart_hour, result_depart_min, result_arrive_hour, result_arrive_min);

    getchar();
    return 0;
}

void give_result(depart_arive the_flight)
{
    result_depart_hour = the_flight.depart_time / MIN_HOUR;
    result_depart_min = the_flight.depart_time % MIN_HOUR;
    result_arrive_hour = the_flight.arrive_time / MIN_HOUR;
    result_arrive_min = the_flight.arrive_time % MIN_HOUR;
}