// �޸ĵ� 8 �µı���� 16��ʹ��������º�����
// bool are_anagrams(const char *word1, const char *word2);
// ��� word1 �� word2 ָ����ַ����Ǳ�λ�ʣ��������� ture��

// �� 8 �µı���� 16��
// ��̲������������Ƿ�Ϊ��λ�ʣ���ͬ��ĸ���������У�

// Enter first word: smartest
// Enter second word: mattress
// The words are anagrams.

// Enter first word: dumbest
// Enter second word: stumble
// The words are not anagrams.

// ��һ��ѭ������ַ��ض�ȡ��һ�����ʣ� ��һ�� 26 Ԫ�����������¼ÿ����ĸ�ĳ��ִ�����( ���磬��ȡ���� smartest ֮�����������ֵΪ 10001000000100000122000000������ smartest ����һ�� a��һ�� e��һ�� m��һ�� r������ s ������ t��������һ��ѭ����ȡ�ڶ������ʣ����ÿ��ȡһ����ĸ�Ͱ���Ӧ����Ԫ�ص�ֵ�� 1������ѭ����Ӧ�ú��Բ�����ĸ����Щ�ַ������Ҳ����ִ�Сд���ڶ������ʶ�ȡ��Ϻ�����һ��ѭ�����������Ԫ���Ƿ�Ϊȫ 0�������ȫ 0����ô���������ʾ��Ǳ�λ�ʡ���ʾ������ʹ�� <ctype.h> �еĺ������� isalpha �� tolower��

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define WORD_LEN 30

bool are_anagrams(const char *, const char *);
int read_line(char[], int);

int main(int argc, char *argv[])
{
    // ��ʼ��
    char word1[WORD_LEN] = "", word2[WORD_LEN] = "";

    // ����¼��
    printf("\n\t Enter first word: ");
    read_line(word1, WORD_LEN);
    printf("\t Enter second word: ");
    read_line(word2, WORD_LEN);

    // ���ݺ���������
    if (are_anagrams(word1, word2)) {
        printf("\n\t The words are anagrams. ");
    }
    else {
        printf("\n\t The words are not anagrams. ");
    }

    getchar();
    return 0;
}

int read_line(char str[], int str_len)
{
    char *p = str;
    char ch;

    while (((ch = getchar()) != '\n') && (p < str + str_len)) {
        *p++ = ch;
    }

    *p = '\0';
    return (int)(p - str);
}

// ����Ŀ��ʾ���㷨����ͬ
bool are_anagrams(const char *word1, const char *word2)
{
    // ���ʳ������ʱ�������߼��ų���
    if (strlen(word1) != strlen(word2)) {
        return false;
    }

    const char *p1 = word1, *p2;
    /* miss ����˵���������ʵ�ʱ�Ķ�Ӧ״̬������ĸ��Ӧ����ʱ��miss Ϊ�� */
    bool miss = false;
    /* ��Ӧ�ϵ���ĸ�´ν����ټ�� */
    bool checked[WORD_LEN] = { false };

    /* p1 ָ����ַ�ʱֹͣѭ�� */
    while (*p1) {
        p2 = word2;
        while ((*p2)) {
            /* ��Ӧλ�õ���ĸ�Ѿ���Ӧ�Ϻ�check ������Ӧλ��Ϊ true����Ӧ�ٴμ�� */
            if (checked[(int)(p2 - word2)] == true) {
                p2++;
                continue;
            }
            /* ��Сд�ڱ������в������֣�ֻҪ��ͬһ����ĸ���� */
            else if ((*p1) == tolower(*p2) || (*p1) == toupper(*p2)) {
                /* ��ǰ p2 ��ָ��ĺ� p1 ���Ӧ���� checked �����н��б�� */
                checked[(int)(p2 - word2)] = true;
                break;
            }
            /* ��ǰ p2 ָ�����ĸ�� p1 ָ�����ĸ����ͬ�������һ����ĸ */
            else { p2++; }
        }
        /* �� p2 ָ����ַ�ʱִ�б���������ַ����ַ���ĩβ����������˵�� word2 ��û�ж�Ӧ��ĸ */
        if (!(*p2)) { return miss; }
        p1++;
    }

    return !miss;
}