// 参考这里给出的字母在键盘上的对应关系: 2 = ABC，3 = DEF，4 = GHI, 5 = JKL，6 = MNO，7 = PQRS，8 = TUV，9 = WXYZ
// 相应的字母可以转换成数字
#include <stdio.h>
#include <ctype.h>

// 可以接受的最长的电话号码
#define NUM_SIZE 20

int main(void)
{
    // 用行号对应相应的数字
    char reference_form[10][4] = { {0}, {0}, {'A','B','C'}, {'D','E','F'}, {'G','H','I'}, {'J','K','L'}, {'M','N','O'}, {'P','Q','R','S'}, {'T','U','V'}, {'W','X','Y','Z'} };
    char ch;
    char phone_number[NUM_SIZE];
    int phone_length = 0;
    char number_sequence[10] = { '0','1','2','3','4','5','6','7','8','9' };

    printf("\n\t Enter phone number: ");

    // 惯用法：用 while 循环来录入信息直到遇见回车符为止
    while ((ch = getchar()) != '\n') {
        // 同时计算号码的长度
        phone_number[phone_length++] = toupper(ch);
    }

    // 当 i 小于号码长度之前持续录入
    for (int i = 0; i < phone_length; i++) {
        // 当输入的号码中包含 字母 时，下面的这部分循环就会起到遍历 reference_form 的作用 然后把该字母对应的行号转化位相应的数字
        for (int j = 2; j < 10; j++) {
            for (int k = 0; k < 4; k++) {
                if (phone_number[i] == reference_form[j][k]) {
                    phone_number[i] = number_sequence[j];
                }
            }
        }
    }

    // 打印变换后的电话号码
    printf("\n\t ");
    for (int i = 0; i < phone_length; i++) {
        printf("%c", phone_number[i]);
    }

    getchar();
    printf("\n\n");
    return 0;
}