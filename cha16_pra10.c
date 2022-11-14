// 下列结构用来存储图形屏幕上的对象信息。
    // struct point { int x, y };
    // struct rectangle { struct point upper_left, lower_right };
// 结构 point 用来存储屏幕上点 x 和 y 的坐标，结构 rectangle 用来存储矩形的左上和右下的坐标点。编写函数，要求可以在 rectangle 结构变量 r 上执行下列操作，且 r 作为实际参数传递。

#include <stdio.h>
#include <stdbool.h>

typedef struct point {
    int x, y;
} point;

typedef struct rectangle {
    struct point upper_left, lower_right;
} rectangle;

int rec_area(struct rectangle);
struct point rec_center(struct rectangle);
struct rectangle rec_move(rectangle, int, int);
bool point_in_rec(struct point, struct rectangle);

int main(void)
{
    struct point center, p = { .x = 17, .y = 17 };
    struct rectangle r = { .upper_left.x = 5, .upper_left.y = 5, .lower_right.x = 10, .lower_right.y = 10 };

    center = rec_center(r);
    printf("\n\t Center of r is: (%d,%d)", center.x, center.y);
    printf("\n\t Area of r is: %d", rec_area(r));

    if (point_in_rec(p, r)) {
        printf("\n\t point p(%d,%d) is in rectangle r((%d,%d),(%d,%d)).",
            p.x, p.y, r.upper_left.x, r.upper_left.y, r.lower_right.x, r.lower_right.y);
    }
    else if (point_in_rec(center, r)) {
        printf("\n\t point center(%d,%d) is in rectangle r((%d,%d),(%d,%d)).",
            center.x, center.y, r.upper_left.x, r.upper_left.y, r.lower_right.x, r.lower_right.y);
    }
    r = rec_move(r, 10, 10);
    if (point_in_rec(p, r)) {
        printf("\n\t point p(%d,%d) is in rectangle r((%d,%d),(%d,%d)).",
            p.x, p.y, r.upper_left.x, r.upper_left.y, r.lower_right.x, r.lower_right.y);
    }
    else if (point_in_rec(center, r)) {
        printf("\n\t point center(%d,%d) is in rectangle r((%d,%d),(%d,%d)).",
            center.x, center.y, r.upper_left.x, r.upper_left.y, r.lower_right.x, r.lower_right.y);
    }

    getchar();
    return 0;
}

// (a) 计算 r 的面积。
int rec_area(struct rectangle r)
{
    return ((r.lower_right.x - r.upper_left.x) * (r.lower_right.y - r.upper_left.y));
}

// (b) 计算 r 的中心，并且把此中心作为 point 值返回。如果中心的 x 或 y 坐标不是整数，在 point 结构中存储截断后的值。
struct point rec_center(struct rectangle r)
{
    struct point p;

    p.x = ((r.lower_right.x + r.upper_left.x) / 2);
    p.y = ((r.lower_right.y + r.upper_left.y) / 2);

    return p;
}

// (c) 将 r 沿 x 周方向移动 x 个单位，沿 y 轴移动 y 个单位，返回 r 修改后的内容。（x 和 y 是函数的另外两个实际参数。）
struct rectangle rec_move(rectangle r, int x, int y)
{
    r.lower_right.x += x;
    r.lower_right.y += y;
    r.upper_left.x += x;
    r.upper_left.y += y;

    return r;
}

// (d) 确定点 p 是否位于 r 内，返回 ture 或者 false。（p 是 struct point 类型的另外一个实际参数。）
bool point_in_rec(struct point p, struct rectangle r)
{
    // 屏幕左上角为原点，右下角为屏幕中的最大点
    if (((p.x < r.lower_right.x) && (p.y < r.lower_right.y)) && ((p.x > r.upper_left.x) && (p.y > r.upper_left.y))) {
        return true;
    }
    return false;
}