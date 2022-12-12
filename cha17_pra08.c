// 15.2 节描述文件 stack.c 提供了在栈中存储整数 的函数。在那一节中，栈是用数组实现的。请修改程序 stack.c 从而使栈现在作为链表来存储。使用单独一个指向链表首结点的指针变量（栈“顶”）来替换变量 contents 和变量 top。在 stack.c 中编写的函数如果要使用  指针。删除函数 is_full，用返回 ture（如果创建的结点可以获得内存）或 false（如果创建的结点无法获得内存）的函数 push 来代替。

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data_int;
    struct node *next;
} node;

node *top = NULL;

void make_empty(void)
{
    struct node *temp;

    while (top != NULL) {
        temp = top;
        top = top->next;
        free(temp);
    }
}

bool is_empty(void)
{
    return (top == NULL ? true : false);
}

bool push(int i)
{
    struct node *new_node = malloc(sizeof(node));

    if (new_node != NULL) {
        new_node->data_int = i;
        new_node->next = top;
        top = new_node;
        return true;
    }
    else if (new_node == NULL) {
        return false;
    }
}

int pop(void)
{
    struct node *temp;
    int pop_num;

    if (is_empty) {
        printf("\n\t stact is empty. ");
        exit(EXIT_FAILURE);
    }

    temp = top;
    pop_num = top->data_int;
    top = top->next;
    free(temp);

    return pop_num;
}

// 书作者答案链接：http://knking.com/books/c2/answers/c17.html