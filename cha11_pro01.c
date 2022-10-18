// 修改第 2 章的编程题 7，使其包含下列函数：
// void pay_amount(int dollars, int* twenties, int* tens, int* fives, int* ones);
// 函数需要确定：为支付参数 dollars 表示的付款金额，所需 20 美元、10 美元、5 美元和 1 美元的最小数目。twenties 参数所指向的变量存储所需 20 美元的数目，tens、fives 和 ones 参数类似。

// 第 2 章 编程题 7：
// 编写一个程序，要求用户输入一个没进数量，然后显示出如何用最少的 20 美元、10 美元、5 美元和 1 美元来付款：

// Enter a dollar amount: 93
// $20 bills: 4
// $10 bills: 1
// $5 bills: 0
// $1 bills: 3

// 提示：将付款金额除以 20， 确定 20 美元的数量，然后从付款金额中减去 20 美元的总金额。对其他面值的钞票重复这一操作。确保在程序中始终使用整数值，不要用浮点数。

#include <stdio.h>

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);

int main(void)
{
    int dollars;
    int twenties, tens, fives, ones;

    printf("\n\t Enter a amount of dollar in integer: ");
    scanf(" %d", &dollars);
    getchar();

    pay_amount(dollars, &twenties, &tens, &fives, &ones);

    getchar();
    return 0;
}

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones)
{
    *twenties = dollars / 20;
    *tens = (dollars - (*twenties * 20)) / 10;
    *fives = (dollars - (*twenties * 20) - (*tens * 10)) / 5;
    *ones = (dollars - (*twenties * 20) - (*tens * 10)) % 5;

    printf("\n\t $20: %d ", *twenties);
    printf("\n\t $10: %d ", *tens);
    printf("\n\t $5: %d ", *fives);
    printf("\n\t $1: %d ", *ones);

    return;
}