// 15.2 �������ļ� stack.c �ṩ����ջ�д洢���� �ĺ���������һ���У�ջ��������ʵ�ֵġ����޸ĳ��� stack.c �Ӷ�ʹջ������Ϊ�������洢��ʹ�õ���һ��ָ�������׽���ָ�������ջ�����������滻���� contents �ͱ��� top���� stack.c �б�д�ĺ������Ҫʹ��  ָ�롣ɾ������ is_full���÷��� ture����������Ľ����Ի���ڴ棩�� false����������Ľ���޷�����ڴ棩�ĺ��� push �����档

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

// �����ߴ����ӣ�http://knking.com/books/c2/answers/c17.html