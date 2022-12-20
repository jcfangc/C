// 编写名为 reverse.c 的程序，用来逆序输出命令行参数。如果键入
// reverse void and null
// 运行程序，产生的输出应为
// null and void

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (strcmp("reverse", argv[1]) == 0) {
        printf("\n\t ");
        for (int i = argc - 1; i > 1; i--) {
            printf("%s ", argv[i]);
        }
    }

    getchar();
    return 0;
}

// 书作者答案：（http://knking.com/books/c2/answers/c13.html）