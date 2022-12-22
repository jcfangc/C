// 请修改函数 compare_parts 使零件根据编号进行降序排列。
// 这里笔者改编了 part 结构体的成员，只保留了编号这一个成员。

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct part {
    int number;
    struct part *next;
};

int comapre_parts(const void *, const void *);

int main(void)
{
    struct part *a;

    srand((unsigned)time(NULL));

    // 分配内存
    a = calloc(10, sizeof(struct part));

    if (a != NULL) {
        printf("\n\t Inordered: \n");
        for (int i = 0; i < 10; i++) {
            (a + i)->number = rand() % 100;
            if (i % 5 == 0) {
                printf("\n");
            }
            printf("\t\t %d: %d", i, (a + i)->number);
        }

        qsort((a + 0), 10, sizeof(struct part), comapre_parts);

        printf("\n\n\t Ordered: \n");
        for (int i = 0; i < 10; i++) {
            if (i % 5 == 0) {
                printf("\n");
            }
            printf("\t\t %d: %d", i, (a + i)->number);
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

int comapre_parts(const void *p, const void *q)
{
    const struct part *p_part = p;
    const struct part *q_part = q;

    if (p_part->number > q_part->number) {
        return -1;
    }
    else if (p_part->number < q_part->number) {
        return 1;
    }
    else {
        return 0;
    }
}

// 书作者只是希望我们模拟调用 qsort 来对数组最后 50 个元素进行排序，所以说道不需要编写比较函数。
// 笔者在这里写了完整的程序出来，所以比较函数是不可或缺的。
// 书作者答案链接：http://knking.com/books/c2/answers/c17.html