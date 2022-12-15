// 按如下方式改进 13.5 的 remind.c 程序。
// （a）如果对应的日期为负数或大于 31，系统就会显示出错信息，并忽略提醒。提示：使用 continue 语句。
// （b）允许用户输入日期、24 小时格式的时间和提示。显示的提醒列表必须先按日期排序，然后再按时间排序。（原始的 remind.c 程序允许用户输入时间，但是它把时间作为提醒的一部分来处理。）
// （c）程序显示一年的提醒列表。要求用户按照月 / 日的格式输入日期。

#include <stdio.h>
#include <string.h>

#define MSG_NUM 50
#define MSG_LEN 50
#define DATE_LEN 6
#define TIME_LEN 6

// 读字符串
int read_line(char *, int);
// 时间顺序排序
void make_chronological(char(*)[MSG_LEN + DATE_LEN + TIME_LEN], char *);

int main(void)
{
    char remind_box[MSG_NUM][MSG_LEN + DATE_LEN + TIME_LEN] = { {'\0'} };
    char new_remind[MSG_LEN + DATE_LEN + TIME_LEN] = { '\0' };
    int month, day, hour, min, num = 0;
    char date[DATE_LEN], time[TIME_LEN], msg[MSG_LEN];

    while (num < MSG_NUM) {
        // 得到必要信息
        printf("\n\t Enter message: (0 to end) ");
        read_line(msg, MSG_LEN);
        if (strcmp(msg, "0") == 0) {
            break;
        }
        printf("\n\t Enter date: (mm/dd) ");
        scanf(" %2d/%2d", &month, &day);
        getchar();
        // 如果对应的日期为负数或大于 31，系统就会显示出错信息，并忽略提醒。
        if (day > 31 || day < 0) {
            printf("\t Wrong day. \n");
            continue;
        }
        printf("\n\t Enter time: (<24-hour>hh:mm) ");
        scanf(" %2d:%2d", &hour, &min);
        getchar();

        // 信息整理入格式串
        sprintf(date, "%2d/%2.2d", month, day);
        sprintf(time, "%2d:%2.2d", hour, min);
        // 已经计算好了每个字符串的长度，所以就没有使用 strncat 和 strncpy
        strcat(strcat(strcat(strcat(strcpy(new_remind, date), " "), time), " "), msg);

        // 时间排序备忘录
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
    // 录入第一条备忘
    if (strcmp(*(remindings + 0), "\0") == 0) {
        strcpy(*(remindings + 0), new_remind);
        return;
    }

    // 略过空备忘录
    char(*p)[MSG_LEN + DATE_LEN + TIME_LEN] = remindings + MSG_NUM - 1;
    while (strcmp(*(p - 1), "\0") == 0 && p > remindings) {
        p--;
    }

    // 移动更未来的备忘录
    while (strcmp(*(p - 1), new_remind) >= 0 && p > remindings) {
        strcpy(*(p), *(p - 1));
        p--;
    }

    // 空位插入当前新备忘
    strcpy(*(p), new_remind);
    return;
}