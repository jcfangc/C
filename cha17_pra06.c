// ����������������Ч��
    // struct point { int x, y; };
    // struct rectangle { struct point upper_left, lower_right; };
    // struct rectangle *p;
// ���޸ĺ��� delete_from_list ʹ��ʹ��һ��ָ������������������� cur �� prev����

#include <stdio.h>
#include <stdlib.h>

struct node *delete_from_list(struct node *, int);

typedef struct node {
    int value;
    struct node *next;
} node;

int main(void)
{
    getchar();
    return 0;
}

// �� cur ����ԭ�����е� prev���� cur->next ����ԭ�����е� cur ����
struct node *delete_from_list(struct node *list, int n)
{
    struct node *cur;

    for (cur = NULL, cur->next = list; cur->next != NULL && cur->next->value != n; cur = cur, cur->next = cur->next->next) {
        ;
    }

    if (cur->next == NULL) {
        return list;
    }
    else if (cur == NULL) {
        list = list->next;
    }
    else {
        cur = cur->next->next;
    }

    free(cur);
    return list;
}

// struct node *delete_from_list(struct node *list, int n)
// {
//     struct node *cur, *prev;

//     for (prev = NULL, cur = list; cur != NULL && cur->value != n; prev = cur, cur = cur->next) {
//         ;
//     }

//     if (cur == NULL) {
//         return list;
//     }
//     else if (prev == NULL) {
//         list = list->next;
//     }
//     else {
//         prev = cur->next;
//     }

//     free(cur);
//     return list;
// }