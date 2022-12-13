#include <stdio.h>

// (a) 国际象棋棋盘的每个方格中可能有一个棋子，即兵/马/象/车/皇后或国王，也可能为空。每个棋子可能为黑色的也可能为白色的。请定义两个枚举类型：Piece 用来包含 7 种可能的值（其中包括一种为 “空”），Color 用来表示 2 种颜色.
typedef enum Piece { Blank, Pawn, Knight, Bishop, Rook, Queen, King } Piece;
typedef enum Color { Black, White } Color;
// (b) 利用 (a) 中的类型，定义名为 Square 的结构类型，使此类型可以存储棋子的类型和颜色。
typedef struct Square {
    enum Piece kind;
    enum Color color;
} Square;
// (c) 利用 (b) 中的 Square 类型，声明一个 board 的 8x8 的数组。使此数组可以用来存储棋盘上的全部内容。
// (d) 给 (c) 中的声明添加初始化式，使 board 的初始值对应国际象棋比赛开始时的棋子布局。没有棋子的方格值为空且颜色为黑色。
struct Square board[8][8] = {
    {
        // ROW 1
        { Rook,     Black },        { Knight,   Black },        { Bishop,   Black },        { Queen,    Black },
        { King,     Black },        { Bishop,   Black },        { Knight,   Black },        { Rook,     Black }
    },
    {
        // ROW 2
        { Pawn,     Black },        { Pawn,     Black },        { Pawn,     Black },        { Pawn,     Black },
        { Pawn,     Black },        { Pawn,     Black },        { Pawn,     Black },        { Pawn,     Black }
    },
    { /* ROW 3 */ },    { /* ROW 4 */ },    { /* ROW 5 */ },    { /* ROW 6 */ },
    {
        // ROW 7
        { Pawn,     White },        { Pawn,     White },        { Pawn,     White },        { Pawn,     White },
        { Pawn,     White },        { Pawn,     White },        { Pawn,     White },        { Pawn,     White }
    },
    {
        // ROW 8
        { Rook,     White },        { Knight,   White },        { Bishop,   White },        { Queen,    White },
        { King,     White },        { Bishop,   White },        { Knight,   White },        { Rook,     White }
    }
};

// 特意将空和黑色放置在枚举的例子的第一个，是为了利用数组初始化中默认的元素为 0 的特性。

int main(void)
{
    printf("\n\t 测试：%d,%d", board[7][3].kind, board[7][3].color);

    getchar();
    return 0;
}
