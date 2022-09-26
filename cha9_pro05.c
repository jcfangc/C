// 修改第 8 章的编程题 17，使其包含下列函数： 
// void create magic square(int n, char magic_ square[n][n]); 
// void print_ magic_ square(int n, char magic_square[n][n]);
// 获得用户输入的数 n 之后，main 函数调用 create_magic_square 函数，另一个调用参数是在 main 内部声明的 n * n 的数组。create_magic_square 函数1, 2, ..., n^2 填充数组，如原题所述。接下来，main 函数调用 print_magic_square，按原题描述的格式显示数组。注意：如果你的编译器不支持变长数组，请把 main 中的数组声明为999而不是n * n，并使用下面的原型:
// void create_magic_square(int n, char magic_square[99][99]);
// void print_magic_square(int n, char magic square[99][99]};

// 第 8 章编程题 17：
// 编写程序打印 n * n 的幻方 (1, 2, ..., n^2的方阵排列，且每行、每列和每条对角线上的和都相等)。由用户指定n的值：
// This program creates a magic square of a specified size.
// The size must be an odd number between 1 and 99.
// Enter size of magic square: 5

//             17   24    1    8   15

//             23    5    7   14   16

//              4    6   13   20   22

//             10   12   19   21    3

//             11   18   25    2    9


// 把幻方存储在一个二维数组中。起始时把数 1 放在 0 行的中间，剩下的数 2, 3, .... n 依次向上移动一行 并向右移动一列。当可能越过数组边界时需要 “绕回” 到数组的另一端。例如，如果需要把下一个 数放到 n - 1 行，我们就将其存储到 n - 1 行（最后行）；如果需要把下一个数放到 n 列，我们就将其存储到 0 列。如果某个特定的数组元素已被占用，那就把该数存储在前一个数的正下方。如果你的编译器支持变长数组，声明数组有 n 行 n 列，否则声明数组有 99 行 99 列。


#include <stdio.h>

#define N 99

void create_magic_square(int, char[][N]);
void print_magic_square(int, char[][N]);

int main(void)
{
    int size;
    char square[N][N];

    printf("\n\t This programme creates a magic squares of a specified size. \n\t The size must be an odd number between 1 and 99. ");
    printf("\n\t Enter size of magic square: ");
    scanf(" %d", &size);
    getchar();

    while (1) {
        if ((size % 2) == 0) {
            printf("\n\t The size must be an ODD number between 1 and 99. ");
            printf("\n\t Enter size of magic square: ");
            scanf(" %d", &size);
        }
        else {
            create_magic_square(size, square);
            break;
        }
    }

    print_magic_square(size, square);

    getchar();
    printf("\n\n");
    return 0;
}


void create_magic_square(int n, char magic_square[][N])
{
    int row = 0, col;
    int square_check[N][N] = { {0} };
    int predicted_row, predicted_col;

    // 计算出行的中间位置
    col = (n - 1) / 2;
    for (int i = 1; i <= (n * n); i++) {
        // 找到对应位置，放下数字。
        magic_square[row][col] = i;
        square_check[row][col] = 1;
        // 行列各自单独判断，形成新坐标。
        predicted_row = ((row - 1) < 0 ? (n - 1) : (row - 1));
        predicted_col = ((col + 1) >= n ? 0 : (col + 1));
        // 检查新坐标是否已经被占用，占用则取原坐标下方坐标。
        if (square_check[predicted_row][predicted_col] == 0) {
            row = predicted_row;
            col = predicted_col;
        }
        else if (square_check[predicted_row][predicted_col] != 0) {
            ++row;
        }
    }

    return;
}

void print_magic_square(int n, char printf_square[][N])
{
    for (int i = 0; i < n; i++) {
        printf("\n\n\t ");
        for (int j = 0; j < n; j++) {
            printf("%5d", printf_square[i][j]);
        }
    }

    return;
}
