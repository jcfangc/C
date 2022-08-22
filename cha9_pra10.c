// 编写函数，使得函数返回下列值。（假设 a 和 n 是形式参数， 其中 a 是 int 类型数组，而 n 则是数组的长度。)
// (a)数组a中的最大元素。
// (b)数组a中所有元素的平均值。
// (c)数组a中正数元素的数量。

#include <stdio.h>

int greatest_element(int[], int);
double array_average(int[], int);
void positive_element(int[], int);

int main(void)
{
  int a[10];

  printf("\n\t Input 10 integral numbers to form a sequence. (Saperated by space)\n\t ");
  for (int i = 0; i < 10; i++) {
    scanf(" %d", &a[i]);
  }
  getchar();

  printf("\n\t This is the greatest number in your sequence: %d ", greatest_element(a, 10));
  printf("\n\t This is average of your sequence: %.2f ", array_average(a, 10));
  printf("\n\t Positive numbers in your sequence:");
  positive_element(a, 10);

  getchar();
  printf("\n\n");
  return 0;
}

int greatest_element(int a[], int length)
{
  int big = a[0];

  for (int i = 1; i < length; i++) {
    big = (big > a[i] ? big : a[i]);
  }

  return big;
}

double array_average(int a[], int length)
{
  int sum = 0;

  for (int i = 0; i < length; i++) {
    sum += a[i];
  }

  // 注意这里将类型强制转化位 double
  return ((double)sum / (double)length);
}

void positive_element(int a[], int length)
{
  for (int i = 0; i < length; i++) {
    if (a[i] > 0) {
      printf(" %d", a[i]);
    }
    else if (a[i] <= 0) {
      continue;
    }
  }
}