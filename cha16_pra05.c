// 编写下列函数，假定 date 结构包含三个成员：month，day 和 year（都是 int 类型）。
// (a) int day_of_year(struct date d);
// 返回 d 是一年中的第多少天（1 和 366 之间的整数）。
// (b) int compare_dates(struct date d1, struct date d2);
// 如果日期 d1 在 d2 之前，返回 -1；如果 d1 在 d2 之后，返回 +1；如果 d1 和 d2 相等，返回0。

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MONTHS 12
#define LARGER 1
#define SMALLER -1
#define EQUAL 0
#define IS_PRIME_YEAR(x) (((x)%4==0)?1:0)

struct date {
    int month, day, year;
};

/* 给出随机的日期，保存在输入的结构 date 中。 */
struct date set_date(struct date);
/* 返回值是一年中的第多少天（1 和 366 之间的整数）。 */
int day_of_year(struct date);
/* 如果日期 d1 在 d2 之前，返回 -1；如果 d1 在 d2 之后，返回 +1；如果 d1 和 d2 相等，返回0。 */
int compare_dates(struct date, struct date);

int main(void)
{
    struct date date_1, date_2;

    /* 给出具体日期 */
    date_1 = set_date(date_1);
    date_2 = set_date(date_2);

    /* 出示日期，测试 day_of_year 函数 */
    printf("\n\t First date: Y: %d, M: %d, D: %d ", date_1.year, date_1.month, date_1.day);
    printf("\n\t NO. %d day of %d ", day_of_year(date_1), date_1.year);
    printf("\n\n\t Second date: Y: %d, M: %d, D: %d ", date_2.year, date_2.month, date_2.day);
    printf("\n\t NO. %d day of %d ", day_of_year(date_2), date_2.year);

    /* 测试 compare_dates 函数 */
    if (compare_dates(date_1, date_2) < EQUAL) {
        printf("\n\n\t First date is ealier than second date. ");
    }
    else if (compare_dates(date_1, date_2) == EQUAL) {
        printf("\n\n\t First date and second date are same date. ");
    }
    else {
        printf("\n\n\t Second date is ealier than first date. ");
    }

    getchar();
    return 0;
}

int day_of_year(struct date d)
{
    const int day_of_month[MONTHS] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
    const int *month = day_of_month;
    int result = 0;

    /* 完全经历的月份，增加当月天数 */
    for (; month < day_of_month + d.month - 1; month++) {
        result += (*month);
    }

    /* 未完全经历的月份，当月经历了的天数 */
    return (result + d.day);
}

int compare_dates(struct date d1, struct date d2)
{
    /* 比较年份 */
    if (d1.year > d2.year) {
        return LARGER;
    }
    else if (d1.year < d2.year) {
        return SMALLER;
    }
    else {
        /* 同年比较日期先后 */
        if (day_of_year(d1) > day_of_year(d2)) {
            return LARGER;
        }
        else if (day_of_year(d1) < day_of_year(d2)) {
            return SMALLER;
        }
        else {
            return EQUAL;
        }
    }
}

struct date set_date(struct date d)
{
    srand((unsigned)time(NULL));
    /* 设定年份 */
    do {
        d.year = (1800 + (rand() % 223)); // 1800 - 2022
    } while (!IS_PRIME_YEAR(d.year));

    /* 设定月份 */
    d.month = (rand() % MONTHS) + 1; // 1 - 12

    /* 设定日期 */
    switch (d.month) {
        case 1: case 3: case 5: case 7: case 8: case 10:
        case 12: d.day = (rand() % 31) + 1; break; // 1 - 31
        case 2: d.day = (rand() % 29) + 1; break; // 1 - 29
        case 4: case 6: case 9:
        case 11: d.day = (rand() % 30) + 1; break; // 1 - 30
        default: printf("\n\t Error Month."); break;
    }

    printf("\n\t Date setted, press a key to continue... ");
    getchar();

    return d;
}