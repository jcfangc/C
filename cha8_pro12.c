// 这个版本的代码有更好的可移植性。上一版本的代码依赖于 字符集 上的字母排序是连续的。
// 该程序根据你输入的单词给你相应的分数
#include <stdio.h>
#include <ctype.h>

#define WORD_SIZE 20

int main(void)
{
    char letter_value[11][10] = {
        {0},
        {'A','E','I','L','N','O','R','S','T','U'},
        {'D','G'},
        {'B','C','M','P'},
        {'F','H','V','W','Y'},
        {'K'},
        {0},
        {0},
        {'J','X'},
        {0},
        {'Q','Z'}
    };
    char ch;
    char entered_word[WORD_SIZE];
    int word_length = 0;
    int word_value = 0;

    printf("\n\t Enter a word: ");

    // 惯用法：还是在遇见换行符之前持续录入字符，但是多了一个条件，录入的字符数量小于最大的字母数
    while ((ch = getchar()) != '\n') {
        for (; word_length < WORD_SIZE;) {
            entered_word[word_length++] = toupper(ch);
            break;
        }
    }

    // 开始计算相应的字母得分
    for (int i = 0; i < word_length; i++) {
        for (int j = 0; j < 11; j++) {
            // 这几个分数没有相应的字母，可以直接跳过
            if (j == 0 || j == 6 || j == 7 || j == 9) {
                continue;
            }
            // 来到这一步的分数都有相应的字母
            for (int k = 0; k < 10; k++) {
                // 分数 1 对应了 10 个字母，但是其他则没有
                if (letter_value[j][k] == 0) {
                    break;
                }
                // 对应分数累加
                if (entered_word[i] == letter_value[j][k]) {
                    word_value += j;
                    break;
                }
            }
        }
    }

    // 打印分数
    printf("\n\t Scrannle value: %d", word_value);

    getchar();
    printf("\n\n");
    return 0;
}