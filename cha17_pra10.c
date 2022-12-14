// 修改 16.2 节的 print_part 函数，使得它的形式参数是一个指向 part 结构的指针。请使用 -> 运算符。

#include <stdio.h>

#define NAME_LEN 60

typedef struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
} part;

// 原函数：
// void print_part(struct part p)
// {
//     printf("Part number: %d\n", p.number);
//     printf("Part name: %s\n", p.name);
//     printf("Quantity on hand: %d\n", p.on_hand);
// }

// 参考答案：
void print_part(struct part *p)
{
    printf("Part number: %d\n", p->number);
    printf("Part name: %s\n", p->name);
    printf("Quantity on hand: %d\n", p->on_hand);
}

int main(void)
{
    struct part a_part = { .name = "a", .number = 123, .on_hand = 321 };

    print_part(&a_part);

    getchar();
    return 0;
}