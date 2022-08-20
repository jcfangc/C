// 输入名字（限字母），程序会按照相应的格式返还你的名字
#include <stdio.h>
#include <ctype.h>

#define NAME_SIZE 20

int main(void)
{
    // 设置数组分别存储名和姓
    char firstname[NAME_SIZE];
    char lastname[NAME_SIZE];
    int firstname_length = 0, lastname_length = 0;
    char ch;

    printf("\n\t Enter you entire name: ");

    // 惯用法，在遇到空格时停止录入字符
    while ((ch = getchar()) != ' ') {
        firstname[firstname_length++] = toupper(ch);
    }

    // 在遇到换行符之前录入字符
    while ((ch = getchar()) != '\n') {
        lastname[lastname_length++] = toupper(ch);
    }

    // 打出姓
    printf("\n\t ");
    for (int i = 0; i < lastname_length; i++) {
        printf("%c", lastname[i]);
    }

    // 打出名的首字母
    printf(", ");
    printf("%c", firstname[0]);
    printf(". ");

    getchar();
    printf("\n\n");
    return 0;
}