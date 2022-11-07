// 编写下列函数，假定 time 结构包含三个成员：hours，minutes 和 seconds（都是 int 类型）。
// (a) struct time split_time(long total_seconds);
// total_seconds 是从午夜开始的秒数。函数返回一个包含等价时间的结构，等价的时间用小时（0-23），分钟（0-59）和秒（0-59）表示。

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define HOUR_D 24
#define MIN_H 60
#define SEC_M 60

struct time {
    int hours, minutes, seconds;
};

/* 输入从午夜开始的秒数。函数返回一个包含等价时间的结构，等价的时间用小时（0-23），分钟（0-59）和秒（0-59）表示。 */
struct time split_time(long);

int main(void)
{
    struct time t;
    long total_time;

    srand((unsigned)time(NULL));
    total_time = (rand() % (24 * 60 * 60));
    printf("\n\t Total seconds: %ld ", total_time);

    t = split_time(total_time);
    printf("\n\t The time: %.2d:%.2d:%.2d ", t.hours, t.minutes, t.seconds);

    getchar();
    return 0;
}

struct time split_time(long tt)
{
    struct time the_split;

    the_split.hours = (int)(tt / (long)(MIN_H * SEC_M));
    the_split.minutes = (int)((tt - (long)the_split.hours * (long)(MIN_H * SEC_M)) / (long)SEC_M);
    the_split.seconds = (int)(tt % (long)MIN_H);

    return the_split;
}
