// �����·�ʽ�Ľ� 13.5 �� remind.c ����
// ��a�������Ӧ������Ϊ��������� 31��ϵͳ�ͻ���ʾ������Ϣ�����������ѡ���ʾ��ʹ�� continue ��䡣
// ��b�������û��������ڡ�24 Сʱ��ʽ��ʱ�����ʾ����ʾ�������б�����Ȱ���������Ȼ���ٰ�ʱ�����򡣣�ԭʼ�� remind.c ���������û�����ʱ�䣬��������ʱ����Ϊ���ѵ�һ������������
// ��c��������ʾһ��������б�Ҫ���û������� / �յĸ�ʽ�������ڡ�

#include <stdio.h>
#include <string.h>

#define MSG_NUM 50
#define MSG_LEN 50
#define DATE_LEN 6
#define TIME_LEN 6

// ���ַ���
int read_line(char *, int);
// ʱ��˳������
void make_chronological(char(*)[MSG_LEN + DATE_LEN + TIME_LEN], char *);

int main(void)
{
    char remind_box[MSG_NUM][MSG_LEN + DATE_LEN + TIME_LEN] = { {'\0'} };
    char new_remind[MSG_LEN + DATE_LEN + TIME_LEN] = { '\0' };
    int month, day, hour, min, num = 0;
    char date[DATE_LEN], time[TIME_LEN], msg[MSG_LEN];

    while (num < MSG_NUM) {
        // �õ���Ҫ��Ϣ
        printf("\n\t Enter message: (0 to end) ");
        read_line(msg, MSG_LEN);
        if (strcmp(msg, "0") == 0) {
            break;
        }
        printf("\n\t Enter date: (mm/dd) ");
        scanf(" %2d/%2d", &month, &day);
        getchar();
        // �����Ӧ������Ϊ��������� 31��ϵͳ�ͻ���ʾ������Ϣ�����������ѡ�
        if (day > 31 || day < 0) {
            printf("\t Wrong day. \n");
            continue;
        }
        printf("\n\t Enter time: (<24-hour>hh:mm) ");
        scanf(" %2d:%2d", &hour, &min);
        getchar();

        // ��Ϣ�������ʽ��
        sprintf(date, "%2d/%2.2d", month, day);
        sprintf(time, "%2d:%2.2d", hour, min);
        // �Ѿ��������ÿ���ַ����ĳ��ȣ����Ծ�û��ʹ�� strncat �� strncpy
        strcat(strcat(strcat(strcat(strcpy(new_remind, date), " "), time), " "), msg);

        // ʱ��������¼
        make_chronological(remind_box, new_remind);

        num++;
    }

    printf("\n\n\t ----------- REMINDINGS ----------- \n");
    int i = 0;
    while (strcmp(*(remind_box + i), "\0") != 0 && i < MSG_NUM) {
        printf("\n\t %2d. %s", (i + 1), *(remind_box + i));
        i++;
    }

    getchar();
    return 0;
}

int read_line(char *msg, int len)
{
    char ch, *p = msg;

    while ((ch = getchar()) != '\n' && (int)(p - msg) < len) {
        *p++ = ch;
    }

    *p++ = '\0';
    return (int)(p - msg);
}

void make_chronological(char(*remindings)[MSG_LEN + DATE_LEN + TIME_LEN], char *new_remind)
{
    // ¼���һ������
    if (strcmp(*(remindings + 0), "\0") == 0) {
        strcpy(*(remindings + 0), new_remind);
        return;
    }

    // �Թ��ձ���¼
    char(*p)[MSG_LEN + DATE_LEN + TIME_LEN] = remindings + MSG_NUM - 1;
    while (strcmp(*(p - 1), "\0") == 0 && p > remindings) {
        p--;
    }

    // �ƶ���δ���ı���¼
    while (strcmp(*(p - 1), new_remind) >= 0 && p > remindings) {
        strcpy(*(p), *(p - 1));
        p--;
    }

    // ��λ���뵱ǰ�±���
    strcpy(*(p), new_remind);
    return;
}