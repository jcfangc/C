// 修改 11.4 节的 maxmin.c 程序，使得 max_min 函数使用指针而不是整数来跟踪数组中的当前位置。

#include <stdio.h>

#define N 10

void max_min(int[], int, int *, int *);

int main(void)
{
    int b[N], i, big, small;

    printf("\n\t Enter %d numbers: ", N);
    for (i = 0; i < N; i++) {
        scanf(" %d", &b[i]);
    }
    getchar(); // '\n'

    max_min(b, N, &big, &small);

    printf("\n\t Largest: %d", big);
    printf("\n\t Smallest: %d", small);

    getchar();
    return 0;
}

void max_min(int a[], int n, int *max, int *min)
{
    int(*p);

    (*max) = (*min) = (*a);
    for (p = (a + 1); p < (a + n); p++) {
        if ((*p) > (*max)) {
            (*max) = (*p);
        }
        else if ((*p) < (*min)) {
            (*min) = (*p);
        }
    }
}