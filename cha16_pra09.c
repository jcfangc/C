// 编写下列函数。（color 结构的定义见练习题 8。）
    // struct color {
    //     int red;
    //     int green;       /* 练习题 8 中 color 的定义 */
    //     int blue;
    // };

#include <stdio.h>
#include <stdbool.h>

typedef struct color {
    int red;
    int green;
    int blue;
} color;

struct color make_color(int, int, int);
int getRed(struct color);
bool equal_color(struct color, color);
struct color brighter(color);
struct color darker(color);

int main(void)
{
    struct color c = { .red = 2, .green = 233, .blue = 123 };
    color c1 = { .red = 0, .green = 0, .blue = 0 };
    color c2 = make_color(0, 0, 0);

    printf("\n\t red value of c: %d", getRed(c));
    printf("\n\t red value of c1: %d", getRed(c1));
    printf("\n\t red value of c2: %d", getRed(c2));

    if (equal_color(c1, c2)) {
        printf("\n\t c1, c2 are same. ");
    }
    if (!equal_color(c, c2)) {
        printf("\n\t c, c2 are NOT same. ");
    }

    printf("\n\t c: red:%d green:%d blue:%d ", c.red, c.green, c.blue);
    c = brighter(c);
    printf("\n\t brighter c: red:%d green:%d blue:%d ", c.red, c.green, c.blue);

    printf("\n\t c1: red:%d green:%d blue:%d ", c1.red, c1.green, c1.blue);
    c1 = brighter(c1);
    printf("\n\t brighter c1: red:%d green:%d blue:%d ", c1.red, c1.green, c1.blue);

    printf("\n\t c: red:%d green:%d blue:%d ", c.red, c.green, c.blue);
    c = darker(c);
    printf("\n\t darker c: red:%d green:%d blue:%d ", c.red, c.green, c.blue);

    printf("\n\t c1: red:%d green:%d blue:%d ", c1.red, c1.green, c1.blue);
    c1 = darker(c1);
    printf("\n\t darker c1: red:%d green:%d blue:%d ", c1.red, c1.green, c1.blue);

    getchar();
    return 0;
}

// (a) struct color make_color(int red, int green, int blue);
    // 函数返回一个指定的 red，green 和 bule 值的 color 结构。如果参数小于 0，把结构的对应成员置为 0。如果参数大于 255，把结构的对应成员置为 255。
struct color make_color(int red, int green, int blue)
{
    struct color c;

    c.red = red;
    c.green = green;
    c.blue = blue;

    return c;
}

// (b) int getRed(struct color c);
    // 函数返回 c 的 red 成员的值。
int getRed(struct color c)
{
    return c.red;
}

// (c) bool equal_color(struct color color1, struct color color2);
    // 如果 color1 和 color2 的对应成员相等，函数返回 ture。
bool equal_color(struct color color1, color color2)
{
    if ((color1.red == color2.red) && (color1.green == color2.green) && (color1.blue == color2.blue)) {
        return true;
    }
    return false;
}

// (d) struct color brighter(struct color c);
    // 函数返回一个表示颜色 c 的更亮版本的 color 结构。该结构等同于 c，但每个成员都除以了 0.7（把结果截断为整数）。但是，有三种特殊情形：
struct color brighter(color c)
{
    // （1）如果 c 的所有成员都为 0，函数返回一个所有成员的值都为 3 的颜色；
    if ((c.red == 0) && (c.green == 0) && (c.blue == 0)) {
        c.red = 3;
        c.green = 3;
        c.blue = 3;

        return c;
    }

    // （2）如果 c 的任意成员比 0 大比 3 小，那么在除以 0.7 之前将其置为 3；
    if ((c.red > 0) && (c.red < 3)) {
        c.red = 3;
    }
    else if ((c.green > 0) && (c.green < 3)) {
        c.green = 3;
    }
    else if ((c.blue > 0) && (c.blue < 3)) {
        c.blue = 3;
    }

    c.red /= 0.7;
    c.green /= 0.7;
    c.blue /= 0.7;

    // （3）如果除以 0.7 之后得到了超过 255 的成员，将其置为 255。
    if (c.red > 255) {
        c.red = 255;
    }
    if (c.green > 255) {
        c.green = 255;
    }
    if (c.blue > 255) {
        c.blue = 255;
    }

    return c;
}

// (e) struct color darker(struct color c);
    // 函数返回一个表示颜色 c 的更暗版本的 color 结构。该结构等同于 c，但每个成员都乘以了 0.7（把结果截断为整数）。
struct color darker(color c)
{
    c.red *= 0.7;
    c.green *= 0.7;
    c.blue *= 0.7;

    return c;
}