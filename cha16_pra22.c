#define KING_VALUE 200
#define QUEEN_VALUE 9
#define ROOK_VALUE 5
#define BISHOP_VALUE 3
#define KNIGHT_VALUE 3
#define PAWN_VALUE 1

// ö�� chess_piece �������£�
enum chess_piece { KING, QUEEM, ROOK, BISHOP, KNIGHT, PAWN };

// (a) Ϊ��Ϊ piece_value ���������������д����������һ����ʼ��ʽ�����������洢�� 200��9��5��3��3 �� 1 �ֱ��ʾ�ӹ���������Щ���ӡ���������ֵʵ����ʱ�������Ϊһ�������ܣ�����������Ϸ��������һЩ������������������һ������ 200 �Ľϴ�ֵ����
const int piece_value[6] = { KING_VALUE, QUEEN_VALUE, ROOK_VALUE, BISHOP_VALUE, KNIGHT_VALUE, PAWN_VALUE };

// (b) ��C99���ظ����⣬����ʹ��ָ����ʼ��ʽ����ʼ�����顣�� chess_pieces �е�ö�ٳ�����Ϊָʾ�����±�ʹ�á�����ʾ���ο� ������� ���ֵ����һ�����⡣��
const int piece_value[6] = { [KING] = KING_VALUE,[QUEEM] = QUEEN_VALUE,[ROOK] = ROOK_VALUE,[BISHOP] = BISHOP_VALUE,[KNIGHT] = KNIGHT_VALUE,[PAWN] = PAWN_VALUE };