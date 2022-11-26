// 修改第 8 章的编程题 16，使其包含如下函数：
// bool are_anagrams(const char *word1, const char *word2);
// 如果 word1 和 word2 指向的字符串是变位词，函数返回 ture。

// 第 8 章的编程题 16：
// 编程测试两个单词是否为变位词（相同字母的重新排列）

// Enter first word: smartest
// Enter second word: mattress
// The words are anagrams.

// Enter first word: dumbest
// Enter second word: stumble
// The words are not anagrams.

// 用一个循环逐个字符地读取第一个单词， 用一个 26 元的整数数组记录每个字母的出现次数。( 例如，读取单词 smartest 之后，数组包含的值为 10001000000100000122000000，表明 smartest 包含一个 a、一个 e、一个 m、一个 r、两个 s 和两个 t。）用另一个循环读取第二个单词，这次每读取一个字母就把相应数组元素的值减 1。两个循环都应该忽略不是字母的那些字符，并且不区分大小写。第二个单词读取完毕后，再用一个循环来检查数组元素是否为全 0。如果是全 0，那么这两个单词就是变位词。提示：可以使用 <ctype.h> 中的函数，如 isalpha 和 tolower。

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define WORD_LEN 30

bool are_anagrams(const char *, const char *);
int read_line(char[], int);

int main(int argc, char *argv[])
{
    // 初始化
    char word1[WORD_LEN] = "", word2[WORD_LEN] = "";

    // 单词录入
    printf("\n\t Enter first word: ");
    read_line(word1, WORD_LEN);
    printf("\t Enter second word: ");
    read_line(word2, WORD_LEN);

    // 根据函数结果输出
    if (are_anagrams(word1, word2)) {
        printf("\n\t The words are anagrams. ");
    }
    else {
        printf("\n\t The words are not anagrams. ");
    }

    getchar();
    return 0;
}

int read_line(char str[], int str_len)
{
    char *p = str;
    char ch;

    while (((ch = getchar()) != '\n') && (p < str + str_len)) {
        *p++ = ch;
    }

    *p = '\0';
    return (int)(p - str);
}

// 和题目提示的算法不相同
bool are_anagrams(const char *word1, const char *word2)
{
    // 单词长度相等时，下面逻辑才成立
    if (strlen(word1) != strlen(word2)) {
        return false;
    }

    const char *p1 = word1, *p2;
    /* miss 用来说明两个单词当时的对应状态，有字母对应不上时，miss 为真 */
    bool miss = false;
    /* 对应上的字母下次将不再检测 */
    bool checked[WORD_LEN] = { false };

    /* p1 指向空字符时停止循环 */
    while (*p1) {
        p2 = word2;
        while ((*p2)) {
            /* 对应位置的字母已经对应上后，check 数组相应位置为 true，则不应再次检测 */
            if (checked[(int)(p2 - word2)] == true) {
                p2++;
                continue;
            }
            /* 大小写在本程序中并不区分，只要是同一个字母即可 */
            else if ((*p1) == tolower(*p2) || (*p1) == toupper(*p2)) {
                /* 当前 p2 所指向的和 p1 相对应，在 checked 数组中进行标记 */
                checked[(int)(p2 - word2)] = true;
                break;
            }
            /* 当前 p2 指向的字母和 p1 指向的字母不相同，检查下一个字母 */
            else { p2++; }
        }
        /* 当 p2 指向空字符时执行本条命令，空字符在字符串末尾，遍历至此说明 word2 中没有对应字母 */
        if (!(*p2)) { return miss; }
        p1++;
    }

    return !miss;
}