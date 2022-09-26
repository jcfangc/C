// 修改第 8 章编程题 9，使其包含下列函数：
// void generate_ random walk(char walk[10][10]);
// void print_ array (char walk[10][10]);
// main 函数首先调用 generate_random_walk，该函数把所有数组元素都初始化为字符 ‘.’，然后 将其中一些字符替换为 A 到 Z 的字母，详见原题的描述。接着，main 函数调用 print_ array 函数来显示数组。


// 第 8 章编程题 9：
// 编写程序，生成一种贯穿 10 x 10 字符数组（初始时全为字符 ‘.’ ）的 “随机步法”。程序必须随机地从一个元素 “走到” 另一个元素，每次都向上、向下、向左或向右移动一个元素位置。已访问过的元素按访问顺序用字母 A 到 Z 进行标记。
// 提示：利用 srand 函数和 rand 函数（见程序deal.c）然后查看此数除以4的余数。余数一共有 4 中可能的值（0、1、2 和 3）指示下一次移动的方向。在执行移动之前，需要检查两项内容：一是不能走到数组外面，二是不能走到已的位置。只要有一个条件不满足就得尝试换一个方向移动。如果4个方向都堵住了，程序就必须终止了。


#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void generate_random_walk(char[][10]);
void print_array(char[][10]);

int main(void)
{
    char walking_map[10][10];

    generate_random_walk(walking_map);
    print_array(walking_map);

    getchar();
    printf("\n\n");
    return 0;
}

void generate_random_walk(char walk[10][10])
{
    // 所需材料
    /* 横纵坐标 */
    int row, column;
    // 步数仓库，装载行走的 26 步
    const char footprints[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
    int footprint = 0;
    /* 定位器，确认走过的路径，禁止重复路过 */
    int navigation[10][10] = { { 0 } };
    // 行进方向白名单，用于记录可以行进的方向，当所有行进方向都无法前进，输出结果
    int direction_white_list[4] = { 1,1,1,1 }, direction; // ↑ → ↓ ←


    // 地图初始化
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            walk[i][j] = '*';
        }
    }

    // 起点坐标选择
    srand((unsigned)time(NULL));
    row = rand() % 10;
    column = rand() % 10;

    // 标记起点
    walk[row][column] = footprints[footprint++];
    navigation[row][column] = 1;


    for (; footprint < 26;) {
        // 四方检测，寻找可行进方向
        // 上方检测
        if (row >= 1) {
            if (navigation[row - 1][column] == 1) {
                // navigation 数组中位置为 1 说明该位置已经被占据了
                direction_white_list[0] = 0;
            }
        }
        else if (row < 1) {
            // 上方就是地图之外了 没有意义
            direction_white_list[0] = 0;
        }

        // 右方检测
        if (column < 9) {
            if (navigation[row][column + 1] == 1) {
                direction_white_list[1] = 0;
            }
        }
        else if (column >= 9) {
            direction_white_list[1] = 0;
        }

        // 下方检测
        if (row < 9) {
            if (navigation[row + 1][column] == 1) {
                direction_white_list[2] = 0;
            }
        }
        else if (row >= 9) {
            direction_white_list[2] = 0;
        }

        // 左方检测
        if (column >= 1) {
            if (navigation[row][column - 1] == 1) {
                direction_white_list[3] = 0;
            }
        }
        else if (column < 1) {
            direction_white_list[3] = 0;
        }

        // 检测结果
        for (int i = 0; i < 4; i++) {
            if (direction_white_list[i] == 0) {
                if (i == 3) {
                    // 已经无法行进
                    // 退出
                    return;
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
            walk[row][column] = footprints[footprint++];
            navigation[row][column] = 1;
            break;
        case 1: // 向右移动一个单位
            column += 1;
            walk[row][column] = footprints[footprint++];
            navigation[row][column] = 1;
            break;
        case 2: // 向下移动一个单位
            row += 1;
            walk[row][column] = footprints[footprint++];
            navigation[row][column] = 1;
            break;
        case 3: // 向左移动一个单位
            column -= 1;
            walk[row][column] = footprints[footprint++];
            navigation[row][column] = 1;
            break;
        default: printf("\n\t 行进错误。"); break;
        }
    }
}

void print_array(char arr[10][10])
{
    // 打印地图
    for (int j = 0; j < 10; j++) {
        printf("\n\t ");
        for (int k = 0; k < 10; k++) {
            printf("%3c", arr[j][k]);
        }
    }
}
