// ��д����ĺ�����
// void remove_filename(char *url);
// url ָ��һ���������ļ�����β�� URL��Uniform Resource Locator, ͳһ��Դ��λ�������ַ����� ���� ��http://www.knking.com/index.html"������Ӧͨ���Ƴ��ļ�����ǰ���б�����޸��ַ�������������������У����Ϊ ��http://www.knking.com������Ҫ���ں�����ʹ�� �������ַ�����β�� �Ĺ��÷�����ʾ�����ַ����е����һ��б���滻Ϊ���ַ���

#include <stdio.h>
#include <string.h>

#define STR_MAX 120

int read_url(char[], int);
void remove_filename(char *);

int main(int argc, char *argv[])
{
    char url[STR_MAX] = { '\0' };

    printf("\n\t Enter an URL: ");
    read_url(url, STR_MAX);
    remove_filename(url);

    printf("\n\t URL without file name is: %s", url);

    getchar();
    return 0;
}

int read_url(char str[], int len)
{
    char(*p) = str;
    char ch;

    while ((ch = getchar()) != '\n' && (p < str + len)) {
        (*p++) = ch;
    }

    return (p - str);
}

// �𰸲���
void remove_filename(char *url)
{
    int length = strlen(url);
    char(*p) = (url + length);

    while ((*p) != '/' && (p > url)) {
        // ��β����������Ѱ��һ����/��
        p--;
    }

    (*p) = '\0';
}