// 这个程序用来计算最大公约数
#include <stdio.h>

int gcd(int x, int y);

int main(void)
{
  int x, y, n;

  printf("\n\t First integer: ");
  scanf("%d", &x);
  getchar();
  printf("\n\t Second integer: ");
  scanf("%d", &y);
  getchar();

  printf("\n\t GCD: %d", gcd(x, y));

  getchar();
  printf("\n\n");
  return 0;
}


int gcd(int x, int y)
{
  int transit;
  int remainder;

  // 保证变量 x 中存放着更大的数
  if (y > x) {
    transit = y;
    y = x;
    x = transit;
  }
  else {
    // 算法本身
    for (; y != 0;) {
      remainder = x % y;
      x = y;
      y = remainder;
    }
    return x;
  }
}