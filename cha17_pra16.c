// ��д���к��������� sum(g,i,j) Ӧ�÷��� g(i) + ... + g(j)��
// int sum(int (*f)(int), int start, int end);

#include <stdio.h>

int sum(int (*)(int), int, int);
int times_2(int);

int main(void)
{
    printf("\n\t Result: %d", sum(times_2, 8, 2));

    return 0;
}

int sum(int (*f)(int), int start, int end)
{
    int total = 0;
    int head, tail;

    // ������ĩ
    if (end >= start) {
        head = start;
        tail = end;
    }
    else {
        head = end;
        tail = start;
    }

    // ����
    for (int i = head; i <= tail; i++) {
        total += (*f)(i);
    }

    return total;
}

int times_2(int i)
{
    return i + i;
}