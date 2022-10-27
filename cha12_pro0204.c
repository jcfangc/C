// (a) 编写程序读一条信息，然后检查这条信息是否是回文（消息中的字母从左往右看和从右往左看是一样的）：

// Enter a message: He lived as a devil, eh?
// Palindrome
// Enter a message: Madam, I am Adam.
// Not a palidrome

// 忽略所有不是字母的字符。用整型变量来跟踪数组中的位置。
// (b) 修改上述程序，使用指针代替整数来跟踪数组中的位置。

// 编程题 4：请利用数组名可以用作指针的实施简化编程题 2 的（b）程序。
// 参考答案改编自本章编程题 1，答案如下：

#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 30

int main(void)
{
    char ch;
    char message[MAX_LEN], alphabet[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
    char(*here), (*letter), (*there);

    here = message;

    for (;;) {
        printf("\n\t Enter a message: ");
        while ((ch = getchar()) != '\n') {
            if (here == message + MAX_LEN) {
                break;
            }
            /* 确保只录入字母有关的信息 */
            for (letter = alphabet; letter < alphabet + 26; letter++) {
                if ((*letter) == toupper(ch)) {
                    (*here++) = ch;
                }
            }
        }
        /* 确保存在输入的内容 */
        if (here > message) {
            break;
        }
    }

    /* 循环后调整指针指向数组末尾 */
    here--;
    there = message;

    do {
        if ((toupper(*there) == toupper(*here)) && (there < here)) {
            there++;
            here--;
            continue;
        }
        else if ((toupper(*there) != toupper(*here)) && (there < here)) {
            printf("\n\t Not a palidrome. ");
            getchar();
            return 0;
        }
    } while (there < here);

    printf("\n\t Palidrome. ");
    getchar();
    return 0;
}