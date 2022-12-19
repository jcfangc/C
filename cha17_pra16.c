// 编写下列函数。调用 sum(g,i,j) 应该返回 g(i) + ... + g(j)。
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

    // 分析首末
    if (end >= start) {
        head = start;
        tail = end;
    }
    else {
        head = end;
        tail = start;
    }

    // 叠加
    for (int i = head; i <= tail; i++) {
        total += (*f)(i);
    }

    return total;
}

int times_2(int i)
{
    return i + i;
}