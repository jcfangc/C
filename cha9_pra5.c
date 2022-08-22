// 返回正整数 n 中数字的个数
#include <stdio.h>

int num_digits(int number);

int main(void)
{
  int number;

  printf("\n\t Input your number:");
  scanf("%d", &number);
  getchar();

  printf("\n\t It has %d digit(s). ", num_digits(number));

  getchar();
  printf("\n\n");
  return 0;
}

int num_digits(int number)
{
  int digit = 0;

  // 一个数至少有一位数，用 do 循环的意义就在这里
  do {
    number /= 10;
    ++digit;
  } while (number % 10 != 0);

  return digit;
}