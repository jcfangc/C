// 修改第 6 章的编程题 3，使其包含下列函数：
// void reduce(int numerator, int denominator, int* reduced_numerator, int* reduced_denominator);
// numerator 和 denominator 分别是分数的分子和分母。reduced_numerator 和 reduced_denominator 是指向变量的指针，相应变量中分别存储把分数化为最简形式后的分子和分母。

// 第 6 章 编程题 3：
// 编写程序，要求用户输入一个分数，然后将其约分为最简分式：
// Enter a fraction: 6/12
// In lowest terms: 1/2
// 提示：为了把分数约分为最简分式，首先计算分子和分母的最大公约数，然后分子和分母都除以最大公约数。

#include <stdio.h>

void reduce(int, int, int *, int *);

int main(void)
{
    int numerator, denominator = 0;
    int renum, redeno;

    // 得到分母不为零的分数
    do {
        printf("\n\t Enter a fraction: ");
        scanf(" %d/ %d", &numerator, &denominator);
        getchar(); // '\n'
    } while (denominator == 0);

    // 分子为零则为零
    if (numerator == 0) {
        printf("\n\t In lowest terms: 0 ");
        getchar();
        return 0;
    }

    // 约分
    reduce(numerator, denominator, &renum, &redeno);

    // 返回结果
    printf("\n\t In lowest terms: %d/%d", renum, redeno);

    getchar();
    return 0;
}

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator)
{
    int big, small, gcd;
    big = (numerator >= denominator ? numerator : denominator);
    small = (numerator < denominator ? numerator : denominator);

    for (;;) {
        // 欧几里得算法
        if ((big % small) != 0) {
            int temp = big % small;
            big = small;
            small = temp;
        }
        else {
            gcd = small;
            break;
        }
    }

    // 返回最简分子和分母
    *reduced_numerator = (numerator / gcd);
    *reduced_denominator = (denominator / gcd);
    return;
}