// 这个程序可以形成一个幻方
// 这里有相关的解释和介绍来说明怎么做一个幻方
// 把幻方存储在一个二维数组中。起始时把数 1 放在 0 行的中间，剩下的数 2, 3, .... n 依次向上移动一行并向右移动一列。当可能越过数组边界时需要 “绕回” 到数组的另一端。例如，如果需要把下一个数放到 n - 1 行，我们就将其存储到 n - 1 行（最后行）；如果需要把下一个数放到 n 列，我们就将其存储到 0 列。如果某个特定的数组元素已被占用，那就把该数存储在前一个数的正下方。如果你的编译器支持变长数组，声明数组有 n 行 n 列，否则声明数组有 99 行 99 列。
#include <stdio.h>

#define N 99

int main(void)
{
    int size;
    int magic_square[N][N] = { {0} };
    int square_check[N][N] = { {0} };
    int row = 0, col;
    int predicted_row, predicted_col;

    printf("\n\t This programme creates a magic squares of a specified size. \n\t The size must be an odd number between 1 and 99. ");
    printf("\n\t Enter size of magic square: ");
    scanf(" %d", &size);
    getchar();

    while (1) {
        if ((size % 2) == 0) {
            printf("\n\t The size must be an ODD number between 1 and 99. ");
            printf("\n\t Enter size of magic square: ");
            scanf(" %d", &size);
            getchar();
        }
        else {
            // 因为序号从 0 开始，减一才可以得到中间的数
            col = (size - 1) / 2;
            for (int i = 1; i <= (size * size); i++) {
                // 找到第一行中间，放下数字。
                magic_square[row][col] = i;
                square_check[row][col] = 1;
                // 行列各自单独判断，形成新坐标。
                // 判断行数变化是否会超出幻方的边界，值得注意的是行数从上往下递增，列数从左往右递增
                predicted_row = (row - 1) < 0 ? (size - 1) : (row - 1);
                predicted_col = (col + 1) >= size ? 0 : (col + 1);
                // 检查新坐标是否已经被占用，占用则取原坐标下方坐标。
                if (square_check[predicted_row][predicted_col] == 0) {
                    row = predicted_row;
                    col = predicted_col;
                }
                else if (square_check[predicted_row][predicted_col] != 0) {
                    // 转移至当前坐标的正下方一个单位的位置
                    ++row;
                }
            }
            break;
        }
    }

    // 打印幻方
    for (int i = 0; i < size; i++) {
        printf("\n\n\t ");
        for (int j = 0; j < size; j++) {
            // 效于五位数的数会自动向右对齐
            printf("%5d", magic_square[i][j]);
        }
    }

    getchar();
    printf("\n\n");
    return 0;
}