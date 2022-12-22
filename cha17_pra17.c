// �� a ���� 100 �����������顣���д���� qsort �ĵ��ã�ֻ������ a �е���� 50 ��Ԫ�ؽ������򡣣�����Ҫ��д�ȽϺ�������

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comapre_f(const void *, const void *);

int main(void)
{
    int *a;

    srand((unsigned)time(NULL));

    // �����ڴ�
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

// ������ֻ��ϣ������ģ����� qsort ����������� 50 ��Ԫ�ؽ�����������˵������Ҫ��д�ȽϺ�����
// ����������д�������ĳ�����������ԱȽϺ����ǲ��ɻ�ȱ�ġ�
// �����ߴ����ӣ�http://knking.com/books/c2/answers/c17.html