// 根据你写的日期得出该日是该年的第几天
#include <stdio.h>

int day_of_year(int month, int day, int year);

int main(void)
{
  int month, day, year;

  printf("\n\t Month: (integer) ");
  scanf("%d", &month);
  getchar();
  printf("\n\t Day: (integer) ");
  scanf("%d", &day);
  getchar();
  printf("\n\t Year: (integer) ");
  scanf("%d", &year);
  getchar();

  printf("\n\t NO.%d day ", day_of_year(month, day, year));

  getchar();
  printf("\n\n");
  return 0;
}

int day_of_year(int month, int day, int year)
{
  int days_in_February;
  // 闰年非闰年（闰年 2月 29天）
  if ((year % 4) == 0) {
    days_in_February = 29;
  }
  else {
    days_in_February = 28;
  }
  // 声明大月数组
  int large_month[7] = { 1,3,5,7,8,10,12 };
  int number_of_large_month = 0;
  // 声明变量记录经过的大月数
  for (int i = 0; i < 7; i++) {
    if (month > large_month[i]) {
      ++number_of_large_month;
    }
  }
  // 总天数 = 大月数 * 31 + (month - 大月数 - 本月份 - 二月份) * 30 + 二月天数 + day
  //
  int total = 0;
  if (month <= 2) {
    total = number_of_large_month * 31 + (month - number_of_large_month - 1) * 30 + day;
  }
  else {
    total = number_of_large_month * 31 + (month - number_of_large_month - 2/*2的含义是本月和二月的月数*/) * 30 + days_in_February + day;
  }
  return total;
}