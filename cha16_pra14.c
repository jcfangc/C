// 假设 shape 是练习题 13 中声明的结构标记。编写函数用来在 shape 类型结构变量 s 上完成下列操作，并且 s 作为实际参数传递给函数。

#include <stdio.h>
#include <stdlib.h>

#define RECTANGLE 1
#define CIRCLE 0
#define __PI__ 3.1415

typedef struct point {
    int x, y;
} point;

struct shape {
    int shape_kind;
    struct point center;
    union {
        struct {
            int height, width;
        } rectangle;
        struct {
            int radious;
        } circle;
    } u;
} s;

double area(struct shape);
struct shape move(struct shape, int, int);
struct shape size_change_1(struct shape, double);
struct shape size_change_2(struct shape, double);
double my_sqrt(double);

int main(void)
{
    struct shape s1 = { .shape_kind = RECTANGLE, .center.x = 2, .center.y = 3, .u.rectangle.height = 4, .u.rectangle.width = 5 };
    struct shape s2 = { .shape_kind = CIRCLE, .center.x = 2, .center.y = 3, .u.circle.radious = 4 };

    // 测试题目 a
    double area_1, area_2;
    area_1 = area(s1);
    area_2 = area(s2);

    // 测试题目 b
    s1 = move(s1, 6, 7);
    s2 = move(s2, 7, 8);

    // 测试题目 c
    printf("\n\t s1 area: %.2lf", area(s1));
    s1 = size_change_1(s1, 2);
    printf("\n\t s1 area: %.2lf", area(s1));

    printf("\n\t s1 area: %.2lf", area(s1));
    s1 = size_change_2(s1, 0.5);
    printf("\n\t s1 area: %.2lf", area(s1));

    printf("\n\t s2 area: %.2lf", area(s2));
    s2 = size_change_1(s2, 2);
    printf("\n\t s2 area: %.2lf", area(s2));

    printf("\n\t s2 area: %.2lf", area(s2));
    s2 = size_change_2(s2, 0.5);
    printf("\n\t s2 area: %.2lf", area(s2));

    getchar();
    return 0;
}

// (a) 计算 s 的面积。
double area(struct shape s)
{
    double area;

    // 确定形状
    if (s.shape_kind == RECTANGLE) {
        // 矩形面积
        area = (double)(s.u.rectangle.height * s.u.rectangle.width);
    }
    else {
        // 圆面积
        area = (double)(s.u.circle.radious * s.u.circle.radious * __PI__);
    }

    return area;
}

// (b) 将 s 沿 x 轴方向移动 x 个单位，沿 y 轴移动 y 个单位，返回 s 修改后的内容。（x 和 y 是函数的另外两个实际参数。）
struct shape move(struct shape s, int x, int y)
{
    s.center.x += x;
    s.center.y += y;

    return s;
}

// (c) 把 s 缩放 c 倍（c 是 double 类型的值），返回 s 修改后的内容。（c 是函数的另外一个实际参数。）
// 对边长缩放 c 倍。
struct shape size_change_1(struct shape s, double c)
{
    // 确定形状
    if (s.shape_kind == RECTANGLE) {
        s.u.rectangle.height *= c;
        s.u.rectangle.width *= c;
    }
    else {
        s.u.circle.radious *= c;
    }

    return s;
}

// 对面积缩放 c 倍。
struct shape size_change_2(struct shape s, double c)
{
    // 确定形状
    if (s.shape_kind == RECTANGLE) {
        s.u.rectangle.height *= my_sqrt(c);
        s.u.rectangle.width *= my_sqrt(c);
    }
    else {
        s.u.circle.radious *= my_sqrt(c);
    }

    return s;
}

double my_sqrt(double c)
{
    double guess = c, gap = 0.00001;
    double new_guess, big, small;

    do {
        // http://www.wjhsh.net/huashanqingzhu-p-6635691.html
        new_guess = (guess + (c / guess)) / 2;
        if (new_guess > guess) {
            big = new_guess;
            small = guess;
        }
        else {
            big = guess;
            small = new_guess;
        }
        guess = new_guess;
    } while (big - small > gap);

    return new_guess;
}

// 书作者答案：http://knking.com/books/c2/answers/c16.html