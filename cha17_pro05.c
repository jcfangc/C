// 编写程序对用户输入的一系列单词排序：
    // Enter word: foo
    // Enter word: bar
    // Enter word: baz
    // Enter word: quux
    // Enter word: 

    // In sorted order: bar baz foo quux
// 假设每个单词不超过 20 个字符。当用户输入空单词（即敲击回车键而没有录入任何单词）时停止读取。把每个单词存储在一个动态分配的字符串中，像 remind2.c 程序（17.2 节）那样用一个指针数组来跟踪这些字符串。读完所有单词后对数组排序（可以使用任何排序算法），人后用一个循环按存储顺序显示这些单词。提示：像 remind2.c 那样，使用 read_line 函数读取每个单词。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 23
#define WORD_MAX 5

int word_num = 0;

void expand_array(char ***, int);
int read_line(char **);
void sort_words(char *[WORD_MAX]);
static int compare_word(const void *, const void *);
void print_words(char *[WORD_MAX]);

int main(void)
{
    int full_times = 1;
    char *words[WORD_MAX];

    for (;;) {
        printf("\t Enter word: ");
        if (word_num == full_times * WORD_MAX) {
            full_times++;
            expand_array(&words, full_times);
        }
        if (read_line(words + word_num) == 0) {
            word_num--;
            // 当用户只键入回车符时退出循环
            break;
        }
    }

    sort_words(words);
    print_words(words);

    getchar();
    return 0;
}

void expand_array(char ***ptr_words, int times)
{
    // 注意我们这里需要重新分配的内存是 words 的内存，而非指向 words 的 ptr_words 的内存，不能遗漏简介取址符
    *ptr_words = realloc(*ptr_words, times * WORD_MAX * sizeof(char *));
    if (ptr_words == NULL) {
        printf("\t No memery avalible. \n");
        getchar();
        exit(EXIT_FAILURE);
    }
    else {
        // 这里被注释掉的内容和没有被注释的内容可以相互替代，是两种不同的方案，然而第二个方案有可能会引起 temp 这个变量没有被使用的警告。
        for (int i = (times - 1) * WORD_MAX; i < times * WORD_MAX; i++) {
            (*ptr_words)[i] = calloc(1, sizeof(char *));
        }
        // char **temp = ((*ptr_words) + ((times - 1) * WORD_MAX));
        // temp = calloc(WORD_MAX, sizeof(char *));
    }
}

int read_line(char **the_word)
{
    char ch, word[MAX_WORD_LEN] = "";
    int count = 0;
    // 录入字母形成单词
    while ((ch = getchar()) != '\n' && count < MAX_WORD_LEN - 2) {
        word[count++] = ch;
    }
    // 索引 21 必须存放 ‘*’
    if (count == MAX_WORD_LEN - 2) {
        word[count++] = '*';
    }
    // 添加保险空字符，字符串完成
    word[count] = '\0';
    word_num++;
    // 动态数组申请内存
    *the_word = calloc(1, (count + 1) * sizeof(char));
    if (*the_word != NULL) {
        // 复制字符串
        strcpy(*the_word, word);
        return (int)strlen(*the_word);
    }
    else {
        printf("\t No memery avalible. \n");
        getchar();
        exit(EXIT_FAILURE);
    }
}

void sort_words(char *words[WORD_MAX])
{
    qsort(words, word_num, sizeof(char *), compare_word);
}

static int compare_word(const void *p, const void *q)
{
    // 由于 p q 本身是一个指针，他们要指向 words 中的若干个指针，所以在这里已经决定了 p q 的本质上是指针的指针。
    // 这也决定了 p q 不可以被单纯强制转换为 (const char *)，因为这个类型并不是指针的指针。
    return strcmp(*(const char **)p, *(const char **)q);
    // return strcmp(*(char *const *)p, *(char *const *)q);
    // (const char **) 和 (char * const *) 强制转换的区别在于它们表示的是指针类型的不同。
    // 前者表示指向常量字符串的指针，而后者表示指向字符串的常量指针。
    // 在qsort函数中，需要交换的是指针数组中指针的顺序，而不是指针所指向的字符串。所以(char *const *) 和 *(const char **)在这里都可以正常工作。
}

void print_words(char *words[WORD_MAX])
{
    printf("\t ");
    for (int i = 0; i < word_num; i++) {
        printf("%s ", words[i]);
    }
}