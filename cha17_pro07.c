// ��C99���޸� 17.2 �ڵ� remind2.c ����ʹ�� reminders �����е�ÿ��Ԫ�ض���ָ�� vstring �ṹ���� 17.9 �ڣ���ָ�룬������ָ����ͨ�ַ�����ָ�롣
// ��������������ڴ�ֱ��ʹ�������ߵĳ�������޸�

/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

 /* remind2.c (Chapter 17, page 418) */
 /* Prints a one-month reminder list (dynamic string version) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REMIND 50   /* maximum number of reminders */
#define MSG_LEN 60      /* max length of reminder message */

typedef struct vstring {
    int len;
    char chars[];
} vstring;

int read_line(char str[], int n);

int main(void)
{
    vstring *reminders[MAX_REMIND];
    char day_str[3], msg_str[MSG_LEN + 1];
    int day, i, j, num_remind = 0;

    for (;;) {
        if (num_remind == MAX_REMIND) {
            printf("-- No space left --\n");
            break;
        }

        printf("Enter day and reminder: ");
        scanf("%2d", &day);
        if (day == 0)
            break;
        sprintf(day_str, "%2d", day);
        read_line(msg_str, MSG_LEN);

        for (i = 0; i < num_remind; i++)
            if (strcmp(day_str, reminders[i]->chars) < 0)
                break;
        for (j = num_remind; j > i; j--) {
            // ��������Ա�޷�ͨ����ֵ�ķ�ʽֱ�Ӹ���
            // ͬʱ��Ҫע�������ʹ�� memcpy ǰ����� dest ָ����ڴ�ռ�С�� src ��Ҫ���Ƶ� n ���ֽڣ���ô��������ڴ�Խ�����
            // ��Խ�� dest ָ����ڴ�ռ�ı߽�ʱ���ᵼ�·���δ������ڴ棬����ܻᵼ�³������������������Ԥ֪�Ĵ���
            // Ϊ�˱������ִ�����ʹ�� memcpy ����ʱӦ��ȷ��Ŀ���ڴ�ռ��㹻�󣬻���ʹ������������memmove�������ڴ��ص���
            // ����ڵ���memcpy֮ǰ������ȼ����Ŀ���ڴ�ռ��Ƿ��㹻����������������·����ڴ档
            reminders[j] = calloc(1, sizeof(vstring) + strlen(reminders[j - 1]->chars) + 1); // 1 for '\0'
            if (reminders[j] == NULL) {
                printf("-- No space left --\n");
                exit(EXIT_FAILURE);
            }
            memcpy(reminders[j], reminders[j - 1], sizeof(vstring) + strlen(reminders[j - 1]->chars));
        }

        reminders[i] = calloc(1, strlen(day_str) + strlen(msg_str) + 1 + sizeof(vstring)); // 1 for '\0'
        if (reminders[i] == NULL) {
            printf("-- No space left --\n");
            break;
        }


        // sprintf(reminders[i]->chars, "%s %s", day_str, msg_str);
        strcpy(reminders[i]->chars, day_str);
        strcat(reminders[i]->chars, msg_str);

        num_remind++;
    }

    printf("\nDay Reminder\n");
    for (i = 0; i < num_remind; i++)
        printf(" %s\n", reminders[i]->chars);

    getchar(); //'\n'
    getchar();
    return 0;
}

int read_line(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}
