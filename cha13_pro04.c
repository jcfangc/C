// ��д��Ϊ reverse.c �ĳ�������������������в������������
// reverse void and null
// ���г��򣬲��������ӦΪ
// null and void

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (strcmp("reverse", argv[1]) == 0) {
        printf("\n\t ");
        for (int i = argc - 1; i > 1; i--) {
            printf("%s ", argv[i]);
        }
    }

    getchar();
    return 0;
}

// �����ߴ𰸣���http://knking.com/books/c2/answers/c13.html��