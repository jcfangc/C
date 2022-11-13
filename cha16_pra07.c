// 假定 fraction 结构包含两个成员：numerator 和 denominator（都是 int 类型）。编写函数完成下列分数运算。
// 分数 f，f1 和 f2 都是 struct fraction 类型的参数。每个函数返回一个 struct fraction 类型的值。
// (b) - (e) 中函数返回的分式应为最简形式。提示：可以使用 (a) 中的函数辅助编写 (b) - (e) 中的函数。

#include <stdio.h>
#include <stdlib.h>

typedef struct fraction {
    int numerator;
    int denominator;
} fraction;

struct fraction spfy_frac(fraction);
struct fraction add_frac(fraction, fraction);
struct fraction minus_frac(fraction, fraction);
struct fraction mpfy_frac(fraction, fraction);
struct fraction divid_frac(fraction, fraction);

int main(void)
{
    struct fraction f;
    fraction a = { .denominator = 135, .numerator = 930 };
    fraction b = { .denominator = 930, .numerator = 930 };
    fraction c = { .denominator = 126, .numerator = 930 };
    fraction d = { .denominator = 126, .numerator = 234 };

    printf("\n\t %d/%d is simplified as ", a.numerator, a.denominator);
    a = spfy_frac(a);
    printf("%d/%d", a.numerator, a.denominator);

    printf("\n\t %d/%d is simplified as ", b.numerator, b.denominator);
    b = spfy_frac(b);
    printf("%d/%d", b.numerator, b.denominator);

    f = add_frac(c, d);
    printf("\n\t %d/%d + %d/%d = %d/%d", \
        c.numerator, c.denominator, d.numerator, d.denominator, f.numerator, f.denominator);

    f = minus_frac(c, a);
    printf("\n\t %d/%d - %d/%d = %d/%d", \
        c.numerator, c.denominator, a.numerator, a.denominator, f.numerator, f.denominator);

    f = mpfy_frac(c, a);
    printf("\n\t %d/%d * %d/%d = %d/%d", \
        c.numerator, c.denominator, a.numerator, a.denominator, f.numerator, f.denominator);

    f = divid_frac(c, a);
    printf("\n\t %d/%d / %d/%d = %d/%d", \
        c.numerator, c.denominator, a.numerator, a.denominator, f.numerator, f.denominator);

    getchar();
    return 0;
}

// (a) 把分数 f 化为最简式。提示：为了把分数华为最简形式，首先计算分子和分母的最大公约数（GCD），然后把分子和分母都除以该最大公约数

struct fraction spfy_frac(fraction f)
{
    /* 确认分母不为零 */
    if (f.denominator == 0) {
        printf("\n\t ERROR: denominator == 0 ");
        getchar();
        exit(EXIT_FAILURE);
    }

    /* 阿基米德算法求最大公约数 */
    int large, small, gcd;

    if (f.denominator > f.numerator) {
        large = f.denominator;
        small = f.numerator;
    }
    else if (f.denominator < f.numerator) {
        large = f.numerator;
        small = f.denominator;
    }
    else {
        f.denominator = 1;
        f.numerator = 1;
        return f;
    }

    while (large % small != 0) {
        gcd = large % small;
        large = small;
        small = gcd;
    }

    f.denominator /= gcd;
    f.numerator /= gcd;

    return f;
}

// (b) 把分数 f1 和 f2 相加。

struct fraction add_frac(fraction f1, fraction f2)
{
    /* 确认分母不为零 */
    if ((f1.denominator == 0) || (f2.denominator == 0)) {
        printf("\n\t ERROR: denominator == 0 ");
        getchar();
        exit(EXIT_FAILURE);
    }

    fraction f;

    f1 = spfy_frac(f1);
    f2 = spfy_frac(f2);

    if (f1.denominator == f2.denominator) {
        f.numerator = f1.numerator + f2.numerator;
    }
    else if (f1.denominator != f2.denominator) {
        f.denominator = f1.denominator * f2.denominator;
        f.numerator = (f1.numerator * f2.denominator) + (f2.numerator * f1.denominator);
    }

    return spfy_frac(f);
}

// (c) 从分数 f1 中减去分数 f2。

struct fraction minus_frac(fraction f1, fraction f2)
{
    /* 确认分母不为零 */
    if ((f1.denominator == 0) || (f2.denominator == 0)) {
        printf("\n\t ERROR: denominator == 0 ");
        getchar();
        exit(EXIT_FAILURE);
    }

    fraction f;

    f1 = spfy_frac(f1);
    f2 = spfy_frac(f2);

    if (f1.denominator == f2.denominator) {
        f.numerator = f1.numerator - f2.numerator;
    }
    else if (f1.denominator != f2.denominator) {
        f.denominator = f1.denominator * f2.denominator;
        f.numerator = (f1.numerator * f2.denominator) - (f2.numerator * f1.denominator);
    }

    return spfy_frac(f);
}

// (d) 把分数 f1 和 f2 相乘。

struct fraction mpfy_frac(fraction f1, fraction f2)
{
    /* 确认分母不为零 */
    if ((f1.denominator == 0) || (f2.denominator == 0)) {
        printf("\n\t ERROR: denominator == 0 ");
        getchar();
        exit(EXIT_FAILURE);
    }

    fraction f;

    f1 = spfy_frac(f1);
    f2 = spfy_frac(f2);

    f.denominator = f1.denominator * f2.denominator;
    f.numerator = f1.numerator * f2.numerator;

    return spfy_frac(f);
}

// (e) 用分数 f1 除以分数 f2。

struct fraction divid_frac(fraction f1, fraction f2)
{
    /* 确认分母不为零 */
    if ((f1.denominator == 0) || (f2.denominator == 0) || (f2.numerator == 0)) {
        printf("\n\t ERROR: denominator == 0 ");
        getchar();
        exit(EXIT_FAILURE);
    }

    f1 = spfy_frac(f1);
    f2 = spfy_frac(f2);

    fraction f;

    if (f2.denominator == f2.numerator) {
        return f1;
    }
    else if (f2.denominator != f2.numerator) {
        f.denominator = f1.denominator * f2.numerator;
        f.numerator = f1.numerator * f2.denominator;
    }

    return spfy_frac(f);
}