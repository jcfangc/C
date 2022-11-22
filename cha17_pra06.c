// 假设下列声明都有效：
    // struct point { int x, y; };
    // struct rectangle { struct point upper_left, lower_right; };
    // struct rectangle *p;
// 请修改函数 delete_from_list 使它使用一个指针变量而不是两个（即 cur 和 prev）。

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

// 用 cur 代替原函数中的 prev，用 cur->next 代替原函数中的 cur 即可
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