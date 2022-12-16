#define KING_VALUE 200
#define QUEEN_VALUE 9
#define ROOK_VALUE 5
#define BISHOP_VALUE 3
#define KNIGHT_VALUE 3
#define PAWN_VALUE 1

// 枚举 chess_piece 声明如下：
enum chess_piece { KING, QUEEM, ROOK, BISHOP, KNIGHT, PAWN };

// (a) 为名为 piece_value 的整数常数数组编写声明（包含一个初始化式），这个数组存储数 200，9，5，3，3 和 1 分别表示从国王到兵这些棋子。（国王的值实际上时无穷大，因为一旦王被擒（将死）则游戏结束，但一些象棋软件会给国王分配一个类似 200 的较大值。）
const int piece_value[6] = { KING_VALUE, QUEEN_VALUE, ROOK_VALUE, BISHOP_VALUE, KNIGHT_VALUE, PAWN_VALUE };

// (b) （C99）重复上题，但是使用指定初始化式来初始化数组。把 chess_pieces 中的枚举常量作为指示符的下标使用。（提示：参考 “问与答” 部分的最后一个问题。）
const int piece_value[6] = { [KING] = KING_VALUE,[QUEEM] = QUEEN_VALUE,[ROOK] = ROOK_VALUE,[BISHOP] = BISHOP_VALUE,[KNIGHT] = KNIGHT_VALUE,[PAWN] = PAWN_VALUE };