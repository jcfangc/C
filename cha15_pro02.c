// 修改 15.3 节的 justify 程序，在 read_word 函数（而不是 main 函数）中为被截短的单词的结尾存储 * 字符
#include <stdio.h>

#define STR_LEN 5

int read_char(void);
void read_word(char *, int);

int main(void)
{
    char str[STR_LEN] = "\0";

    printf("\n\t Enter a word: ");
    read_word(str, STR_LEN);

    printf("\n\t %s", str);

    getchar();
    return 0;
}

/* 原 read_char 函数 */
int read_char(void)
{
    int ch = getchar();

    if (ch == '\n' || ch == '\t') {
        return ' ';
    }

    return ch;
}

void read_word(char *word, int len)
{
    int ch, pos = 0;

    while ((ch = read_char()) == ' ') {
        ;
    }
    while (ch != ' ' && ch != EOF) {
        if (pos < len - 1) {
            word[pos++] = ch;
        }
        else if (pos == (len - 1)) {
            word[pos++] = '*';
        }
        ch = read_char();
    }
    word[pos] = '\0';
}

/* 原 read_word 函数 */
// void read_word(char *word, int len)
// {
//     int ch, pos = 0;

//     while ((ch = read_char()) == ' ') {
//         ;
//     }
//     while (ch != ' ' && ch != EOF) {
//         if (pos < len) {
//             word[pos++] = ch;
//         }
//         ch = read_char();
//     }
//     word[pos] = '\0';
// }