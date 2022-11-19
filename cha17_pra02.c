// ��д��Ϊ duplicate �ĺ������˺���ʹ�ö�̬�洢�����������ַ����ĸ��������磬����
    // p = duplicate(str);
// ��Ϊ�� str ������ͬ���ַ��������ڴ�ռ䣬���Ұ��ַ��������ݸ��Ƶ����ַ�����Ȼ�󷵻�ָ�����ַ�����ָ�룬��������ڴ�ʧ�ܣ���ô���� duplicate ���ؿ�ָ�롣

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *duplicate(char *);

int main(void)
{
    char str_0[] = "abc";
    char *str_1;

    str_1 = duplicate(str_0);
    if (str_1 != NULL) {
        printf("\n\t %s", str_1);
    }
    else {
        printf("\n\t Null pointer returned. ");
    }

    getchar();
    return 0;
}

char *duplicate(char *str)
{
    char *p;
    int len = (int)strlen(str) + 1; // 1 for '\0'

    p = malloc(len * sizeof(char));
    if (p != NULL) {
        strncpy(p, str, len);
    }

    return p;
}


// �����ߴ𰸣�http://knking.com/books/c2/answers/c17.html
// char *duplicate(const char *s)
// {
//   char *temp = malloc(strlen(s) + 1);

//   if (temp == NULL)
//     return NULL;

//   strcpy(temp, s);
//   return temp;
// }