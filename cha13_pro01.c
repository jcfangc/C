// 编写程序找出一组单词中 “最小” 单词和 “最大” 单词。用户输入单词后，程序根据字典顺序决定排在最前面和最后面的单词。当用户输入 4 个字母的单词时，程序停止读入。所有单词都不超过 20 个字母。程序会话如下：

// Enter word: dog
// Enter word: zebra
// Enter word: rabbit
// Enter word: catfish
// Enter word: walrus
// Enter word: cat
// Enter word: fish

// Smallest word: cat
// Largest word: zebra

// 提示：使用两个名为 smallest_word 和 largest_word 的字符串来分别记录所输入中的 “最小” 单词和 “最大” 单词。用户每输入一个新单词，都要用 strcmp 函数把它与 smallest_word 进行比较。如果新的单词比 smallest_word “小”，就用 strcpy 函数把新单词保存到 smallest_word 中。用类似的方式与 largest_word 进行比较。用 strlen 函数来判断用户是否输入了 4 个字母的单词。

#include <stdio.h>
#include <string.h>

#define LETTER_MAX 20
#define LARGE_ROW 0
#define SMALL_ROW 1

// 比较单词大小的函数，返回指向 2*LETTER_MAX 字符数组的指针，数组两行分别录入最大的的单词和最小的单词
void word_comparator(char *);
// 读取单词
int read_word(char *, int);

// 0 LARGE 1 SMALL
static char word_box[2][LETTER_MAX] = { {'\0'} };

int main(void)
{
    char(*box_ptr)[LETTER_MAX] = word_box;
    char new_word[LETTER_MAX];
    int len = 0;

    do {
        printf("\n\t Enter a word: (4-letter word to end) ");
        len = read_word(new_word, LETTER_MAX);
        word_comparator(new_word);
    } while (len != 4);

    printf("\n\t Largest: %s ", *(box_ptr + LARGE_ROW));
    printf("\n\t Smallst: %s ", *(box_ptr + SMALL_ROW));

    getchar();
    return 0;
}

int read_word(char *new_word, int len)
{
    char ch, *p = new_word;

    while ((ch = getchar()) != '\n' && (int)(p - new_word) < len) {
        *p++ = ch;
    }

    *p = '\0';
    return (int)(p - new_word);
}

void word_comparator(char *new_word)
{
    char(*box_ptr)[LETTER_MAX] = word_box;
    static int times = 0;

    // 第一次进行比较时，没有对比的单词
    if (!times++) {
        strcpy(*(box_ptr + LARGE_ROW), new_word);
        strcpy(*(box_ptr + SMALL_ROW), new_word);
        return;
    }

    if (strcmp(new_word, *(box_ptr + LARGE_ROW)) > 0) {
        // 录入限制了单词大小，所以不需要 strncpy
        strcpy(*(box_ptr + LARGE_ROW), new_word);
    }
    else if (strcmp(*(box_ptr + SMALL_ROW), new_word) > 0) {
        strcpy(*(box_ptr + SMALL_ROW), new_word);
    }
}

// 书作者答案：http://knking.com/books/c2/answers/c13.html

// #include <stdio.h>
// #include <string.h>

// #define WORD_LEN 20

// void read_line(char str[], int n);

// int main(void)
// {
//     char smallest_word[WORD_LEN + 1],
//         largest_word[WORD_LEN + 1],
//         current_word[WORD_LEN + 1];

//     printf("Enter word: ");
//     read_line(current_word, WORD_LEN);
//     strcpy(smallest_word, strcpy(largest_word, current_word));

//     while (strlen(current_word) != 4) {
//         printf("Enter word: ");
//         read_line(current_word, WORD_LEN);
//         if (strcmp(current_word, smallest_word) < 0)
//             strcpy(smallest_word, current_word);
//         if (strcmp(current_word, largest_word) > 0)
//             strcpy(largest_word, current_word);
//     }

//     printf("\nSmallest word: %s\n", smallest_word);
//     printf("Largest word: %s\n", largest_word);

//     return 0;
// }

// void read_line(char str[], int n)
// {
//     int ch, i = 0;

//     while ((ch = getchar()) != '\n')
//         if (i < n)
//             str[i++] = ch;
//     str[i] = '\0';
// }

// 书作者连用 strcpy 的方式可以节省一行代码，是参考答案中笔者认为不错的做法。