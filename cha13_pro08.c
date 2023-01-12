// �޸ĵ� 7 �µı���� 5��ʹ��������º�����
// int compute_scrabble_value(const char* word);
// �������� word ��ָ����ַ�����ƴ��ֵ��

// �� 7 �� ����� 5��
// ��ʮ��ƴ����Ϸ�У��������С��Ƭ��ɵ��ʣ�ÿ����Ƭ������ĸ����ֵ����ֵ������ĸϡȱ�̶ȵĲ�ͬ����ͬ������ֵ�У�1 ���� AEILNORSTU��2 ���� DG��3 ���� BCMP��4 ���� FHVWY��5 ���� K��8 ���� JX��10 ���� QZ������д����ͨ���Ե�������ĸ����ֵ��������㵥�ʵ�ֵ��
// Enter a word: pitfall
// Scrabble value: 12
// ��д�ĳ���Ӧ���������л�ϳ��ִ�Сд��ĸ����ʾ��ʹ�� toupper �⺯����


#include <stdio.h>
#include <ctype.h>

#define WORD_LEN 30

int compute_scrabble_value(const char *);

int main(int argc, char *argv[])
{
    char entered_word[WORD_LEN];

    printf("\n\t Enter a word: ");
    scanf(" %s", entered_word);
    getchar(); // '\n'

    printf("\n\t Scrabble value: %d ", compute_scrabble_value(entered_word));

    getchar();
    return 0;
}

int compute_scrabble_value(const char *word)
{
    char *trans[10] = { "AEILNORSTU", "DG", "BCMP", "FHVWY", "K", "", "", "JX", "", "QZ" };
    const char *p = word;
    int value = 0;

    while (*p) { // ���÷����൱�� while(*p != '\0')p
        for (int i = 0; i < 10; i++) {
            if (i != 5 && i != 6 && i != 8) { /* ����������������Ĳ��� */
                char *k = trans[i];
                while (*k) { // ���÷����൱�� while(*k != '\0')
                    if (toupper(*p) == *k) { // ���ַ��Ƚ�
                        value += (i + 1);
                        goto NEXTLETTER;
                    }
                    k++; // ָ������
                }
            }
        }
    NEXTLETTER: p++; // ָ������
    }

    return value;
}