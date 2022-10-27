// 编写第 9 章练习题 13 中描述的 evaluate_position 函数，使用指针算数运算而不是取下标来访问数组元素。要求使用单层循环而不是嵌套循环。

// 其实思路和 17 题是很相似的，完整程序如下，改编自 9 章 练习题 13：

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define BOARD_LEN 8

/* 和本题答案相关的函数 */
int evaluate_position(char[][BOARD_LEN]);
void evaluation_check(char[][BOARD_LEN]);

int main(void)
{
    char chess_board[BOARD_LEN][BOARD_LEN] = { {'\0'} };
    int map_check[BOARD_LEN][BOARD_LEN] = { {0} };
    const char chessman[2][16] = {
      { 'K', 'Q', 'R', 'R', 'B', 'B', 'N', 'N', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
      { 'k', 'q', 'r', 'r', 'b', 'b', 'n', 'n', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' }
    };
    char picked_chessman;
    int existence[BOARD_LEN][BOARD_LEN] = { {0} };

    srand((unsigned)time(NULL));

    // 棋盘初始化
    for (int i = 0; i < BOARD_LEN; i++) {
        for (int j = 0; j < BOARD_LEN; j++) {
            chess_board[i][j] = '*';
        }
    }
    // 生成随机棋盘
    // 挑选棋子
    for (int color = 0; color < 2; color++) {
        for (int role = 0; role < 16; role++) {
            picked_chessman = chessman[color][role];
            // 挑选棋盘坐标，放置棋子
            for (;;) {
                int row = rand() % BOARD_LEN;
                int col = rand() % BOARD_LEN;
                if (map_check[row][col] != 0) {
                    continue;
                }
                else {
                    map_check[row][col] = 1;
                    chess_board[row][col] = picked_chessman;
                    break;
                }
            }
        }
    }

    // 棋子是否被吃掉了
    for (int i = 0; i < BOARD_LEN; i++) {
        for (int j = 0; j < BOARD_LEN; j++) {
            existence[i][j] = rand() % 2;
            if (existence[i][j] == 0) {
                chess_board[i][j] = '*';
            }
        }
    }

    // 打印棋盘
    for (int i = 0; i < BOARD_LEN; i++) {
        printf("\n\t");
        for (int j = 0; j < BOARD_LEN; j++) {
            printf("%3c", chess_board[i][j]);
        }
    }

    // 计算
    printf("\n\n\t Advantage: %d ", evaluate_position(chess_board));

    printf("\n");
    evaluation_check(chess_board);

    getchar();
    return 0;
}

int evaluate_position(char (*arr)[BOARD_LEN])
{
    // 求和
    int white_sum = 0;
    int black_sum = 0;
    char(*row)[BOARD_LEN] = arr, (*element) = (*row);

    // 
    for (; ((*row) + (element - (*row))) < ((*arr) + (BOARD_LEN * BOARD_LEN)); element++) {
        if ((element - (*row)) != 0 && ((element - (*row)) % BOARD_LEN) == 0) {
            element = (*++row);
            if (row == arr + BOARD_LEN) { /* 数组的最后一行在 arr + BOARD_LEN - 1 */
                break;
            }
        }
        switch (*((*row) + (element - (*row)))) {
        case 'K':
        case 'k': continue;
        case 'Q': white_sum += 9; break;
        case 'q': black_sum += 9; break;
        case 'R': white_sum += 5; break;
        case 'r': black_sum += 5; break;
        case 'B': white_sum += 3; break;
        case 'b': black_sum += 3; break;
        case 'N': white_sum += 3; break;
        case 'n': black_sum += 3; break;
        case 'P': white_sum += 1; break;
        case 'p': black_sum += 1; break;
        default: continue;
        }
    }

    // 计算值
    int advantage = (white_sum - black_sum);
    return advantage;
}

void evaluation_check(char arr[][BOARD_LEN])
{
    int chessman_number[2][6] = { {0} }; // K // Q // R // B // N // P
    char chessmen[2][6] = {
      {'K','Q','R','B','N','P'},
      {'k','q','r','b','n','p'}
    };

    for (int i = 0; i < BOARD_LEN; i++) {
        for (int j = 0; j < BOARD_LEN; j++) {
            switch (arr[i][j]) {
            case 'K': chessman_number[0][0] += 1; break;
            case 'k': chessman_number[1][0] += 1; break;
            case 'Q': chessman_number[0][1] += 1; break;
            case 'q': chessman_number[1][1] += 1; break;
            case 'R': chessman_number[0][2] += 1; break;
            case 'r': chessman_number[1][2] += 1; break;
            case 'B': chessman_number[0][3] += 1; break;
            case 'b': chessman_number[1][3] += 1; break;
            case 'N': chessman_number[0][4] += 1; break;
            case 'n': chessman_number[1][4] += 1; break;
            case 'P': chessman_number[0][5] += 1; break;
            case 'p': chessman_number[1][5] += 1; break;
            default: continue;
            }
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 6; j++) {
            switch (chessman_number[i][j]) {
            case 0: continue;
            default:
                printf("\n\t %c: %d ", chessmen[i][j], chessman_number[i][j]);
            }
        }
    }
}