// 编写函数计算下面多项式的值：
// 3*x^5 + 2*x^4 - 5*x^3 - x^2 + 7*x - 6
// 编写程序要求用户输入 x 的值，调用该函数计算多项式的值并显示函数返回的值。


#include <stdio.h>

double power_computer(double, int);
double polynomial_computer(double);

int main(void)
{
    double number;

    printf("\n\t Enter a number: ");
    scanf(" %lf", &number);
    getchar();

    printf("\n\t Result of (3*%.2lf^5)+(2*%.2lf^4)-(5*%.2lf^3)-(1*%.2lf^2)+(7*%.2lf)-6 is: %.2lf", number, number, number, number, number, polynomial_computer(number));

    getchar();
    printf("\n\n");
    return 0;
}

double power_computer(double y, int n)
{
    if (n == 1) {
        return y;
    }
    else {
        // 递归
        return (y * power_computer(y, n - 1));
    }
}

double polynomial_computer(double x)
{
    return ((3 * power_computer(x, 5)) + (2 * power_computer(x, 4)) - (5 * power_computer(x, 3)) - (1 * x * x) + (7 * x) - 6);
}