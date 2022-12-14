// �޸� 16.2 �ڵ� print_part ������ʹ��������ʽ������һ��ָ�� part �ṹ��ָ�롣��ʹ�� -> �������

#include <stdio.h>

#define NAME_LEN 60

typedef struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
} part;

// ԭ������
// void print_part(struct part p)
// {
//     printf("Part number: %d\n", p.number);
//     printf("Part name: %s\n", p.name);
//     printf("Quantity on hand: %d\n", p.on_hand);
// }

// �ο��𰸣�
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