// 凯撒加密
#include <stdio.h>

#define SEN_SIZE 100

int main(void)
{
    char ch;
    char sentence[SEN_SIZE] = { '\0' };
    int sentence_length = 0;
    int shift_amount;
    int decrypted_number;

    // 为了不依赖电脑的字母表，自己在此建立一个字母表
    char alphabet[2][26] = {
        { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' },
        { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' }
    };
    int case_index, sequence_index;

    printf("\n\t Enter message to be encrypted: ");

    // 录入句子
    while ((ch = getchar()) != '\n') {
        sentence[sentence_length++] = ch;
    }

    // 了解移动位数
    printf("\n\t Enter shift amount: ");
    scanf(" %d", &shift_amount);
    getchar();

    /* 移动方法：
    首先扫描句字，得到字母，用一个变量承载对应字母表中的定位 e.g. x 对应 [2][23]
    其次计算新定位 e.g. 移动 5 位，应该对应 [2][1] 即 b
    计算通式：sequence_index = ((sequence_index + shift_amount) % 26)
    如此循环，直到历遍句子中的每一个字母 */

    for (int i = 0; i < sentence_length; i++) {
        ch = sentence[i];
        // 无法加密的内容直接跳过
        if (ch == ' ' || ch == '.' || ch == '?' || ch == '!' || ch == '\"' || ch == '\'' || ch == ',') {
            continue;
        }
        else if (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9') {
            continue;
        }
        // 字母相关的内容通过以下方式遍历和加密
        else {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 26; k++) {
                    // 通过遍历找到字母相应的序号（字母表中的序号）
                    if (ch == alphabet[j][k]) {
                        case_index = j;
                        sequence_index = k;
                    }
                }
            }
            // 在这一步进行加密操作
            sequence_index = ((sequence_index + shift_amount) % 26);
            sentence[i] = alphabet[case_index][sequence_index];
        }
    }

    // 输出加密的信息
    printf("\n\t ");
    for (int i = 0; i < sentence_length; i++) {
        printf("%c", sentence[i]);
    }

    // 给出解密的数字
    if (shift_amount <= 26) {
        decrypted_number = (26 - shift_amount);
    }
    else {
        decrypted_number = (26 - (shift_amount % 26));
    }
    printf("\n\n\t The decrypted number is: %d", decrypted_number);


    printf("\n\n\t Press Enter to end. ");
    (void)getchar();
    printf("\n\n");
    return 0;
}