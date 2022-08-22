// 这个程序可以按照要求显示一个数的第几位
#include <stdio.h>

int digit(int, int); // 名称被省略常常是因为共同编写大写程序时避免有相同名字的宏把参数替换，导致相应的原型被破坏。

int main(void)
{
  int number, wanted_digit;

  printf("\n\t Input your number:");
  scanf("%d", &number);
  getchar();
  printf("\n\t Which digit do you want? (count from right) ");
  scanf("%d", &wanted_digit);
  getchar();

  printf("\n\t The digit you want is %d. ", digit(number, wanted_digit));

  getchar();
  printf("\n\n");
  return 0;
}

int digit(int number, int wanted_digit)
{
  int digit = 0;
  int digit_list[30] = { 0 };

  do {
    // 用数组把数字的每一位存储下来
    digit_list[digit] = (number % 10);
    number /= 10;
    ++digit;
  } while (number % 10 != 0);

  // 输出希望得到的那一位数
  return digit_list[wanted_digit - 1];
}