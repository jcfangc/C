// 编写名为 duplicate 的函数，此函数使用动态存储分配来创建字符串的副本。例如，调用
    // p = duplicate(str);
// 将为和 str 长度相同的字符串分配内存空间，并且把字符串的内容复制到新字符串，然后返回指向新字符串的指针，如果分配内存失败，那么函数 duplicate 返回空指针。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *duplicate(char *);

int main(void)
{
    char str_0[] = "abc";
    char *str_1;

    str_1 = duplicate(str_0);
    if (str_1 != NULL) {
        printf("\n\t %s", str_1);
    }
    else {
        printf("\n\t Null pointer returned. ");
    }
    free(str_1);

    getchar();
    return 0;
}

char *duplicate(char *str)
{
    char *p;
    int len = (int)strlen(str) + 1; // 1 for '\0'

    p = malloc(len * sizeof(char));
    if (p != NULL) {
        strncpy(p, str, len);
    }

    return p;
}


// 书作者答案：http://knking.com/books/c2/answers/c17.html
// char *duplicate(const char *s)
// {
//   char *temp = malloc(strlen(s) + 1);

//   if (temp == NULL)
//     return NULL;

//   strcpy(temp, s);
//   return temp;
// }
