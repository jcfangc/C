// 修改第 5 章的编程题 5，用函数计算所得税的金额。在输入须纳税所得后，函数返回税金。
// 第 5 章的编程题 5：
// 在美国的某一个州，单数居民需要负担下面表格列出的所得税。

    // 收入（美元）                            税金
    
    // 未超过750                               收入的1%
    // 750~2250                                7.50美元加上超出750美元部分的2%
    // 2250~3750                               37.50美元加上超出2250美元部分的3%
    // 3750~5250                               82.50美元加上超出3750美元部分的4%
    // 5250~7000                               142.50美元加上超出5250美元部分的5%
    // 超过7000                                230.00美元加上超出7000美元部分的6%

// 编写一个程序，要求用户输入须纳税的收入，然后显示税金。


#include <stdio.h>

double tax_computer(double);

int main(void)
{
  double income;

  for (;;) {
    printf("\n\t Input your income: (0 to exit) ");
    scanf(" %lf", &income);
    getchar();
    
    if (income == 0.0) {
      break;
    }

    printf("\t Your tax should be: %.2f ", tax_computer(income));
    printf("\n");
  }

  printf("\n\n");
  return 0;
}

double tax_computer(double money)
{
  double tax;

  if (money <= 750) {
    tax = money * 0.01;
  }
  else if (money > 750 && money <= 2250) {
    tax = (7.5 + ((money - 750) * 0.02));
  }
  else if (money > 2250 && money <= 3750) {
    tax = (37.5 + ((money - 2250) * 0.03));
  }
  else if (money > 3750 && money <= 5250) {
    tax = (82.5 + ((money - 3750) * 0.04));
  }
  else if (money > 5250 && money <= 7000) {
    tax = (142.5 + ((money - 5250) * 0.05));
  }
  else if (money > 7000) {
    tax = (230 + ((money - 7000) * 0.06));
  }

  return tax;
}