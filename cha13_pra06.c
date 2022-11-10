// 编写名为 censor 的函数，把字符串中出现的每一处 foo 替换为 xxx。例如，字符串 ”food fool“ 会变为 ”xxxd xxxl“。在不失清晰性的前提下程序越短越好。

#include <stdio.h>

#define STR_LEN 60

void censor(char *, int);

int main(void)
{
    char str[STR_LEN + 1] = "food fool";

    censor(str, (int)sizeof(str));
    printf("\n\t %s", str);

    getchar();
    return 0;
}

void censor(char *str, int len)
{
    const char foo[4] = "foo";

    for (int i = 3; str[i] != '\0'; i++) {
        if (str[i - 3] == 'f' && str[i - 2] == 'o' && str[i - 1] == 'o') {
            str[i - 3] = str[i - 2] = str[i - 1] = 'x';
        }
    }
}

// 书作者答案：http://knking.com/books/c2/answers/c13.html
// void censor(char s[])
// {
//     int i;
//     for (i = 0; s[i] != '\0'; i++)
//         if (s[i] == 'f' && s[i + 1] == 'o' && s[i + 2] == 'o')
//             s[i] = s[i + 1] = s[i + 2] = 'x';
// }