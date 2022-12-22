// 设 a 是有 100 个整数的数组。请编写函数 qsort 的调用，只对数组 a 中的最后 50 个元素进行排序。（不需要编写比较函数。）

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comapre_f(const void *, const void *);

int main(void)
{
    int *a;

    srand((unsigned)time(NULL));

    // 分配内存
    a = calloc(100, sizeof(int));

    if (a != NULL) {
        printf("\n\t Inordered: \n");
        for (int i = 0; i < 100; i++) {
            *(a + i) = rand() % 100;
            if (i % 5 == 0) {
                printf("\n");
            }
            printf("\t\t %d: %d", i, *(a + i));
        }

        qsort((a + 50), 50, sizeof(int), comapre_f);

        printf("\n\t Ordered: \n");
        for (int i = 50; i < 100; i++) {
            if (i % 5 == 0) {
                printf("\n");
            }
            printf("\t\t %d: %d", i, *(a + i));
        }
    }
    else {
        printf("\n\t No memery avalible. ");
        getchar();
        exit(EXIT_FAILURE);
    }

    getchar();
    return 0;
}

int comapre_f(const void *p, const void *q)
{
    const int *p_int = p;
    const int *q_int = q;

    if (*p_int > *q_int) {
        return 1;
    }
    else if (*p_int < *q_int) {
        return -1;
    }
    else {
        return 0;
    }
}

// 书作者只是希望我们模拟调用 qsort 来对数组最后 50 个元素进行排序，所以说道不需要编写比较函数。
// 笔者在这里写了完整的程序出来，所以比较函数是不可或缺的。
// 书作者答案链接：http://knking.com/books/c2/answers/c17.html