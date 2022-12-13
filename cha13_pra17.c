// ��д����ĺ�����
// bool test_extension(const char *file_name,  const char *extension);
// file_name ָ������ļ������ַ���������ļ���չ���� extension ָ����ַ���ƥ�䣨�����ִ�Сд������������ ture�����磬�������� test_extension ("memo.txt", "TXT") ������ true��Ҫ���ں�����ʹ�� �������ַ�����β�� �Ĺ��÷�����ʾ���ڱȽ��ַ�֮ǰʹ�� toupper �������� 23.5�ڣ����ַ���ת���ɴ�д��ʽ��

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define STR_MAX 60

int read_line(char[], int);
_Bool test_extension(const char *, const char *);

int main(int argc, char *argv[])
{
    char filename[STR_MAX] = { '\0' };

    printf("\n\t Enter file name. \n\t ");
    read_line(filename, STR_MAX);
    // �����ļ�����չ���ǲ��� ��txt��
    if (test_extension(filename, "txt")) {
        printf("\n\t TRUE ");
    }
    else {
        printf("\n\t FALSE ");
    }

    getchar();
    return 0;
}

int read_line(char str[], int len)
{
    char(*p) = str;

    while (((*p) = getchar()) != '\n' && (p < str + len)) {
        p++;
    }

    (*p) = '\0';
    *(str + len - 1) = '\0';
    return (p - str);
}

_Bool test_extension(const char *file_name, const char *extension)
{
    // �ҵ� '.'���� file_name ָ�� '.' ֮���λ��
    while ((*file_name++) != '.') {
        ;
    }

    // �Ƚ��ļ���չ��
    while (*extension && *file_name) {
        if (toupper(*extension++) == toupper(*file_name++)) {
            continue;
        }
        else {
            return false;
        }
    }

    if ((*extension) == '\0' && (*file_name) == '\0') {
        return true;
    }
    else {
        return false;
    }
}