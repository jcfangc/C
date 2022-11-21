// ��д���к�����
    // int *creat_array(int n, int initial_value);
// ��������һ��ָ��̬����� n Ԫ int �������ָ�룬�����ÿ����Ա����ʼ��Ϊ initial_value������ڴ����ʧ�ܣ�����ֵΪNULL��

#include <stdio.h>
#include <stdlib.h>

#define N 5

int *creat_array(int, int);

int main(int argc, char *argv[])
{
    int *arr;
    arr = creat_array(N, 2);

    // �ǿղŴ�ӡֵ
    if (arr != NULL) {
        printf("\n\t ");
        for (int i = 0; i < N; i++) {
            printf("%2d", arr[i]);
        }
    }
    else {
        printf("\n\t NULL pointer");
    }
    free(arr);

    getchar();
    return 0;
}

int *creat_array(int n, int initial_value)
{
    int *p;

    p = malloc(n * sizeof(int));
    // �ǿ�ָ��ŷ���ֵ
    if (p != NULL) {
        for (int *value = p; value < p + n; value++) {
            *value = initial_value;
        }
    }

    return p;
}