// 编写下列函数：
// void split_date(int day_of_year, int year, int *month, int *day);
// day_of_year 是 1 和 366 之间的整数，表述 year 置顶的那一年中的特定一天。month 和 day 是指向变量的指针，相应的变量在函数中分别存储等价的月（1-12）和该月中的日期（1-31）。

#include <stdio.h>

// 该函数前两个 int 型形式参数用于承载“某年中的第几日”和“具体年份”，后两个 int* 型指针用于承载需要输出的变量，即经过计算后得出的具体日期。
void split_date(int, int, int *, int *);

int main(void)
{
    int year, day;
    int month, date;

    printf("\n\t Enter a year: ");
    scanf(" %d", &year);

    for (;;) {
        // 判断年份是否是闰年
        if ((year % 4) == 0) {
            printf("\n\t Which day's date do you want to consult? \n\t (Enter a number between 1-366) \n\t ");
            scanf(" %d", &day);
            getchar(); // '\n'
            if (day <= 366 && day >= 1) {
                split_date(day, year, &month, &date);
                break;
            }
            else {
                continue;
            }
        }
        else {
            printf("\n\t Which day's date do you want to consult? \n\t (Enter a number between 1-365) \n\t ");
            scanf(" %d", &day);
            getchar(); // '\n'
            if (day <= 365 && day >= 1) {
                split_date(day, year, &month, &date);
                break;
            }
            else {
                continue;
            }
        }
    }

    // 转化月份为字符串输出
    switch (month) {
    case 1: printf("\n\t January "); break;
    case 2: printf("\n\t February "); break;
    case 3: printf("\n\t March "); break;
    case 4: printf("\n\t April "); break;
    case 5: printf("\n\t May "); break;
    case 6: printf("\n\t June "); break;
    case 7: printf("\n\t July "); break;
    case 8: printf("\n\t August "); break;
    case 9: printf("\n\t September "); break;
    case 10: printf("\n\t October "); break;
    case 11: printf("\n\t November "); break;
    case 12: printf("\n\t December "); break;
    default: printf("\n\t Month error. "); return 0;
    }

    // 输出日期
    printf("%d", date);

    getchar();
    return 0;
}

void split_date(int day_of_year, int year, int *month, int *date)
{
    if ((year % 4) == 0) {
        // 闰年每月天数的数组
        int leap_year[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
        for (int i = 0; i < 12; i++) {
            // 按照月份顺序，将月天数和输入天数相减以，直到出现负值，以确定月份
            day_of_year -= leap_year[i];
            if (day_of_year <= 0) {
                // 由于 i 从 0 开始计数，i 和 代表的月数之间始终是 +1 的关系
                *month = i + 1;
                // 此时 day_of_year = day_of_year - leap_year[i]，是一个负值，意味着和此月份的天数相比少了多少天。
                *date = leap_year[i] + day_of_year;
                return;
            }
        }
    }
    else {
        // 平年每月天数的数组
        int nonleap_year[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        for (int i = 0; i < 12; i++) {
            // 按照月份顺序，将月天数和输入天数相减以，直到出现负值，以确定月份
            day_of_year -= nonleap_year[i];
            if (day_of_year <= 0) {
                // 由于 i 从 0 开始计数，i 和 代表的月数之间始终是 +1 的关系
                *month = i + 1;
                // 此时 day_of_year = day_of_year - leap_year[i]，是一个负值，意味着和此月份的天数相比少了多少天。
                *date = nonleap_year[i] + day_of_year;
                return;
            }
        }
    }
}