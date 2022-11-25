// �޸ĵ� 8 �µı���� 15��ʹ��������º�����
// void encrypt(char *message, int shift);
// ���� message ָ��һ������������Ϣ���ַ�����shift ��ʾ��Ϣ��ÿ����ĸ��Ҫ�ƶ���λ����

// �� 8 �µı���� 15��
// ��֪������ϵ�һ�ּ��ܼ����ǿ������ܣ�������Julius Caesar�����÷�����һ����Ϣ�е�ÿ����ĸ����ĸ���й̶�����֮����Ǹ���ĸ�������(���Խ������ĸ Z�����ƻص���ĸ�����ʼλ�á����磬���ÿ����ĸ������ĸ��������λ��֮�����ĸ���棬��ô Y �ͱ��滻Ϊ A��Z �ͱ��滻Ϊ B�� )��д�����ÿ������ܷ�������Ϣ���м��ܡ��û���������ܵ���Ϣ����λ����(��ĸ�ƶ���λ����Ŀ) :

// Enter message to be encrypted: Go ahead, make my day.
// Enter shift amount (1-25): 3
// Encrypted message: Jr dkhdg, pdnh pb gab.

// ע�⣬���û�����26����λ�����Ĳ�ֵʱ��������Զ���Ϣ���н���:
// Enter message to be encrypted: Jr dkhdg, pdnh pb gdb.
// Enter shift amount (1-25): 3
// Encrypted message: Go ahead, make my day .

// ���Լٶ���Ϣ�ĳ��Ȳ����� 80 ���ַ���������ĸ����Щ�ַ���Ҫ�Ķ������⣬����ʱ��Ҫ�ı���ĸ�Ĵ�Сд����ʾ��Ϊ�˽��ǰ���ᵽ���ƻ����⣬�����ñ��ʽ ((ch- ��A��) + n) % 26+ 'A �����д��ĸ�����룬���� ch �洢��ĸ��n �洢��λ��������Сд��ĸҲ��Ҫһ�����Ƶı��ʽ��)

#include <stdio.h>
#include <ctype.h>

#define MESSAGE_LEN 120

int read_line(char[], int);
void encrypt(char *, int);

int main(int argc, char *argv[])
{
    // ��ʼ��
    char message[MESSAGE_LEN] = "";
    int phase;

    // ¼�����
    printf("\n\t Enter message to be encrypted: ");
    int sent_len = read_line(message, MESSAGE_LEN);

    // �����ƶ���λ
    printf("\n\t Enter shift amount (1-25): ");
    scanf("%d", &phase);
    getchar(); // '\n'
    encrypt(message, phase);

    // ��ӡ������Ϣ
    printf("\n\t Encrypted message: ");
    for (int i = 0; i < sent_len; i++) {
        printf("%c", message[i]);
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

void encrypt(char *message, int shift)
{
    // ������ĸ����������ϵͳ�ַ�
    char alphabet[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
    char(*position), (*replace);

    // ���� message �е�ÿ���ַ�
    for (position = message; position < message + MESSAGE_LEN; position++) {
        // �����ַ���ĩ��
        if ((*position) == '\0') { break; }
        // ����ΪСдʱ
        if (islower(*position)) {
            // �ҵ���ĸ���еĶ�Ӧ����
            for (replace = alphabet; replace < alphabet + 26; replace++) {
                if ((*position) != tolower(*replace)) { continue; }
                // �ҵ���Ӧ�ַ�ʱ
                else if ((*position) == tolower(*replace)) {
                    // ������λ�ƶ��滻��ĸ
                    (*position) = tolower(*(alphabet + (((int)(replace - alphabet) + shift) % 26)));
                    break;
                }
            }
        }
        // ����Ϊ��дʱ
        else if (isupper(*position)) {
            // �ҵ���ĸ���еĶ�Ӧ����
            for (replace = alphabet; replace < alphabet + 26; replace++) {
                if ((*position) != (*replace)) { continue; }
                // �ҵ���Ӧ�ַ�ʱ
                else if ((*position) == (*replace)) {
                    // ������λ�ƶ��滻��ĸ
                    (*position) = (*(alphabet + (((int)(replace - alphabet) + shift) % 26)));
                    break;
                }
            }
        }
        // �����ŵ�
        else { continue; }
    }
}