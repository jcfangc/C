// (a) 编写名为 capitalize 的函数，把参数中的字母都改为大写字母。参数是空字符结尾的字符串，且此字符串可以包含任意字符不仅是字母。使用数组取下标操作访问字符串中的字符。提示：使用 toupper 函数（→23.5节）把每个字符转换成大写。

// (b) 重写 capitalize 函数，这次使用指针算数运算来访问字符串中的字符。

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define STR_LEN 60

void capitalize(char *, int);

int main(void)
{
    char str[STR_LEN + 1] = "abcd_1234_啊哦额有";

    capitalize(str, (int)sizeof(str));
    printf("\n\t %s", str);

    getchar();
    return 0;
}

void capitalize(char *str, int len)
{
    int i = 0;
    char ch;

    while (str[i]) {
        ch = toupper(str[i]);
        str[i++] = ch;
    }
}

// void capitalize(char *str, int len)
// {
//     char *p = str, ch;

//     while ((*p)) {
//         ch = toupper((*p));
//         *p++ = ch;
//     }
// }