// 一个检测 x y 是否落在 0 至 n-1 区间内的函数
#include <stdio.h>

int check(int x, int y, int n);

int main(void)
{
  int x, y, n;

  printf("\n\t Input X Y Z in sequence.");
  printf("\n\t X: ");
  scanf("%d", &x);
  getchar();
  printf("\n\t Y: ");
  scanf("%d", &y);
  getchar();
  printf("\n\t Z: ");
  scanf("%d", &n);
  getchar();

  printf("\n\t %d", check(x, y, n));

  getchar();
  printf("\n\n");
  return 0;
}

int check(int x, int y, int n)
{
  if (x >= 0 && y >= 0) {
    if (x <= (n - 1) && y <= (n - 1)) {
      return 1;
    }
    else {
      return 0;
    }
  }
  else {
    return 0;
  }
}
