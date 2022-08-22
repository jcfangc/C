// double inner_ product (double a[], double b[], int n);
// 函数返回 a[0] * b[0] + a[1] * b[1] + ... + a[n-1] * b[n-1]。
#include <stdio.h>

#define N 30

double inner_product(double[], double[], int);

int main(void)
{
  double sequence_1[N] = { 0 }, sequence_2[N] = { 0 };
  int len_1 = 0;
  int len_2 = 0;
  char ch;

  printf("\n\t Input first sequence of number: ");
  for (;;) {
    // 注意这里不能用 " %lf" 而是 "%lf" 防止 if 中的 getchar 误录入 下面同理
    scanf("%lf", &sequence_1[len_1++]);
    if ((ch = getchar()) == '\n') {
      break;
    }
  }

  printf("\n\t Input second sequence of number: ");
  for (;;) {
    scanf("%lf", &sequence_2[len_2++]);
    if ((ch = getchar()) == '\n') {
      break;
    }
  }

  // 根据定义，inner_product 的计算受限于长度更短的那个数列
  int len = (len_1 <= len_2 ? len_1 : len_2);

  printf("\n\t Sum of the products is %.2f ", inner_product(sequence_1, sequence_2, len));

  getchar();
  printf("\n\n");
  return 0;
}

double inner_product(double fact_1[], double fact_2[], int length)
{
  double product;
  double sum = 0.0;

  for (int i = 0; i < length; i++) {
    product = fact_1[i] * fact_2[i];
    sum += product;
  }

  return sum;
}