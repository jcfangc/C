// 如果程序只有一个函数（main），那么它最多可以包含多少个名为 i 的不同变量？

#include <stdio.h>

int i = 1;

int main(void)
{
  printf("\n\t This is the No.%d i.", i);

  int i = 2;
  printf("\n\t This is the No.%d i.", i);

  {
    char i[1] = { '3' };
    printf("\n\t This is the No.%c i.", i[0]);
  }

  {
    int i[1] = { 4 };
    printf("\n\t This is the No.%d i.", i[0]);
  }

  {
    int i = 5;
    printf("\n\t This is the No.%d i.", i);
  }

  getchar();
  printf("\n\n");
  return 0;
}

// 从运行后的结果可以看到，只要在 main 中另外放置一对花括号，花括号中声明的同名变量不会受到花括号外变量的影响。那按照这样的做法似乎可以在main 中放置无限多个名为 i 的不同变量。