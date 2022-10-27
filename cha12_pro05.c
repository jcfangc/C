// 修改第 8 章的编程题 14，用指针而不是整数来跟踪包含该语句的数组的当前位置。

// 第 8 章的编程题 14：
// 编写程序颠倒句子中单词的顺序：

// Enter a sentence: you can cage a swallow can't you?
// Reversal of sentence: you can't swallow a cage can you?

// 提示：用循环逐个读取字符，然后把它们存储在一个意为字符数组中。当遇到句号。问好或者感叹号（称为 “终止字符”）时，终止循环并把终止字符存储在一个 char 类型变量中。然后用一个循环反向搜索数组，找到最后一个单词的起始位置。显示最后一个单词，然后反向搜索倒数第二个单词。重复这一过程，直到达到数组的起始位置。最后显示出终止字符。


#include <stdio.h>

#define MAX_LEN 50

int main(void)
{
    char terminal;
    char sentence[MAX_LEN];
    char(*letter) = sentence;

    // 录入字符到数组中
    printf("\n\t Enter a sentence: ");
    while ((terminal = getchar()) != '.' && terminal != '!' && terminal != '?') {
        *letter++ = terminal;
    }
    getchar(); // '\n'

    printf("\n\t ");
    // 录入结束，找到数组中的空格，并打印空格后的单词
    /* 意识到这个循环是不会包括句首的第一个单词的，因为句首单词前没有空格 */
    char(*space);
    char(*printer);
    for (space = (letter - 1); space >= sentence; space--) {
        if ((*space) == ' ') {
            for (printer = (space + 1); printer < letter; printer++) {
                /* 考虑到中间单词之间有空格的一般情况 */
                if ((*printer) == ' ') {
                    printf(" ");
                    break;
                }
                /* 句尾单词的特殊情况 */
                else if (printer == (letter - 1)) {
                    printf("%c ", (*printer));
                    break;
                }
                /* 打印字母组成单词 */
                else {
                    printf("%c", (*printer));
                }
            }
        }
    }
    /* 循环结束前，控制流会重新回到循环条件的命令行，之后 space 指针会额外进行一次加法运算 */

    // 输出第一个单词和终止字符
    for (printer = (space + 1); printer < letter; printer++) {
        if ((*printer) == ' ') {
            break;
        }
        printf("%c", (*printer));
    }
    printf("%c", terminal);

    getchar();
    return 0;
}