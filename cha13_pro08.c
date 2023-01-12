// 修改第 7 章的编程题 5，使其包含如下函数：
// int compute_scrabble_value(const char* word);
// 函数返回 word 所指向的字符串的拼字值。

// 第 7 章 编程题 5：
// 在十字拼字游戏中，玩家利用小卡片组成单词，每个卡片包含字母和面值。面值根据字母稀缺程度的不同而不同。（面值有：1 —— AEILNORSTU，2 —— DG，3 —— BCMP，4 —— FHVWY，5 —— K，8 —— JX，10 —— QZ。）编写程序通过对单词中字母的面值求和来计算单词的值：
// Enter a word: pitfall
// Scrabble value: 12
// 编写的程序应该允许单词中混合出现大小写字母。提示：使用 toupper 库函数。


#include <stdio.h>
#include <ctype.h>

#define WORD_LEN 30

int compute_scrabble_value(const char *);

int main(int argc, char *argv[])
{
    char entered_word[WORD_LEN];

    printf("\n\t Enter a word: ");
    scanf(" %s", entered_word);
    getchar(); // '\n'

    printf("\n\t Scrabble value: %d ", compute_scrabble_value(entered_word));

    getchar();
    return 0;
}

int compute_scrabble_value(const char *word)
{
    char *trans[10] = { "AEILNORSTU", "DG", "BCMP", "FHVWY", "K", "", "", "JX", "", "QZ" };
    const char *p = word;
    int value = 0;

    while (*p) { // 惯用法，相当于 while(*p != '\0')p
        for (int i = 0; i < 10; i++) {
            if (i != 5 && i != 6 && i != 8) { /* 跳过数组中无意义的部分 */
                char *k = trans[i];
                while (*k) { // 惯用法，相当于 while(*k != '\0')
                    if (toupper(*p) == *k) { // 逐字符比较
                        value += (i + 1);
                        goto NEXTLETTER;
                    }
                    k++; // 指针运算
                }
            }
        }
    NEXTLETTER: p++; // 指针运算
    }

    return value;
}