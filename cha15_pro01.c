// 15.3 节的 justify 程序通过在单词间插入额外的空格来调整行。当前编写的函数 writen_1ine 的工作方法是，与开始处的单词间隔相比，靠近行末尾单词的间隔略微宽一些。（例如，靠近末尾的单词彼此之问可能有 3 个空格，而靠近开始的单词彼此之间可能只有 2 个空格。）请修改函数 write_line 来改进此程序，要求函数能够使较大的间隔交替出现在行的末尾和行的开头。

#include <stdio.h>
#include <string.h>

#define MAX_LEN 60

void write_line(void);
int word_num(char[], int);
int move(char *, char[], int);

char line[MAX_LEN + 1] = "I love you, do you love me?";
int line_len;
int num_words;

int main(void)
{
    line_len = strlen(line);
    num_words = word_num(line, (int)sizeof(line));

    write_line();

    getchar();
    return 0;
}

// 参考答案部分
void write_line(void)
{
    /* 用于存放空格仓库 */
    int space_store = MAX_LEN - line_len;

    /* 用于容纳原字符串的副本 */
    char line_copy[MAX_LEN + 1];
    strncpy(line_copy, line, MAX_LEN);
    line_copy[MAX_LEN] = '\0';

    /* 两个位置对称的指针 */
    char *left, *right;
    left = line_copy;
    right = line_copy + line_len;

    /* 向副本中添加空格 */
    while (space_store) {
        /* 搜索空格 */
        while ((*left) != ' ') {
            left++;
        }
        /* 当两个指针相遇后便重置 */
        if (left >= right) {
            left = line_copy;
            right = line_copy + line_len;
            continue;
        }
        /* 插入空格 */
        if (space_store) {
            /* move 函数用于将指针所指之后的字符都向后移动一个位置，当指针指向空格时，会造成添加空格的效果。 */
            /* move 返回当前字符串内容的长度。 */
            line_len = move(left, line_copy, line_len);
            /* 将 left 转移至下一单词处 */
            while ((*left) == ' ') {
                left++;
            }
            /* right 放回原本所指单词的单词尾 */
            right++;
            if (!(--space_store)) {
                break;
            }
        }
        /* 搜索空格 */
        while ((*right) != ' ') {
            right--;
        }
        /* 当两个指针相遇后便重置 */
        if (left >= right) {
            left = line_copy;
            right = line_copy + line_len;
            continue;
        }
        /* 插入空格 */
        if (space_store) {
            /* move 函数用于将指针所指之后的字符都向后移动一个位置，当指针指向空格时，会造成添加空格的效果。 */
            /* move 返回当前字符串内容的长度。 */
            line_len = move(right, line_copy, line_len);
            /* right 传递至下一单词尾部 */
            while ((*right) == ' ') {
                right--;
            }
            if (!(--space_store)) {
                break;
            }
        }
    }

    /* 输出两端对齐的副本 */
    printf("\n\t %s", line_copy);
}

int move(char *label, char arr[], int len)
{
    char *p = arr + len;

    /* 标记位置之后的内容向后移动一位 */
    for (; p > label; p--) {
        (*p) = (*(p - 1));
    }

    return (int)strlen(arr);
}

// void write_line(void)
// {
//     int extra_space, space_to_insert, i, j;

//     printf("\n\t ");
//     extra_space = MAX_LEN - line_len;
//     for (i = 0; i < line_len; i++) {
//         if (line[i] != ' ') {
//             putchar(line[i]);
//         }
//         else {
//             space_to_insert = extra_space / (num_words - 1);
//             for (j = 1; j <= space_to_insert + 1; j++) {
//                 putchar('*');
//             }
//             extra_space -= space_to_insert;
//             num_words--;
//         }
//     }
// }

int word_num(char str[], int len)
{
    int num = 0;

    for (int i = 0; i < len - 1; i++) {
        if (str[i] != ' ' && str[i + 1] == ' ') {
            num += 1;
        }
    }

    return (num + 1); // last word
}