// 声明一个具有如下成员的结构，其标记为 pinball_machine：
// name —— 字符串，最多 40 个字符
// year —— 整数，表示制造年份
// type —— 枚举类型的值，可能的取值为 EM（机电式的）和 SS（固态电路的）
// players —— 整数，表示玩家的最大数目

#define NULL_CHAR 1

typedef struct pinball_machine {
    // 记得为空字符留位
    char name[40 + NULL_CHAR];
    int year;
    enum { EM, SS } type;
    // 考虑到最大数目应该是个固定的，所以使用了类型限定符 const
    const int players;
} pinball_machine;