// ���� shape ����ϰ�� 13 �������Ľṹ��ǡ���д���������� shape ���ͽṹ���� s ��������в��������� s ��Ϊʵ�ʲ������ݸ�������

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

    // ������Ŀ a
    double area_1, area_2;
    area_1 = area(s1);
    area_2 = area(s2);

    // ������Ŀ b
    s1 = move(s1, 6, 7);
    s2 = move(s2, 7, 8);

    // ������Ŀ c
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

// (a) ���� s �������
double area(struct shape s)
{
    double area;

    // ȷ����״
    if (s.shape_kind == RECTANGLE) {
        // �������
        area = (double)(s.u.rectangle.height * s.u.rectangle.width);
    }
    else {
        // Բ���
        area = (double)(s.u.circle.radious * s.u.circle.radious * __PI__);
    }

    return area;
}

// (b) �� s �� x �᷽���ƶ� x ����λ���� y ���ƶ� y ����λ������ s �޸ĺ�����ݡ���x �� y �Ǻ�������������ʵ�ʲ�������
struct shape move(struct shape s, int x, int y)
{
    s.center.x += x;
    s.center.y += y;

    return s;
}

// (c) �� s ���� c ����c �� double ���͵�ֵ�������� s �޸ĺ�����ݡ���c �Ǻ���������һ��ʵ�ʲ�������
// �Ա߳����� c ����
struct shape size_change_1(struct shape s, double c)
{
    // ȷ����״
    if (s.shape_kind == RECTANGLE) {
        s.u.rectangle.height *= c;
        s.u.rectangle.width *= c;
    }
    else {
        s.u.circle.radious *= c;
    }

    return s;
}

// ��������� c ����
struct shape size_change_2(struct shape s, double c)
{
    // ȷ����״
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

// �����ߴ𰸣�http://knking.com/books/c2/answers/c16.html