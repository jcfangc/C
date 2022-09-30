// 如果换一种方式计算 x ^ n，9.6 节的 power 函数速度可以更快。我们注意到，如果 n 是 2 的幂，则可以通过自乘的方法计算 x ^ n。例如，x ^ 4 是 x ^ 2 的平方，所以 x ^ 4 可以用两次乘法计算，而不需要三次乘法。这种方法甚至可以用于 n 不是 2 的幂的情况。如果 n 是偶数，可以用公式 x ^ n = (x ^ (n / 2)) ^ 2；如果 n 是奇数，则 x ^ n = x * x ^ (n - 1)。编写 x ^ n 的递归函数（递归在 n = 0 时结束，此时函数返回 1）。为了测试该函数，写一个程序要求用户输入 x 和 n 的值，调用 power 计算 x ^ n，然后显示函数返回值。


#include <stdio.h>

double power(double, int);

int main(void)
{
    double number;
    int times;

    printf("\n\t Enter a number: ");
    scanf(" %lf", &number);
    getchar();

    // 函数中的递归算法无法计算小于零的次数，所以要确保次数大于零
    do {
        printf("\n\t Enter the time of the power: ");
        scanf(" %d", &times);
        getchar();
    } while (times < 0);

    printf("\n\t Result: %.2f ", power(number, times));

    getchar();
    printf("\n\n");
    return 0;
}

double power(double num, int power_times)
{
    if (power_times == 0) {
        return ((double)1);
    }
    else {
        if ((power_times % 2) != 0) {
            return (num * power(num, power_times - 1));
        }
        else if ((power_times % 2) == 0) {
            power_times /= 2;
            return (power(num, power_times) * power(num, power_times));
        }
    }
}