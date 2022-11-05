// 在下列声明中，结构 x 和结构 y 都拥有名为 x 和 y 的成员：
    // struct { int x, y; } x;
    // struct { int x, y; } y;
// 单独出现时，这两个声明是否合法？两个声明是否可以同时出现在程序中呢？验证你的答案。
#include <stdio.h>

int main(void)
{
    struct { int x, y; } x;
    // struct { int x, y; } y;

    x.x = 1;
    x.y = 2;
    // y.x = 3;
    // y.y = 4;

    printf("\n\t %d", x.x);
    printf("\n\t %d", x.y);
    // printf("\n\t %d", y.x);
    // printf("\n\t %d", y.y);

    getchar();
    return 0;
}