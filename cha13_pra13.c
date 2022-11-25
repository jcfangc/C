// 修改第 8 章的编程题 15，使其包含如下函数：
// void encrypt(char *message, int shift);
// 参数 message 指向一个包含加密信息的字符串，shift 表示信息中每个字母需要移动的位数。

// 第 8 章的编程题 15：
// 已知的最古老的一种加密技术是凯撒加密（得名于Julius Caesar）。该方法把一条消息中的每个字母用字母表中固定距离之后的那个字母来替代。(如果越过了字母 Z，会绕回到字母表的起始位置。例如，如果每个字母都用字母表中两个位置之后的字母代替，那么 Y 就被替换为 A，Z 就被替换为 B。 )编写程序用凯撒加密方法对消息进行加密。用户输入待加密的消息和移位计数(字母移动的位置数目) :

// Enter message to be encrypted: Go ahead, make my day.
// Enter shift amount (1-25): 3
// Encrypted message: Jr dkhdg, pdnh pb gab.

// 注意，当用户输入26与移位计数的差值时，程序可以对消息进行解密:
// Enter message to be encrypted: Jr dkhdg, pdnh pb gdb.
// Enter shift amount (1-25): 3
// Encrypted message: Go ahead, make my day .

// 可以假定消息的长度不超过 80 个字符。不是字母的那些字符不要改动。此外，加密时不要改变字母的大小写。提示：为了解决前面提到的绕回问题，可以用表达式 ((ch- ‘A’) + n) % 26+ 'A 计算大写字母的密码，其中 ch 存储字母，n 存储移位计数。（小写字母也需要一个类似的表达式。)

#include <stdio.h>
#include <ctype.h>

#define MESSAGE_LEN 120

int read_line(char[], int);
void encrypt(char *, int);

int main(int argc, char *argv[])
{
    // 初始化
    char message[MESSAGE_LEN] = "";
    int phase;

    // 录入语句
    printf("\n\t Enter message to be encrypted: ");
    int sent_len = read_line(message, MESSAGE_LEN);

    // 输入移动相位
    printf("\n\t Enter shift amount (1-25): ");
    scanf("%d", &phase);
    getchar(); // '\n'
    encrypt(message, phase);

    // 打印加密信息
    printf("\n\t Encrypted message: ");
    for (int i = 0; i < sent_len; i++) {
        printf("%c", message[i]);
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

void encrypt(char *message, int shift)
{
    // 内置字母表，不依赖于系统字符
    char alphabet[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
    char(*position), (*replace);

    // 遍历 message 中的每个字符
    for (position = message; position < message + MESSAGE_LEN; position++) {
        // 处理到字符串末端
        if ((*position) == '\0') { break; }
        // 内容为小写时
        if (islower(*position)) {
            // 找到字母表中的对应文字
            for (replace = alphabet; replace < alphabet + 26; replace++) {
                if ((*position) != tolower(*replace)) { continue; }
                // 找到对应字符时
                else if ((*position) == tolower(*replace)) {
                    // 根据相位移动替换字母
                    (*position) = tolower(*(alphabet + (((int)(replace - alphabet) + shift) % 26)));
                    break;
                }
            }
        }
        // 内容为大写时
        else if (isupper(*position)) {
            // 找到字母表中的对应文字
            for (replace = alphabet; replace < alphabet + 26; replace++) {
                if ((*position) != (*replace)) { continue; }
                // 找到对应字符时
                else if ((*position) == (*replace)) {
                    // 根据相位移动替换字母
                    (*position) = (*(alphabet + (((int)(replace - alphabet) + shift) % 26)));
                    break;
                }
            }
        }
        // 标点符号等
        else { continue; }
    }
}