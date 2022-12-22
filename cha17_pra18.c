// ���޸ĺ��� compare_parts ʹ������ݱ�Ž��н������С�
// ������߸ı��� part �ṹ��ĳ�Ա��ֻ�����˱����һ����Ա��

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

    // �����ڴ�
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

// ������ֻ��ϣ������ģ����� qsort ����������� 50 ��Ԫ�ؽ�����������˵������Ҫ��д�ȽϺ�����
// ����������д�������ĳ�����������ԱȽϺ����ǲ��ɻ�ȱ�ġ�
// �����ߴ����ӣ�http://knking.com/books/c2/answers/c17.html