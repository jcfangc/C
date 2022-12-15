// ��д�����ҳ�һ�鵥���� ����С�� ���ʺ� ����� ���ʡ��û����뵥�ʺ󣬳�������ֵ�˳�����������ǰ��������ĵ��ʡ����û����� 4 ����ĸ�ĵ���ʱ������ֹͣ���롣���е��ʶ������� 20 ����ĸ������Ự���£�

// Enter word: dog
// Enter word: zebra
// Enter word: rabbit
// Enter word: catfish
// Enter word: walrus
// Enter word: cat
// Enter word: fish

// Smallest word: cat
// Largest word: zebra

// ��ʾ��ʹ��������Ϊ smallest_word �� largest_word ���ַ������ֱ��¼�������е� ����С�� ���ʺ� ����� ���ʡ��û�ÿ����һ���µ��ʣ���Ҫ�� strcmp ���������� smallest_word ���бȽϡ�����µĵ��ʱ� smallest_word ��С�������� strcpy �������µ��ʱ��浽 smallest_word �С������Ƶķ�ʽ�� largest_word ���бȽϡ��� strlen �������ж��û��Ƿ������� 4 ����ĸ�ĵ��ʡ�

#include <stdio.h>
#include <string.h>

#define LETTER_MAX 20
#define LARGE_ROW 0
#define SMALL_ROW 1

// �Ƚϵ��ʴ�С�ĺ���������ָ�� 2*LETTER_MAX �ַ������ָ�룬�������зֱ�¼�����ĵĵ��ʺ���С�ĵ���
void word_comparator(char *);
// ��ȡ����
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

    // ��һ�ν��бȽ�ʱ��û�жԱȵĵ���
    if (!times++) {
        strcpy(*(box_ptr + LARGE_ROW), new_word);
        strcpy(*(box_ptr + SMALL_ROW), new_word);
        return;
    }

    if (strcmp(new_word, *(box_ptr + LARGE_ROW)) > 0) {
        // ¼�������˵��ʴ�С�����Բ���Ҫ strncpy
        strcpy(*(box_ptr + LARGE_ROW), new_word);
    }
    else if (strcmp(*(box_ptr + SMALL_ROW), new_word) > 0) {
        strcpy(*(box_ptr + SMALL_ROW), new_word);
    }
}

// �����ߴ𰸣�http://knking.com/books/c2/answers/c13.html

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

// ���������� strcpy �ķ�ʽ���Խ�ʡһ�д��룬�ǲο����б�����Ϊ�����������