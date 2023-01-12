// ��д������û������һϵ�е�������
    // Enter word: foo
    // Enter word: bar
    // Enter word: baz
    // Enter word: quux
    // Enter word: 

    // In sorted order: bar baz foo quux
// ����ÿ�����ʲ����� 20 ���ַ������û�����յ��ʣ����û��س�����û��¼���κε��ʣ�ʱֹͣ��ȡ����ÿ�����ʴ洢��һ����̬������ַ����У��� remind2.c ����17.2 �ڣ�������һ��ָ��������������Щ�ַ������������е��ʺ���������򣨿���ʹ���κ������㷨�����˺���һ��ѭ�����洢˳����ʾ��Щ���ʡ���ʾ���� remind2.c ������ʹ�� read_line ������ȡÿ�����ʡ�

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
            // ���û�ֻ����س���ʱ�˳�ѭ��
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
    // ע������������Ҫ���·�����ڴ��� words ���ڴ棬����ָ�� words �� ptr_words ���ڴ棬������©���ȡַ��
    *ptr_words = realloc(*ptr_words, times * WORD_MAX * sizeof(char *));
    if (ptr_words == NULL) {
        printf("\t No memery avalible. \n");
        getchar();
        exit(EXIT_FAILURE);
    }
    else {
        // ���ﱻע�͵������ݺ�û�б�ע�͵����ݿ����໥����������ֲ�ͬ�ķ�����Ȼ���ڶ��������п��ܻ����� temp �������û�б�ʹ�õľ��档
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
    // ¼����ĸ�γɵ���
    while ((ch = getchar()) != '\n' && count < MAX_WORD_LEN - 2) {
        word[count++] = ch;
    }
    // ���� 21 ������ ��*��
    if (count == MAX_WORD_LEN - 2) {
        word[count++] = '*';
    }
    // ��ӱ��տ��ַ����ַ������
    word[count] = '\0';
    word_num++;
    // ��̬���������ڴ�
    *the_word = calloc(1, (count + 1) * sizeof(char));
    if (*the_word != NULL) {
        // �����ַ���
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
    // ���� p q ������һ��ָ�룬����Ҫָ�� words �е����ɸ�ָ�룬�����������Ѿ������� p q �ı�������ָ���ָ�롣
    // ��Ҳ������ p q �����Ա�����ǿ��ת��Ϊ (const char *)����Ϊ������Ͳ�����ָ���ָ�롣
    return strcmp(*(const char **)p, *(const char **)q);
    // return strcmp(*(char *const *)p, *(char *const *)q);
    // (const char **) �� (char * const *) ǿ��ת���������������Ǳ�ʾ����ָ�����͵Ĳ�ͬ��
    // ǰ�߱�ʾָ�����ַ�����ָ�룬�����߱�ʾָ���ַ����ĳ���ָ�롣
    // ��qsort�����У���Ҫ��������ָ��������ָ���˳�򣬶�����ָ����ָ����ַ���������(char *const *) �� *(const char **)�����ﶼ��������������
}

void print_words(char *words[WORD_MAX])
{
    printf("\t ");
    for (int i = 0; i < word_num; i++) {
        printf("%s ", words[i]);
    }
}