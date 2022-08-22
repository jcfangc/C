// 下列程序的输出是什么？

#include <stdio.h>

void swap(int a, int b);

int main(void)
{
  int i = 1, j = 2;


  swap(i, j);
  printf("i = %d, j = %d \n", i, j);

  getchar();
  return 0;
}

void swap(int a, int b) 
{
  int temp = a;
  a = b;
  b = temp;
}

// 对最后结果感到疑惑的同学可以多复习一下 9.3 实际参数：在函数执行过程中，对形式参数的改变不会影响实际参数的值，这是因为形式参数中包含的是实际数值的副本。