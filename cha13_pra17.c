// 编写下面的函数：
// bool test_extension(const char *file_name,  const char *extension);
// file_name 指向包含文件名的字符串。如果文件扩展名与 extension 指向的字符串匹配（不区分大小写），函数返回 ture。例如，函数调用 test_extension ("memo.txt", "TXT") 将返回 true。要求在函数中使用 “搜索字符串结尾” 的惯用法。提示：在比较字符之前使用 toupper 函数（→ 23.5节）把字符串转换成大写形式。

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define STR_MAX 60

int read_line(char[], int);
_Bool test_extension(const char *, const char *);

int main(int argc, char *argv[])
{
    char filename[STR_MAX] = { '\0' };

    printf("\n\t Enter file name. \n\t ");
    read_line(filename, STR_MAX);
    // 测试文件名扩展名是不是 “txt”
    if (test_extension(filename, "txt")) {
        printf("\n\t TRUE ");
    }
    else {
        printf("\n\t FALSE ");
    }

    getchar();
    return 0;
}

int read_line(char str[], int len)
{
    char(*p) = str;

    while (((*p) = getchar()) != '\n' && (p < str + len)) {
        p++;
    }

    (*p) = '\0';
    *(str + len - 1) = '\0';
    return (p - str);
}

_Bool test_extension(const char *file_name, const char *extension)
{
    // 找到 '.'，让 file_name 指向 '.' 之后的位置
    while ((*file_name++) != '.') {
        ;
    }

    // 比较文件扩展名
    while (*extension && *file_name) {
        if (toupper(*extension++) == toupper(*file_name++)) {
            continue;
        }
        else {
            return false;
        }
    }

    if ((*extension) == '\0' && (*file_name) == '\0') {
        return true;
    }
    else {
        return false;
    }
}