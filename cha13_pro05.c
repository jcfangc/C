// ��д��Ϊ sum.c �ĳ��������������в��������趼����������͡��������
// sum 8 24 62
// ���г��򣬲��������ӦΪ
// Total��94
// ��ʾ���� atoi ��������26.2�ڣ���ÿ�������в������ַ�����ʽת����������ʽ��

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int total = 0;

    // argv[0] --> ������
    // argv[1] --> "sum"
    if (strcmp(argv[1], "sum") == 0) {
        for (int i = 2; i < argc; i++) {
            total += atoi(argv[i]);
        }
    }

    printf("\n\t Total: %d ", total);

    getchar();
    return 0;
}