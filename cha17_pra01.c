// ÿ�ε���ʱ����麯�� malloc ���������κ��ڴ���亯�����ķ���ֵ�Ǽ��ܷ��˵����顣���дһ����Ϊ my_malloc �ĺ�����Ϊ malloc ������ ����װ�����������ú��� my_malloc ��Ҫ����� n ���ֽ�ʱ��������� malloc �������ж� malloc ����ȷʵû�з��ؿ�ָ�룬Ȼ�󷵻����� malloc ��ָ�롣��� malloc ���ؿ�ָ�룬��ô���� my_malloc ��ʾ������Ϣ����ֹ����

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NULL_ERR printf("\n\t Null pointer returned in %s", __func__)
#define N 2147483647

void *my_malloc(size_t);

int main(void)
{
    char *str;

    str = my_malloc(N * sizeof(char));
    strncpy(str, "My_malloc works well.", N);
    printf("\n\t %s", str);

    getchar();
    return 0;
}

void *my_malloc(size_t size)
{
    void *p;

    if ((p = malloc(size)) == NULL) {
        NULL_ERR;
        getchar();
        exit(EXIT_FAILURE);
    }

    return p;
}