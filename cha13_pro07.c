// �޸ĵ� 5 �µı���� 11�����ַ���ָ������ȡ�� switch ��䡣���磬���ڲ����� switch �������ʾ��һλ���ֶ�Ӧ�ĵ��ʣ����Ѹ����������±�Ӱ��� ��twenty������thirty�� ���ַ���������������

// �� 5 �� ����� 11��
// ��дһ������Ҫ���û�����һ����λ����Ȼ����ʾ������Ӣ�ĵ��ʣ�
// Enter a two-digit number��45
// You entered the number forty-five.
// ��ʾ�������ֽ�Ϊ�������֡���һ�� switch �����ʾ��һλ���ֶ�Ӧ�ĵ��ʣ���twenty������thirty�� �ȣ����õڶ��� switch �����ʾ�ڶ�λ���ֶ�Ӧ�ĵ��ʡ���Ҫ���� 11 ~ 19 ��Ҫ���⴦��

#include <stdio.h>

int main(int argc, char *argv[])
{
    int entered_num;
    char *teen[10] = { "ten", "eleven", "twelve", "thirteen", "forteen", "fifteen", "sixteen", "seven", "eighteen", "nineteen" };
    char *teens[8] = { "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninty" };
    char *digit[9] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

    for (;;) {
        printf("\n\t Enter a two-digit number: ");
        scanf(" %d", &entered_num);
        getchar(); // '\n'

        if (entered_num >= 10 && entered_num < 100) {
            break;
        }
    }

    if (entered_num < 20) {
        printf("\n\t You entered the number %s.", teen[(entered_num % 10)]);
    }
    else if (entered_num >= 20) {
        // ʮλ����
        int timesof_10 = 2;
        for (;;) {
            if (++timesof_10 * 10 >= entered_num) {
                break;
            }
        }
        // ���ڸ��������ж����������˳�ʱ timesof_10 ����Ԥ���� + 1����������� - 1 ��������
        printf("\n\t You entered the number %s", teens[(timesof_10 - 1 - 2)]);
        if (entered_num % 10 != 0) {
            printf(" - %s", digit[(entered_num % 10) - 1]);
        }
        printf(".");
    }

    getchar();
    return 0;
}