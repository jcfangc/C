// 这个程序可以将你录入的句子反向打印出来
#include <stdio.h>

#define N 100

int main(void)
{
    char ch;
    char sentence[N] = { '\0' };
    int sentence_length = 0;
    char terminate_char;

    printf("\n\t Enter your sentence: ");

    // 录入句子，和终止符号
    // while (1) {
    //     ch = getchar();
    //     if (ch != '.' && ch != '!' && ch != '?') {
    //         if (sentence_length < N) {
    //             sentence[sentence_length++] = ch;
    //         }
    //     }
    //     else {
    //         terminate_char = ch;
    //         break;
    //     }
    // }

    // 这一段程序和上一段被注释掉的程序效果相同
    while ((ch = getchar()) != '\n') {
        sentence[sentence_length++] = ch;
    }
    if (sentence[sentence_length - 1] == '.' || sentence[sentence_length - 1] == '?' || sentence[sentence_length - 1] == '!') {
        terminate_char = sentence[sentence_length - 1];
        sentence[sentence_length-- - 1] = '\0';
    }
    

    printf("\n\t ");
    // 一个扫描的坐标（i），一个打印的坐标（j）
    for (int i = (sentence_length - 1); i >= 0; i--) {
        // 倒数第一个单词到第二个单词的打印
        // 由 i 来找到一个单词前面的空格处
        // 由 j 来打印该空格后面的单词
        if (sentence[i] == ' ') {
            int j = i + 1;
            // 在 j 遇到下一个单词前的空格位时停止打印
            do {
                if (j < sentence_length) {
                    printf("%c", sentence[j++]);
                }
                else {
                    break;
                }
            } while (sentence[j] != ' ');
            printf(" ");
        }

        // 打印句首第一个单词
        // 句首第一个单词之前没有空格，它的处理逻辑要分列出来
        // 如果想要避免这个分列出来的处理我们在可以录入句子的数组最前面由程序自主添加一个空格
        if (i == 0) {
            int j = i;
            do {
                if (j < sentence_length) {
                    printf("%c", sentence[j++]);
                }
                else {
                    break;
                }
            } while (sentence[j] != ' ');
        }
    }

    // 打印句尾的标点符号
    printf("%c", terminate_char);

    getchar();
    printf("\n\n");
    return 0;
}