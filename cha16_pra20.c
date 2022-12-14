// 假定 direction 变量声明如下：
// enum {NORTH, SOUTH, EAST, WEST} direction;
// 设 x 和 y 为 int 类型的变量。编写 switch 语句测试 direction 的值，如果值为 EAST 就使 x 增 1，如果值为 WEST 就使 x 减 1，如果值为 south 就使 y 增 1，如果值为 NORTH 就使 y 减 1。

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    enum { NORTH, SOUTH, EAST, WEST } direction;
    int x = 0, y = 0, step;

    printf("\n\t Enter number of steps: ");
    scanf(" %d", &step);
    getchar(); // '\n'

    srand((unsigned)time(NULL));
    for (int i = 0; i < step; i++) {
        // 决定方向
        direction = rand() % (WEST + 1);
        // 根据方向进行输出
        switch (direction) {
            case NORTH:
                y--;
                printf("\n\t Gone north\n\t (%d,%d)", x, y);
                break;
            case SOUTH:
                y++;
                printf("\n\t Gone south\n\t (%d,%d)", x, y);
                break;
            case EAST:
                x++;
                printf("\n\t Gone east\n\t (%d,%d)", x, y);
                break;
            case WEST:
                x--;
                printf("\n\t Gone west\n\t (%d,%d)", x, y);
                break;
            default:
                printf("\n\t ERROR");  break;
        }
    }

    getchar();
    return 0;
}