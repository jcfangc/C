// （C99）修改 17.2 节的 remind2.c 程序，使得 reminders 数组中的每个元素都是指向 vstring 结构（见 17.9 节）的指针，而不是指向普通字符串的指针。
// 方便起见，笔者在此直接使用书作者的程序进行修改

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
            // 灵活数组成员无法通过赋值的方式直接复制
            // 同时需要注意的是在使用 memcpy 前，如果 dest 指向的内存空间小于 src 所要复制的 n 个字节，那么将会出现内存越界错误。
            // 当越过 dest 指向的内存空间的边界时，会导致访问未分配的内存，这可能会导致程序崩溃或者其他不可预知的错误。
            // 为了避免这种错误，在使用 memcpy 函数时应该确保目标内存空间足够大，或者使用其他函数如memmove来避免内存重叠。
            // 因此在调用memcpy之前，最好先检查下目标内存空间是否足够，如果不够就先重新分配内存。
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
