// 假设下列声明都有效：
    // struct point { int x, y; };
    // struct rectangle { struct point upper_left, lower_right; };
    // struct rectangle *p;
// 假设希望 p 指向一个 rectangle 结构，此结构的左上角位于 (10, 25) 的位置上，而右下角位于 (20, 15) 的位置上。请编写一系列语句来分配这样一个结构，并且像说明的那样进行初始化。

#include <stdio.h>
#include <stdlib.h>

struct point { int x, y; };
struct rectangle { struct point upper_left, lower_right; };
struct rectangle *p;

int main(void)
{
    // 让 p “指向” 一个 rectangle 结构
    p = malloc(sizeof(struct rectangle));
    // 初始化
    p->upper_left.x = 10;
    p->upper_left.y = 25;
    p->lower_right.x = 20;
    p->lower_right.y = 15;

    free(p);
    getchar();
    return 0;
}