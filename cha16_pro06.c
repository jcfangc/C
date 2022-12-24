// 修改第 5 章编程题 9，以便用户输入日期都存储在一个 date 结构（见练习题 5）中。把练习题 5 中的 compare_dates 函数集成到你的程序中。

// 第 5 章编程题 9:
// 编写一个程序，提示用户输入的两个日期，然后显示哪一个日期更早。

#include <stdio.h>

#define LARGER 1
#define SMALLER -1
#define EQUAL 0
#define MONTHS 12

typedef struct date {
    int year;
    int month;
    int day;
} date;

int day_of_year(struct date);
int compare_dates(struct date, struct date);

int main(void)
{
    date d1, d2;

    printf("\n\t Enter first date: (dd/mm/yy) \n\t ");
    scanf(" %d/%d/%d", &d1.day, &d1.month, &d1.year);
    getchar();
    printf("\n\t Enter second date: (dd/mm/yy) \n\t ");
    scanf(" %d/%d/%d", &d2.day, &d2.month, &d2.year);
    getchar();

    if (compare_dates(d1, d2) == SMALLER) {
        printf("\n\t %.2d/%.2d/%d is earlier than %.2d/%.2d/%d.", d1.day, d1.month, d1.year, d2.day, d2.month, d2.year);
    }
    else if (compare_dates(d1, d2) == LARGER) {
        printf("\n\t %.2d/%.2d/%d is earlier than %.2d/%.2d/%d.", d2.day, d2.month, d2.year, d1.day, d1.month, d1.year);
    }
    else if (compare_dates(d1, d2) == EQUAL) {
        printf("\n\t Same day. ");
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