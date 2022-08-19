// 这个程序用 26 个字母在一定范围内生成轨迹

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    // 所需材料
    /* 10 * 10 地图一张 */
    char map[10][10];
    /* 横纵坐标 */
    int row, column;
    // 步数仓库，装载行走的 26 步
    char footprints[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
    int footprint = 0;
    /* 定位器，确认走过的路径，禁止重复路过 */
    int navigation[10][10] = { { 0 } };
    // 行进方向白名单，用于记录可以行进的方向，当所有行进方向都无法前进，输出结果
    int direction_white_list[4] = { 1,1,1,1 }, direction; // ↑ → ↓ ←


    // 地图初始化
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            map[i][j] = '*';
        }
    }

    // 起点坐标选择
    srand((unsigned)time(NULL));
    row = rand() % 10;
    column = rand() % 10;

    // 标记起点
    map[row][column] = footprints[footprint++];
    navigation[row][column] = 1;

    for (; footprint < 26;) {
        // 四方检测，寻找可行进方向
        // 上方检测
        if (navigation[row - 1][column] == 1 || (row - 1) < 0) {
            direction_white_list[0] = 0;
        }
        // 右方检测
        if (navigation[row][column + 1] == 1 || (column + 1) > 9) {
            direction_white_list[1] = 0;
        }
        // 下方检测
        if (navigation[row + 1][column] == 1 || (row + 1) > 9) {
            direction_white_list[2] = 0;
        }
        // 左方检测
        if (navigation[row][column - 1] == 1 || (column - 1) < 0) {
            direction_white_list[3] = 0;
        }
        // 检测结果
        for (int i = 0; i < 4; i++) {
            if (direction_white_list[i] == 0) {
                if (i == 3) {
                    // 已经无法行进，打印地图
                    for (int j = 0; j < 10; j++) {
                        printf("\n\t ");
                        for (int k = 0; k < 10; k++) {
                            printf("%3c", map[j][k]);
                        }
                    }
                    // 退出
                    getchar();
                    printf("\n\n");
                    return 0;
                }
                continue;
            }
            else if (direction_white_list[i] != 0) {
                break;
            }
        }

        // 通过上方程序说明仍然有可行的行进方向，接下来开始行进
        // 在可行方向中任意选择一个（先选择一个方向，然后判断是否在可行方向中）
        while (1) {
            direction = rand() % 4;
            if (direction_white_list[direction] != 0) {
                break;
            }
        }

        // 白名单初始化
        for (int i = 0; i < 4; i++) {
            direction_white_list[i] = 1;
        }

        // 行进
        switch (direction) {
        case 0: // 向上移动一个单位
            row -= 1;
            map[row][column] = footprints[footprint++];
            navigation[row][column] = 1;
            break;
        case 1: // 向右移动一个单位
            column += 1;
            map[row][column] = footprints[footprint++];
            navigation[row][column] = 1;
            break;
        case 2: // 向下移动一个单位
            row += 1;
            map[row][column] = footprints[footprint++];
            navigation[row][column] = 1;
            break;
        case 3: // 向左移动一个单位
            column -= 1;
            map[row][column] = footprints[footprint++];
            navigation[row][column] = 1;
            break;
        default: printf("\n\t 行进错误。"); break;
        }
    }

    // 打印地图
    for (int j = 0; j < 10; j++) {
        printf("\n\t ");
        for (int k = 0; k < 10; k++) {
            printf("%3c", map[j][k]);
        }
    }

    getchar();
    printf("\n\n");
    return 0;
}