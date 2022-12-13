// 编写下面的函数：
// void remove_filename(char *url);
// url 指向一个包含以文件名结尾的 URL（Uniform Resource Locator, 统一资源定位器）的字符串， 例如 “http://www.knking.com/index.html"。函数应通过移除文件名和前面的斜杠来修改字符串。（在上面的例子中，结果为 “http://www.knking.com”。）要求在函数中使用 ”搜索字符串结尾“ 的惯用法。提示：把字符串中的最后一个斜杠替换为空字符。

#include <stdio.h>
#include <string.h>

#define STR_MAX 120

int read_url(char[], int);
void remove_filename(char *);

int main(int argc, char *argv[])
{
    char url[STR_MAX] = { '\0' };

    printf("\n\t Enter an URL: ");
    read_url(url, STR_MAX);
    remove_filename(url);

    printf("\n\t URL without file name is: %s", url);

    getchar();
    return 0;
}

int read_url(char str[], int len)
{
    char(*p) = str;
    char ch;

    while ((ch = getchar()) != '\n' && (p < str + len)) {
        (*p++) = ch;
    }

    return (p - str);
}

// 答案部分
void remove_filename(char *url)
{
    int length = strlen(url);
    char(*p) = (url + length);

    while ((*p) != '/' && (p > url)) {
        // 从尾部倒过来搜寻第一个‘/’
        p--;
    }

    (*p) = '\0';
}