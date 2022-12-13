#include <stdio.h>

// (a) �����������̵�ÿ�������п�����һ�����ӣ�����/��/��/��/�ʺ�������Ҳ����Ϊ�ա�ÿ�����ӿ���Ϊ��ɫ��Ҳ����Ϊ��ɫ�ġ��붨������ö�����ͣ�Piece �������� 7 �ֿ��ܵ�ֵ�����а���һ��Ϊ ���ա�����Color ������ʾ 2 ����ɫ.
typedef enum Piece { Blank, Pawn, Knight, Bishop, Rook, Queen, King } Piece;
typedef enum Color { Black, White } Color;
// (b) ���� (a) �е����ͣ�������Ϊ Square �Ľṹ���ͣ�ʹ�����Ϳ��Դ洢���ӵ����ͺ���ɫ��
typedef struct Square {
    enum Piece kind;
    enum Color color;
} Square;
// (c) ���� (b) �е� Square ���ͣ�����һ�� board �� 8x8 �����顣ʹ��������������洢�����ϵ�ȫ�����ݡ�
// (d) �� (c) �е�������ӳ�ʼ��ʽ��ʹ board �ĳ�ʼֵ��Ӧ�������������ʼʱ�����Ӳ��֡�û�����ӵķ���ֵΪ������ɫΪ��ɫ��
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

// ���⽫�պͺ�ɫ������ö�ٵ����ӵĵ�һ������Ϊ�����������ʼ����Ĭ�ϵ�Ԫ��Ϊ 0 �����ԡ�

int main(void)
{
    printf("\n\t ���ԣ�%d,%d", board[7][3].kind, board[7][3].color);

    getchar();
    return 0;
}
